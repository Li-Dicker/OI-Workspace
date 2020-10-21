#include<bits/stdc++.h>
#define int long long
#define N 111111
#define M 11
#define INF 0x3f3f3f3f
using namespace std;

const int MOD=1e9+7;
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

int ksm(int x,int k)
{
    int res=1;
    while (k)
    {
        if (k&1)
            res=res*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return res;
}

void dfs1(int u,int fa,int step)
{
    if (vis[u][step])
        return ;
    vis[u][step]=s1[u][step]=f[u][step]=1;
    if (!step)
        return ;
    for (int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa)
            continue ;
        for (int st=0;st<=k;st++)
            dfs1(v,u,st);
        f[u][step]=f[u][step]*f[v][step-1]%MOD;
        s1[u][step]+=s1[v][step-1];
    }
    f[u][step]=f[u][step]*s1[u][step]%MOD;
}
// void dfs1(int x,int f,int d){if(vis[x][d])return;
// 	vis[x][d]=g[x][d]=s1[x][d]=1;if(!d)return;
// 	for(int i=head[x],to;i;i=edge[i].next){to=edge[i].v;
// 		if(to==f)continue;
// 		for(int j=0;j<=k;j++)dfs1(to,x,j);
// 		g[x][d]=g[x][d]*g[to][d-1]%MOD,s1[x][d]+=s1[to][d-1];
// 	}g[x][d]=g[x][d]*s1[x][d]%MOD;
// }

void dfs2(int u,int fa)
{
    g[u][1]=g[u][0]=s2[u][0]=1,s2[u][1]=2;
    for (int i=2;i<=k;i++)
    {
        s2[u][i]=s2[fa][i-1]-s1[u][i-2]+1;
        g[u][i]=g[fa][i-1]*((s2[u][i]-1)*ksm(f[u][i-2]*s2[fa][i-1]%MOD,MOD-2)%MOD)%MOD;
    }
    for (int step=1;step<=k;step++)
    {
        for (int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].v;
            if (v==fa)
                continue ;
            g[u][step]=g[u][step]*f[v][step-1]%MOD;
            s2[u][step]+=s1[v][step-1];
        }
        g[u][step]=g[u][step]*s2[u][step]%MOD;
    }
    for (int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa)
            continue ;
        dfs2(v,u);
    }
}

signed main()
{
    freopen("c.in","r",stdin);freopen("c1.out","w",stdout);
	n=input(),k=input();
    for (int i=1;i<n;i++)
    {
        tmp1=input(),tmp2=input();
        adde(tmp1,tmp2);
        adde(tmp2,tmp1);
    }
    for (int i=0;i<=k;i++)
        dfs1(1,0,i);
    for (int i=0;i<=k;i++)
        g[1][i]=f[1][i],s2[1][i]=s1[1][i];
    for (int i=head[1];i;i=edge[i].next)
        dfs2(edge[i].v,1);
    for (int i=1;i<=n;i++)
        print(s2[i][k],' ');
    puts("");
    for (int i=1;i<=n;i++)
        print(g[i][k],' ');
    return 0;
}
/*
8 3
1 2
3 1
2 4
7 2
5 2
4 6
5 8
*/