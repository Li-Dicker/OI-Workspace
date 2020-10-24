#include <bits/stdc++.h>
#define int long long
#define N 222222
#define PII 3.141592653589793
using namespace std;

int n, edgenum, tmp1, tmp2, x, y, ans, l, r, mid;
int vis[N], head[N], a[N], father[N];

struct Oops
{
    int v, next;
} edge[N << 1];

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

void adde(int u, int v)
{
    edge[++edgenum].v = v;
    edge[edgenum].next = head[u];
    head[u] = edgenum;
}

void dfs1(int u, int fa)
{
    a[u] = a[fa] + 1;
    father[u] = fa;
    if (a[x] < a[u])
        x = u;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == fa)
            continue;
        dfs1(v, u);
    }
}

void dfs2(int u, int fa, int len, int m)
{
    if (len > m)
        return;
    vis[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == fa)
            continue;
        dfs2(v, u, len + 1, m);
    }
}

void dfs3(int u, int fa)
{
    if (!vis[u] && a[y] < a[u])
        y = u;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == fa)
            continue;
        dfs3(v, u);
    }
}

bool check(int m)
{
    memset(vis, 0, sizeof(vis));
    if (a[x] <= m)
        return 1;
    int j = x;
    for (int i = 1; i <= m; i++)
        j = father[j];
    dfs2(j, 0, 0, m);
    y = 0;
    dfs3(1, 0);
    j = y;
    if (a[y] <= m)
        return 1;
    for (int i = 1; i <= m; i++)
        j = father[j];
    dfs2(j, 0, 0, m);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            return 0;
    return 1;
}

signed main()
{
    n = input();
    for (int i = 1; i < n; i++)
    {
        tmp1 = input(), tmp2 = input();
        adde(tmp1, tmp2);
        adde(tmp2, tmp1);
    }
    a[0] = 0;
    dfs1(1, 0);
    l = 0, r = n, mid = (l + r) >> 1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    print(ans, '\n');
    return 0;
}
