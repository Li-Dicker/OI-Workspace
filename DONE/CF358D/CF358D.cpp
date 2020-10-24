#include<bits/stdc++.h>
#define int long long
#define N 3333
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[N],b[N],c[N];
int dp[N][3];
//0:firsti-1,second i;2:firsti,secondi-1
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

signed main()
{
	n=input();
	for (int i=1;i<=n;i++)
		a[i]=input();
	for (int i=1;i<=n;i++)
		b[i]=input();
	for (int i=1;i<=n;i++)
		c[i]=input();
	memset(dp,-INF,sizeof(dp));
	dp[1][0]=0;
	for (int i=2;i<=n+1;i++)
	{
		dp[i][1]=max(dp[i-1][1]+b[i-1],dp[i-1][0]+a[i-1]);
		dp[i][0]=max(dp[i-1][1]+c[i-1],dp[i-1][0]+b[i-1]);
	}
	print(dp[n+1][1],'\n');
	return 0;
}