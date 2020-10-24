#include <bits/stdc++.h>
#include "swap.h"

using namespace std;

const int MAX_N = 3e5 + 10;

int K, conn_time[MAX_N], pa[MAX_N], siz[MAX_N], dfn[MAX_N], dfni[MAX_N], dfn_tick, top[MAX_N], depth[MAX_N];
pair<int, int> endpoints[MAX_N];
vector<int> child[MAX_N];

struct DSU {
    int pa[MAX_N];

    void init(int _n) {
        K = _n;
        for (int i = 0; i < K; i++) pa[i] = i;
    }

    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

    int merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            pa[a] = pa[b] = pa[K] = K;
            return K++;
        } else {
            return -1;
        }
    }

    void next_step(int x) {
        pa[x] = pa[K] = K;
        K++;
    }
} dsu;

void hld_dfs1(int x) {
    siz[x] = 1;
    for (int i : child[x]) {
        depth[i] = depth[x] + 1;
        hld_dfs1(i);
        siz[x] += siz[i];
    }
    sort(child[x].begin(), child[x].end(), [](int a, int b) { return siz[a] > siz[b]; });
}

void hld_dfs2(int x, int y) {
    dfni[dfn[x] = dfn_tick++] = x; top[x] = y;
    for (int i : child[x]) {
        hld_dfs2(i, i == child[x][0] ? y : i);
    }
}

int lca(int a, int b) {
    while (top[a] != top[b]) {
        if (depth[top[a]] > depth[top[b]])
            a = pa[top[a]];
        else
            b = pa[top[b]];
    }
    return depth[a] < depth[b] ? a : b;
}

void init(int N, int M,
        std::vector<int> U, std::vector<int> V, std::vector<int> W) {
    dsu.init(N);
    for (int i = 0; i < N; i++) {
        endpoints[i] = make_pair(i, i);
    }
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < M; i++) {
        edges.emplace_back(W[i], U[i], V[i]);
    }
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        int u, v, w, x; tie(w, u, v) = e;
        int eu = u, ev = v;
        u = dsu.find(u); v = dsu.find(v);
        x = dsu.merge(u, v);
        if (~x) {
            conn_time[x] = w;
            pa[u] = pa[v] = x;
            if ((eu == endpoints[u].first || eu == endpoints[u].second) && (ev == endpoints[v].first || ev == endpoints[v].second)) {
                endpoints[x] = make_pair(endpoints[u].first + endpoints[u].second - eu, endpoints[v].first + endpoints[v].second - ev);
            } else {
                endpoints[x] = make_pair(-1, -1);
            }
        } else {
            x = dsu.find(u);
            dsu.next_step(x);
            pa[x] = K - 1;
            endpoints[K - 1] = make_pair(-1, -1);
            conn_time[K - 1] = w;
        }
    }
    for (int i = 0; i < K; i++) {
        if (dsu.pa[i] == i) {
            pa[i] = K;
        }
    }
    pa[K] = -1;
    conn_time[K] = -1;
    endpoints[K] = make_pair(-1, -1);
    for (int i = 0; i < K; i++) {
        child[pa[i]].push_back(i);
    }
    hld_dfs1(K);
    hld_dfs2(K, K);
}

int getMinimumFuelCapacity(int X, int Y) {
    int x = lca(X, Y);
    while (endpoints[x].first != -1) {
        if (endpoints[top[x]].first != -1) x = pa[top[x]];
        else {
            int l = dfn[top[x]], r = dfn[x];
            while (l != r) {
                int m = (l + r + 1) / 2;
                if (endpoints[dfni[m]].first != -1) {
                    r = m - 1;
                } else {
                    l = m;
                }
            }
            x = dfni[l];
        }
    }
    return conn_time[x];
}
