#include <bits/stdc++.h>
#define int long long
#define MK 1<<16
#define N 20
const int INF = 1e18;
using namespace std;
int n,k;
int dp[N][MK];
int x[N],y[N],num[N];
 
signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&x[i],&y[i],&num[i]);
	}
	for(int i=1;i<=k;i++)
    {
    	for(int j=0;j<(1<<n);j++)
        {
        	dp[i][j] = INF;
        }
    }
    dp[0][0]=0;
	for(int i=0;i<(1<<n);i++)
	{
		int maxx = 0;
		int maxy = 0;
		int cnt = 0;
		int sum = 0;
		int u = i;
		int id = 0;
		while(u)
		{
			if(u&1)
			{
				maxx = max(maxx,x[id]);
				maxy = max(maxy,y[id]);
				sum += x[id]*y[id]*num[id];
				cnt += num[id];
			}
			id++;
			u>>=1;
		}
		dp[1][i] = maxx*maxy*cnt-sum;
	}
	for(int i=2;i<=k;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			for(int x=j;x;x=(x-1)&j)
			{
				for(int k=1;k<i;k++)
				{
					dp[i][j] = min(dp[i][j],dp[i-k][x]+dp[k][j^x]);
				}
			}
		}
	}
	printf("%lld\n",dp[k][(1<<n)-1]);
	return 0;
}