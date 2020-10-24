#include <bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n, m, edgenum = 0, ans = 0, tmp1, tmp2;
int fa[N], head[N];
struct Edge
{
    int v, next;
} edge[N << 2];
bitset<1111> vis[1111];

namespace IOstream
{
    #define int long long
    #define print(edge, b) prints(edge), putchar(b)
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

void dfs(int u)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == fa[u])
            continue;
        fa[v] = u;
        vis[v] |= vis[u];
        dfs(v);
    }
}

void adde(int u, int v)
{
    edge[++edgenum].next = head[u];
    head[u] = edgenum;
    edge[edgenum].v = v;
}

signed main()
{
    freopen("b.in","r",stdin);freopen("b.out","w",stdout);
    n = input(), m = input();
    for (int i = 1; i <= n - 1; i++)
    {
        tmp1 = input(), tmp2 = input();
        adde(tmp1, tmp2);
        adde(tmp2, tmp1);
    }
    for (int i = 1; i <= m; i++)
    {
        vis[tmp1 = input()].set(i, 1);
        vis[tmp2 = input()].set(i, 1);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if ((vis[i] & vis[j]).count() != 0)
                ans++;
        }
        print(ans, ' ');
    }
    return 0;
}
/*

5 1
1 2
1 3
3 5
3 4
2 3


11 3
1 2
2 3
2 4
1 5
5 6
5 7
5 8
6 9
8 10
8 11
2 9
3 6
2 8


*/