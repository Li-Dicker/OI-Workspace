#include<bits/stdc++.h>
#define int long long
#define N 222222
#define M 1111111
#define INF 0x3f3f3f3f3f3f
using namespace std;

int n,ans=-INF;
int a[N],mp[N];

namespace IOstream
{
	#define int long long
	#define print(a,b) prints(a),putchar(b)
	int BUF[22],BUFSIZE,IONUM,SIGN;
	char GET;

	inline int input()
	{
		IONUM=0,SIGN=1;
		GET=getchar();
		while (GET<'0'||GET>'9')
		{
			if (GET=='-')
				SIGN=-1;
			GET=getchar();
		}
		while (GET>='0'&&GET<='9')
		{
			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
			GET=getchar();
		}
		return SIGN*IONUM;
	}

	inline void prints(int IONUM)
	{
		if (IONUM<0)
			IONUM=-IONUM,putchar('-');
		do
			BUF[++BUFSIZE]=IONUM%10,IONUM/=10;
		while (IONUM);
		while (BUFSIZE)
			putchar(BUF[BUFSIZE--]+'0');
	}

}
using namespace IOstream;

int min(int a,int b)
{
	return a<b?a:b;
}

signed main()
{
	n=input();
	for (int i=1;i<=n;i++)
		mp[a[i]=input()]=a[i];
	// a[n+1]=min(a[n]*2,N-111111);
	// for (int i=1;i<=n;i++)
	// 	for (int j=a[i]+1;j<=a[i+1];j++)
	// 		mp[j]=a[i];
	// for (int i=1;i<=n;i++)
	// 	for (int j=1;a[i]*j<=a[n+1];j++)
	// 		if (mp[a[i]*j]>=a[i])
	// 			ans=max(ans,mp[a[i]*j]%a[i]);
	// print(ans,'\n');
	for (int i=1;i<=a[n];i++)
		if (mp[i]==0)
			mp[i]==mp[i-1];
	for (int i=1;i<=a[n];i++)
		print(mp[i],' ');
	return 0;
}