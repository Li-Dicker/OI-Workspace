#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int n,m,cnt,ans;
int dp[2222][2222][5];
signed main()
{
	scanf("%lld %lld",&n,&m);
	dp[1][1][0]=dp[1][2][1]=dp[1][2][2]=dp[1][1][3]=1;
	for (int i=2;i<=n;i++)
		for(int j=1;j<=(i<<1);j++)
		{
			cnt=0;
			cnt+=dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3];
			dp[i][j][0]=cnt%MOD;
			cnt=0;
			if (j>=2)
				cnt+=dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-2][2]+dp[i-1][j-1][3];
			else
				cnt=cnt+dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-1][3];
			dp[i][j][1]=cnt%MOD;
			cnt=0;
			if (j>=2)
				cnt=cnt+dp[i-1][j-2][1]+dp[i-1][j-1][0]+dp[i-1][j][2]+dp[i-1][j-1][3];
			else
				cnt=cnt+dp[i-1][j-1][0]+dp[i-1][j][2]+dp[i-1][j-1][3];
			dp[i][j][2]=cnt%MOD;
			cnt=0;
			cnt=cnt+dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3];
			dp[i][j][3]=cnt%MOD;
		}
	ans=0;
	for (int i=0;i<4;i++)
		ans+=dp[n][m][i],ans%=MOD;
	printf("%lld\n",ans);
	return 0;
}