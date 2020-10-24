#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#define N 22
using namespace std;
int n,tmp1,cnt=0,ans=0;//cnt：每一行可能有的方案数
int mp[N][N],st[20000],dp[N][22222],num[N][22222];//mp[i]:第i行的情况,st[i]:第i行可能有的方案数
signed main()
{
	while (scanf("%d",&n)!=EOF)
	{
		cnt=0,ans=0;
		memset(mp,0,sizeof(0));
		memset(st,0,sizeof(st));
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		for (int i=0;i<(1<<n);i++)//枚举一行可能有的状态和每个方案的和
			if (!(i&(i<<1)))//判断有没相邻两个重合的情况
				st[++cnt]=i;//最新的方案就是i
		for (int i=1;i<=n;i++)//列举行数
			for (int j=1;j<=cnt;j++)//列举第几种方案
			{
				tmp1=1;
				for (int k=0;k<n;k++)//列举列数
				{
					if (tmp1&st[j])
						num[i][j]+=mp[i][k+1];
					tmp1<<=1;
				}
			}
		for (int i=1;i<=cnt;i++)
			dp[1][i]=num[1][i];//暴力枚举第一行
		for (int i=2;i<=n;i++)
			for (int j=1;j<=cnt;j++)
				for (int k=1;k<=cnt;k++)
					if (!(st[j]&st[k]))
						dp[i][j]=max(dp[i][j],dp[i-1][k]+num[i][j]);
		for (int i=1;i<=cnt;i++)
			ans=max(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	
	return 0;
}
