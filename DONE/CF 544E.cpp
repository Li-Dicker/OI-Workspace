#include<bits/stdc++.h>
#define int long long
#define N 22
#define INF 0x3f3f3f3f3f3f3f3f3f
using namespace std;
int n,m,usee,maxn;
int a[N][n],bit[N][N],cost[N][N];
char s[N][N];
signed main()
{
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%c",s[i][j]);//输入字符矩阵
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%lld",&a[i][j]);//输入修改的代价
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)//遍历每一个点
			for (int k=1;k<=n;k++)//遍历这个点这一列的每一个点
			{
				usee=0,maxn=-INF;//usee：花费，maxn：最贵的
				if (s[i][j]==s[k][j])//是否重复字符
				{
					usee+=a[i][j];//与这个字符相同的字符价格累加
					maxn=max(maxn,a[i][j]);//找到其中价格最贵的一个
					bit[i][j]|=1<<k;//找到与这个字符相同的字符，并二进制存储
				}
				usee-=maxn;//减去其中最贵的
				cost[i][j]=usee;//记录下花费
			}
	for (int i=1;i<(1<<n);i++)
		for (int j=1;j<=n;j++)
			if (i&(1<<j)==0)
				for (int k=1;k<=m;k++)
				{
					dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+a[i][k]);
					dp[i|bit[j][k]]=min(dp[i|bit[j][k]],dp[i]+cost[j][k]);
				}
	for (int i=1;)
	return 0;
}