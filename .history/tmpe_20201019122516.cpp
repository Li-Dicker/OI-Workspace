#include<bits/stdc++.h>
#define int long long 
#define N 111111
#define INF 0x3f3f3f3f3f3f
using namespace std;

int T,n,m,v,res=1,ans=0,len=0,last;
int a[N]={1};

namespace IOstream
{
	int input()
	{
		int IN;
		scanf("%lld",&IN);
		return IN;
	}
	
	void print(int OUT,char OUTEND)
	{
		printf("%lld",OUT);
		putchar(OUTEND);
	}
}
using namespace IOstream;

int max(int a,int b)
{
	return a>b?a:b;
}

void work()
{
	if (n==0)
		return ;
	res=1,last=1,len=0;
	for (int i=1;i<=n;i++)
	{
		res*=a[i];
		len++;
		if (res>=v)
		{
			ans+=n-(last+len-1);
			while (res>=v)
			{
				res/=a[last];
				last++,len--;
				ans+=n-(last+len-1);
			}
		}
	}
}

signed main()
{
	// freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	T=input();
	loop:
	while (T--)
	{
		n=input(),v=input();
		if (v==0)
		{
			for (int i=1;i<=n;i++)
				m=input();
			print((1+n)*n/2,'\n');
			goto loop;
		}
		m=n,ans=0;
		n=0;
		while (m--)
		{
			a[++n]=input();
			if (a[n]==0||m==0)
			{
				if (a[n]==0)
					n--;
				work();
				n=0;
			}
		}
		print(ans,'\n');
	}
	return 0;
}
/*
1
100 160360732
4 1 9 0 0 0 9 2 1 9 7 3 0 8 6 8 3 5 9 6 6 3 7 5 2 5 8 7 0 5 8 1 6 3 7 0 0 7 1 3 4 7 9 6 7 3 9 4 4 0 6 5 9 5 6 9 8 1 0 0 4 9 2 5 1 9 7 1 7 3 2 2 5 9 7 6 9 2 0 0 0 0 7 5 0 0 4 4 4 2 3 2 3 1 2 9 3 7 8 7
*/
