#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#define int long long
#define N 15
#define mod 100000000
using namespace std;
int n,m,tmp1,cnt=0,ans=0;//cnt：每一行可能有的方案数
int mp[N],st[1<<N],dp[N][1<<N];//mp[i]:第i行的情况,st[i]:第i行可能有的方案数
signed main()
{
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			scanf("%lld",&tmp1);
			if (tmp1==0)
				mp[i]=mp[i]|(1<<(j-1));
		}//将每一行的状态处理成一个二进制串
	for (int i=0;i<(1<<m);i++)//枚举一行可能有的状态（不考虑地形的影响）
		if (!(i&(i<<1)))//判断有没相邻两个重合的情况
			st[++cnt]=i;//最新的方案就是i
	for (int i=1;i<=cnt;i++)//暴力枚举第一行
		if (!(st[i]&mp[1]))//地形和方案匹配
			dp[1][i]++;//第一行状态为i方案数为1
	for (int i=2;i<=n;i++)//列举行数
		for (int j=1;j<=cnt;j++)//列举当前行的状态
			if (!(mp[i]&st[j]))//判断当前行和当前状态是否匹配
				for (int r=1;r<=cnt;r++)//枚举上一行的状态
					if (!(mp[i-1]&st[r]))//上一行的地形和状态是否匹配
						if (!(st[j]&st[r]))//上下行的状态合法
							dp[i][j]+=dp[i-1][r];
	for (int i=1;i<=cnt;i++)
		ans+=dp[n][i],ans%=mod;
	printf("%lld\n",ans);
	return 0;
}