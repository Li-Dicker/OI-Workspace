#include<bits/stdc++.h>
// #define int long long
#define N 3001
#define INF 0x3f3f3f3f
using namespace std;

int n,k,edgenum=0,ans=INF;
int tmp1,tmp2,tmp3;
int head[N],size[N];
int dp[N][N][3];

struct Edge
{
    int v,w,next;
}edge[N<<1];

namespace IOstream
{
    // #define int long long
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

void adde(int u,int v,int w)
{
    edge[++edgenum].next=head[u];
    head[u]=edgenum;
    edge[edgenum].v=v;
    edge[edgenum].w=w;
}

int min(long long a,long long b)
{
    return a<b?a:b;
}

void dfs(int u,int fa)
{
    dp[u][1][0]=dp[u][1][1]=0,size[u]=1;
    for (int I=head[u];I;I=edge[I].next)
    {
        int v=edge[I].v;
        if (v==fa)
            continue ;
        dfs(v,u);
        for (int i=min(k,size[u]);i>=0;i--)
            for (int j=min(size[v],k-i);j>=0;j--)
            {
                dp[u][i+j][0]=min(dp[u][i+j][0],(long long)dp[u][i][0]+dp[v][j][0]+edge[I].w*2);
                dp[u][i+j][1]=min(dp[u][i+j][1],min((long long)dp[u][i][0]+dp[v][j][1]+edge[I].w,(long long)dp[u][i][1]+dp[v][j][0]+edge[I].w*2));
                dp[u][i+j][2]=min(dp[u][i+j][2],min((long long)dp[u][i][1]+dp[v][j][1]+edge[I].w,min((long long)dp[u][i][0]+dp[v][j][2]+edge[I].w*2,(long long)dp[u][i][2]+dp[v][j][0]+edge[I].w*2)));
            }
        size[u]+=size[v];
    }
    ans=min(ans,dp[u][k][2]);
}

signed main()
{
    n=input(),k=input();
    for (int i=1;i<n;i++)
    {
        tmp1=input(),tmp2=input(),tmp3=input();
        adde(tmp1,tmp2,tmp3);
        adde(tmp2,tmp1,tmp3);
    }
    memset(dp,INF,sizeof(dp));
    if (k==1)
        ans=0;
    else
        dfs(1,0);
    print(ans,'\n');
    return 0;
}
