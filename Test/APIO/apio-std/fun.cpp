#include <bits/stdc++.h>
#include "fun.h"

using namespace std;

const int MAX_N = 1e5 + 10;

int N, Q, K;
int center, dist[MAX_N], group[MAX_N];
vector<int> neighbour, subtree[3];

void findcenter() {
    for (int i = 1; i < N; i++) {
        if (attractionsBehind(center, i) * 2 >= N)
            center = i;
    }
}

void finddist() {
    for (int i = 0; i < N; i++) {
        if (i != center) {
            dist[i] = hoursRequired(center, i);
            if (dist[i] == 1) {
                neighbour.push_back(i);
            }
        }
    }
    K = neighbour.size();
}

void findgroup() {
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < K; j++) {
            if (hoursRequired(i, neighbour[j]) == dist[i] - 1)
                group[i] = j;
        }
    }
    for (int i = 0; i < N; i++) {
        if (i == center) continue;
        subtree[group[i]].push_back(i);
    }
    for (int i = 0; i < K; i++) {
        sort(subtree[i].begin(), subtree[i].end(), [](int a, int b) { return dist[a] < dist[b]; });
    }
}

vector<int> limitedFindFunTour(vector<int> tour, int heavy) {
    vector<int> L, R;
    for (int i = 0; i < K; i++) {
        if (i == heavy)
            R.insert(R.end(), subtree[i].begin(), subtree[i].end());
        else
            L.insert(L.end(), subtree[i].begin(), subtree[i].end());
    }
    sort(L.begin(), L.end(), [](int a, int b) { return dist[a] < dist[b]; });
    sort(R.begin(), R.end(), [](int a, int b) { return dist[a] < dist[b]; });
    bool center_included = false;
    if (R.size() > L.size() + 1) {
        center_included = true;
        L.insert(L.begin(), center);
    }
    while (!R.empty()) {
        swap(L, R);
        tour.push_back(L.back());
        L.pop_back();
    }
    if (!center_included) {
        tour.push_back(center);
    }
    return tour;
}

vector<int> findFunTour() {
    vector<int> tour;
    int sel = 0;
    for (int i = 1; i < K; i++)
        if (dist[subtree[i].back()] > dist[subtree[sel].back()])
            sel = i;
    for (int i = 1; i < N; i++) {
        tour.push_back(subtree[sel].back());
        subtree[sel].pop_back();
        for (int j = 0; j < K; j++) {
            if (j == sel) continue;
            if (subtree[j].size() * 2 < N - i - 1)
                continue;
            bool deny = false;
            for (int k = 0; k < K; k++) {
                if (k == j || k == sel) continue;
                if (dist[subtree[k].back()] > dist[tour.back()])
                    deny = true;
            }
            if (deny)
                continue;
            return limitedFindFunTour(tour, j);
        }
        int nsel = (sel + 1) % K;
        for (int j = 0; j < K; j++)
            if (j != sel && dist[subtree[j].back()] > dist[subtree[nsel].back()])
                nsel = j;
        sel = nsel;
    }
    tour.push_back(center);
    return tour;
}

vector<int> createFunTour(int _N, int _Q) {
    N = _N; Q = _Q;
    findcenter();
    finddist();
    findgroup();
    return findFunTour();
}
