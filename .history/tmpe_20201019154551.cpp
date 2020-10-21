#include<bits/stdc++.h>
#define int long long
#define N 111111
#define M 11
#define MOD 100000007
#define INF 0x3f3f3f3f
using namespace std;

int n,k,edgenum=0;
int tmp1,tmp2;
int head[N];
int f[N][M],s1[N][M],g[N][M],s2[N][M],vis[N][M];
struct Edge
{
    int v,next;
}edge[N<<1];


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

void adde(int u,int v)
{
    edge[++edgenum].next=head[u];
    head[u]=edgenum;
    edge[edgenum].v=v;
}

void dfs1(int u,int fa,int step)
{
    if (vis[u][step]||!step)
        return ;
    vis[u][step]=s1[u][step]=f[u][step]=1;
    for (int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa)
            continue ;
        for (int st=1;st<=k;st++)
            dfs1(v,u,st);
        s1[u][step]+=s1[v][step-1];
    }
}

signed main()
{
	n=input(),k=input();
    for (int i=1;i<n;i++)
    {
        tmp1=input(),tmp2=input();
        adde(tmp1,tmp2);
        adde(tmp2,tmp1);
    }
    dfs1(1,0,k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=k;j++)
            print(s1[i][j],'\n');

    return 0;
}