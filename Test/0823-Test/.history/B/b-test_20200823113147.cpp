#include <bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i, j, k, n, s, t, m;
inline int read()
{
    int num = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
    {
        num = num * 10 + ch - 48;
        ch = getchar();
    }
    return num;
}
const int N = 1e5 + 10;
bitset<1010> bst[1010];
int head[N];
struct fu
{
    int v, next;
} a[N << 2];
int fa[N], pd[N];
void dfs(int u)
{
    for (int ii = head[u]; ii; ii = a[ii].next)
    {
        int v = a[ii].v;
        if (v == fa[u])
            continue;
        fa[v] = u;
        bst[v] |= bst[u];
        dfs(v);
    }
}
void work(int aa, int bb)
{
    a[++k].next = head[aa];
    head[aa] = k;
    a[k].v = bb;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    //freopen(".ans","w",sdtout);
    scanf("%d%d", &n, &m);
    int x, y;
    for (i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        work(x, y);
        work(y, x);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        bst[x].set(i, 1);
        bst[y].set(i, 1);
    }
    dfs(1);
    for (i = 1; i <= n; i++)
    {
        int ans = 0;
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if ((bst[i] & bst[j]).count() != 0)
                ans++;
        }
        printf("%d ", ans);
    }
    return 0;
}