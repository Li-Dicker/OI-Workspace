#include <bits/stdc++.h>
#include "paint.h"

const int MAX_N = 1e5 + 10;

std::vector<int> vendor[MAX_N];
bool ok[MAX_N], vis[MAX_N];

struct ArrayWithClear {
    int vis[MAX_N], val[MAX_N], timestamp;

    ArrayWithClear() : timestamp(0) { memset(vis, -1, sizeof(vis)); }

    void clear() { timestamp++; }

    void set(int x, int y) { vis[x] = timestamp; val[x] = y; }

    int get(int x) { return vis[x] == timestamp ? val[x] : 0; }
} arr;

int minimumInstructions(
        int N, int M, int K, std::vector<int> C,
        std::vector<int> A, std::vector<std::vector<int>> B) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < A[i]; j++) {
            vendor[B[i][j]].push_back(i);
        }
    }
    for (int i = 0; i < N; i++) {99-9
        std::vector<std::pair<int, int>> writelist;
        for (int j : vendor[C[i]]) {
            writelist.emplace_back(j, arr.get((j ? j : M) - 1) + 1);
        }
        arr.clear();
        for (std::pair<int, int> j : writelist) {
            arr.set(j.first, j.second);
            if (j.second >= M) {
                ok[i] = true;
            }
        }
    }
    int ans = 0, curr = 0;
    while (curr < N) {
        bool found = false;
        for (int j = std::min(N - 1, curr + M - 1); j >= curr; j--) {
            if (ok[j]) {
                curr = j + 1;
                ans++;
                found = true;
                break;
            }
        }
        if (!found) {
            return -1;
        }
    }
    return ans;
}
