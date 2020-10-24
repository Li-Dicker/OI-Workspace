#include <bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n,m,edgenum=0,tmp1,tmp2;
int fa[N],head[N];
struct fu
{
    int v, next;
} edge[N << 2];
bitset<1111> vis[1111];

namespace IOstream
{
    #define int long long
    #define print(edge,b) prints(edge),putchar(b)
    int BUF[22],BUFSIZE,IONUM,SIGN;
    char GET;

    inline int input()
    {
        IONUM=0,SIGN=1;
        GET=getchar();
        while (GET<'0'||GET>'9')
        {
            if (GET=='-')
                SIGN=-1;
            GET=getchar();
        }
        while (GET>='0'&&GET<='9')
        {
            IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
            GET=getchar();
        }
        return SIGN*IONUM;
    }

    inline void prints(int IONUM)
    {
        if (IONUM<0)
            IONUM=-IONUM,putchar('-');
        do
            BUF[++BUFSIZE]=IONUM%10,IONUM/=10;
        while (IONUM);
        while (BUFSIZE)
            putchar(BUF[BUFSIZE--]+'0');
    }

}
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
    n=input(),m=input();
    for (i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        adde(tmp1, tmp2);
        adde(tmp2, tmp1);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        vis[tmp1].set(i, 1);
        vis[tmp2].set(i, 1);
    }
    dfs(1);
    for (i = 1; i <= n; i++)
    {
        int ans = 0;
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if ((vis[i] & vis[j]).count() != 0)
                ans++;
        }
        printf("%d ", ans);
    }
    return 0;
}