#include<bits/stdc++.h>
#define int long long
#define N 1111
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y _yy_
using namespace std;
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

int n,ans1=INF,ans2=INF;
int sum[N];
int a[N][3],dp[N][N*6];

signed main()
{
	n=input();
	sum[0]=0;
	for (int i=1;i<=n;i++)
	{
		a[i][1]=input(),a[i][2]=input();
		sum[i]=sum[i-1]+a[i][1]+a[i][2];
	}
	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=sum[n]+1;j++)
			dp[i][j]=INF;
	dp[1][a[1][1]]=0,dp[1][a[1][2]]=1;
	for (int i=1;i<=n;i++)
		for (int j=sum[i];j>=1;j--)
		{
			dp[i+1][j+a[i+1][1]]=min(dp[i+1][j+a[i+1][1]],dp[i][j]);
			dp[i+1][j+a[i+1][2]]=min(dp[i+1][j+a[i+1][2]],dp[i][j]+1);
		}
	for (int i=1;i<=sum[n];i++)
	{
		if (dp[n][i]>=INF)
			continue ;
		if (abs((sum[n]-i)-i)==ans1)
			ans1=abs((sum[n]-i)-i),ans2=min(ans2,dp[n][i]);
		else if (abs((sum[n]-i)-i)<ans1)
			ans1=abs((sum[n]-i)-i),ans2=dp[n][i];
	}
	print(ans2,'\n');
	return 0;
}
/*

4
6 1
1 5
1 3
1 2

*/