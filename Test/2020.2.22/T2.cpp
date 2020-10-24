#include<bits/stdc++.h>
#define int long long
#define N 18
using namespace std;
int n,m,k,tmp1,tmp2,tmp3,s,cnt,ans;
int val[N];
int add[N][N],dp[(1<<N)+N][N];
void init()
{
    memset(dp,0,sizeof(dp));
    memset(add,0,sizeof(add));
}
signed main()
{
    while (scanf("%lld%lld%lld",&n,&m,&k)!=EOF)
    {
    	init();
        for (int i=0;i<n;i++)
            scanf("%lld",&val[i]);
        for (int i=0;i<k;i++)
        {
            scanf("%lld%lld%lld",&tmp1,&tmp2,&tmp3);
            add[tmp1-1][tmp2-1]=tmp3;
        }
        for (int i=0;i<n;i++)
            dp[1<<i][i]=val[i];
        s=1<<n,ans=0;
        for (int i=0;i<s;i++)
        {
            cnt=0;
            for (int j=0;j<n;j++)
                if (i&(1<<j))
                {
                    cnt++;
                    for (int k=0;k<n;k++)
                        if ((i&(1<<k))==0)
                            dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+val[k]+add[j][k]);
                }
            if (cnt==m)
                for (int j=0;j<n;j++)
                    if (i&(1<<j))
                        ans=max(ans,dp[i][j]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
dp[i][j]表示当前吃菜的状态为i,当前吃的最后一道菜为j,所获得的最大的值，
三层循环,第一层循环枚举状态,第二层枚举当前吃的最后一道菜,第三层循环表示下一次吃的菜
dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+val[k]+add[j][k]);
val表示价值，add表示这两道菜连在一起的价值
*/