#include<bits/stdc++.h>
#define int long long
#define N 23
using namespace std;
int n;
int a[1000005],dp[1<<N];
signed main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		dp[a[i]^((1<<N)-1)]=a[i];//每个数都取反
	}
	for (int i=(1<<N)-1;i>=0;i--)//逆序遍历区间内每一个数
		if (!dp[i])//这个数是否需要
			for (int j=0;j<N;j++)
				if (dp[i|(1<<j)])//找是否有这个数或者其他满足要求的数
					dp[i]=dp[i|(1<<j)];//换掉可以换的位
	for (int i=1;i<=n;i++)//输出答案
		if (dp[a[i]])
			printf("%lld ",dp[a[i]]);
		else
			printf("-1 ");
	return 0;
}