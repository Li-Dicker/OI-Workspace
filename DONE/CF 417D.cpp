#include<bits/stdc++.h>
#define INF 0x7f7f7f7f7f7f7f7f7f
#define N 20
using namespace std;
int n,m,b,x,tmp1,cnt;
long long ans;
long long dp[1<<N];
struct Oops
{
    int x,k,num;
}a[111];
int cmp(Oops a,Oops b)
{
    return a.k<b.k;
}
void init()
{
    sort(a,a+n,cmp);
    memset(dp,-1,sizeof(dp));
    cnt=(1<<m)-1,ans=INF,dp[0]=0;
}
int min(int a,int b)
{
	if (a<b)
		return a;
	return b;
}
signed main()
{
    scanf("%d%d%d",&n,&m,&b);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].k,&tmp1);
        while (tmp1--)
        {
            scanf("%d",&x);
            a[i].num|=1<<(x-1);
        }
    }
    init();
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=cnt;j++)
        {
            if (dp[j]==-1)
                continue ;
            tmp1=j|a[i].num;
            if (dp[tmp1]==-1)
                dp[tmp1]=dp[j]+a[i].x;
            else
                dp[tmp1]=min(dp[tmp1],dp[j]+a[i].x);
        }
        if (dp[cnt]!=-1)
            ans=min(ans,dp[cnt]+1LL*a[i].k*b);
    }
    if (ans==INF)
        ans=-1;
    printf("%I64d\n",ans);
	return 0;
}