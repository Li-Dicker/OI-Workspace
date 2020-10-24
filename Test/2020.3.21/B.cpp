#include<bits/stdc++.h>
#define int long long
#define N 111111
using namespace std;
int n,m,cnt=0,u,v;
int head[N],val[N];
int dp[N][2];
struct lyp
{
    int u,v,next;
}edge[3*N];
void adde(int u,int v)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u,int fa)
{
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa)
            continue ;
        dfs(v,u);
        dp[u][0]=max(dp[u][0],dp[v][0]),dp[u][1]=max(dp[u][1],dp[v][1]);
    }
    val[u]+=(dp[u][0]-dp[u][1]);
    if (val[u]>=0)
        dp[u][1]+=val[u];
    else
        dp[u][0]-=val[u];
}
signed main()
{
    scanf("%lld",&n);
    memset(head,-1,sizeof(head));
    for (int i=1;i<n;i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    for (int i=1;i<=n;i++)
        scanf("%lld",&val[i]);
    dfs(1,1);
    printf("%lld",dp[1][0]+dp[1][1]);
    return 0;
}