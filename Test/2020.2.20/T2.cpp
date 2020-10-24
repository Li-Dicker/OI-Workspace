#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define int long long
#define N 11111
using namespace std;
int n,t,size,maxn,ans;
int a[N],dp[N];
map<int,int>tong;
signed main()
{
	scanf("%lld%lld",&n,&t);
	size=n*min(n,t),maxn=1,ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		tong[a[i]]++;
	}
	for (int i=n+1;i<=size;i++)
		a[i]=a[i-n];
	for (int i=1;i<=size;i++)
	{
		dp[i]=1;
		for (int j=i-1;j>=max(i-n,1);j--)
			if (a[i]>=a[j])
				dp[i]=max(dp[i],dp[j]+1);
		maxn=max(maxn,dp[i]);
	}
	if (n>=t)
		printf("%lld\n",maxn);
	else
	{
		for (int i=-1;i<=333;i++)
			ans=max(ans,tong[i]);
		ans=maxn+ans*(t-n);
		printf("%lld\n",ans);
	}
	return 0;
}