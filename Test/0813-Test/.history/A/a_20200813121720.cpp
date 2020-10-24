#include <bits/stdc++.h>
#define int long long
#define N 1111
using namespace std;

int n, m, u, v;
bitset<N> vis, vis, edge[N];

namespace IOstream
{
    #define int long long
    #define print(a,b) prints(a),putchar(b)
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

void search(int x, int s)
{
    if (edge[x].count() <= 1)
    {
        return;
    }
    if (x == s && vis.count())
    {
        if (vis.count() & 1)
            vis |= vis;
        return;
    }
    vis.set(x);
    for (int i = 1; i <= n; i++)
    {
        if (edge[x][i] == 1 && (i == s || !vis[i]))
            search(i, s);
    }
    vis.reset(x);
}

int main()
{
    freopen("a.in", "r", stdin);freopen("a.out", "w", stdout);
    n=input(),m=input();
    vis.reset();
    for (int i=0;i<=1111;i++)
        edge[i].reset();
    for (int i = 1; i <= n; i++)
        edge[i].set(), edge[i][i] = 0;
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &u, &v), edge[u][v] = edge[v][u] = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            vis.reset();
            search(i, i);
        }
    printf("%d\n", n - vis.count());
    return 0;
}
