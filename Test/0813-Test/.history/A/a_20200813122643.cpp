#include <bits/stdc++.h>
#define int long long
#define N 1111
using namespace std;

int n, m, tmp1, tmp2;
bitset<N> VIS;
bitset<N> vis;
bitset<N> edge[N];

namespace IOstream
{
#define int long long
#define print(a, b) prints(a), putchar(b)
    int BUF[22], BUFSIZE, IONUM, SIGN;
    char GET;

    inline int input()
    {
        IONUM = 0, SIGN = 1;
        GET = getchar();
        while (GET < '0' || GET > '9')
        {
            if (GET == '-')
                SIGN = -1;
            GET = getchar();
        }
        while (GET >= '0' && GET <= '9')
        {
            IONUM = (IONUM << 3) + (IONUM << 1) + (GET & 15);
            GET = getchar();
        }
        return SIGN * IONUM;
    }

    inline void prints(int IONUM)
    {
        if (IONUM < 0)
            IONUM = -IONUM, putchar('-');
        do
            BUF[++BUFSIZE] = IONUM % 10, IONUM /= 10;
        while (IONUM);
        while (BUFSIZE)
            putchar(BUF[BUFSIZE--] + '0');
    }

} // namespace IOstream
using namespace IOstream;

void init()
{
    VIS.reset();
    for (int i = 1; i <= n; i++)
        edge[i].set(), edge[i][i] = 0;
}

void dfs(int u, int s)
{
    if (edge[u].count() <= 1)
        return;
    if (u == s && vis.count())
    {
        if (vis.count() & 1)
            VIS |= vis;
        return;
    }
    vis.set(u);
    for (int i = 1; i <= n; i++)
        if (edge[u][i] == 1 && (i == s || !vis[i]))
            dfs(i, s);
    vis.reset(u);
}

signed main()
{
    freopen("a.in", "r", stdin);freopen("a.out", "w", stdout);
    n = input(), m = input();
    init();
    for (int i = 1; i <= m; i++)
    {
        tmp1 = input(), tmp2 = input();
        edge[tmp1][tmp2] = edge[tmp2][tmp1] = 0;
    }
    for (int i = 1; i <= n; i++)
        if (!VIS[i])
        {
            vis.reset();
            dfs(i, i);
        }
    print(n - VIS.count(), '\n');
    return 0;
}
