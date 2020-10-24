#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,tmp,TEST;
int Rand(int k)
{
	int res=0;
	for (int i=1;i<=k;i++)
		res*=10,res+=rand()%10;
	return res;
}
signed main()
{
	srand(time(NULL));
	cin>>TEST;
	T=Rand(2)%30+1;
	while (T--)
	{
		n=Rand(5)%TEST+1;
		printf("%lld\n",n);
		for (int i=1;i<=n;i++)
			printf("%lld",Rand(2)%10);
		cout<<endl;
	}
	return 0;
}
