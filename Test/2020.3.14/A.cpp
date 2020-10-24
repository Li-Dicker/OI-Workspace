#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s,r,t,ans;
signed main()
{
	scanf("%lld",&n);
	ans=n-1;
	for (int i=1;i<=n;i)
	{
		t=n/(n/i);
		ans+=(n/i)*(t-i+1);
		i=t+1;
	}
	ans-=(2*(n-1)+1);
	s=0;
	while (s*s<=n)
		s++;
	for (int i=2;i<=s;i++)
		if (i*(i+1)<=n)
			ans+=i;
		else
		{
			r=i*i;
			while (r<=n&&r<=i*(i+1))
				ans++,r++;
		}
	printf("%lld\n",ans);
	return 0;
}
/*
3
2

10
21

21
58

1000
6564

*/