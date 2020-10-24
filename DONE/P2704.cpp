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
#define N 16
using namespace std;
int n,m;
int mp[N],dp[],st[1<<N];
string tmp1;
signed main()
{
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		cin>>tmp1;
		for (int j=1;j<=m;j++)
		{
			if (tmp1[j-1]=='H')
				mp[i]=mp[i]|(1<<(j-1));
		}
	}//预处理地图为01串
	for (int i=0;i<(1<<m);i++)
		if (!i&(i<<1))
			st[++cnt]=i;//预处理可能有的方案数
	for (int i=1;i<=cnt;i++)
		if ()
	return 0;
}
