#include<bits/stdc++.h>
#define int long long
#define N 17
using namespace std;
int T,n,tmp1,tmp2;
int p[N],dp[1<<N],cover[1<<N];
signed main()
{
	while (scanf("%lld",&n)!=EOF)
	{
		T++;
		if (n==0)
			return 0;
		for (int i=0;i<n;i++)
		{
			scanf("%lld",&tmp1);
			p[i]=(1<<i);
			for (int j=1;j<=tmp1;j++)
			{
				scanf("%lld",&tmp2);
				p[i]|=(1<<tmp2);
			}
		}
		for (int i=0;i<(1<<n);i++)
		{
			cover[i]=0;
			for (int j=0;j<n;j++)
				if (i&(1<<j))
					cover[i]|=p[j];
		}
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=(1<<n)-1;i++)
		{
			if (cover[i]==(1<<n)-1)
				dp[i]=1;
			else
				dp[i]=0;
			for (int j=i;j;j=(j-1)&i)
				dp[i]=max(dp[i],dp[i^j]+dp[j]);
		}
		printf("Case %lld: %lld\n",T,dp[(1<<n)-1]);
	}
	return 0;
}
