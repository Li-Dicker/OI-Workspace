#include<bits/stdc++.h>
#define int long long
#define N 18
using namespace std;
int n,T,len,cnt;
int st[1<<N],k[1<<N],dp[1<<N];
char s[N];
void init()
{
	memset(st,0,sizeof(st));
	memset(k,0,sizeof(k));
	memset(dp,0,sizeof(dp));
	dp[0]=1;
}
signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		init();
		scanf("%lld",&n);
		for(int i=0;i<=n;i++)
		{
			cin>>s;
			len=strlen(s);
			for (int j=0;j<len;j++)
				if (s[j]=='1')
					st[i]|=(1<<j);
		}
		k[0]=st[0];
		cnt=(1<<n)-1;
		for (int i=1;i<=cnt;i++)
		{
			k[i]=st[0];
			for (int j=0;j<n;j++)
				if ((i>>j)&1)
					k[i]|=st[j+1];
		}
		for (int i=1;i<=cnt;i++)
		{
			dp[i]=0;
			for (int j=0;j<n;j++)
				if ((k[i^(1<<j)]>>j)&1)
					dp[i]+=dp[i^(1<<j)];
		}
		printf("%lld\n",dp[cnt]);
	}
	return 0;
}