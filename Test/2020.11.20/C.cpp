#include<bits/stdc++.h>
#define N 8888
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

int n,ans,ans1,ans2;
int a[N],s[N],sum[N];
int dp[N][N][3];

signed main()
{
	n=input();
	sum[0]=0;
	for (int i=1;i<=n;i++)
		s[i]=input(),a[i]=s[i]-i,sum[i]=sum[i-1]+(a[i]==0);
	ans=ans1=ans2=0;
	for (int i=1;i<=n;i++)
	{
		dp[i][0][0]=(a[i]==0);
		if (ans<dp[i][0][0]-(sum[i]-sum[i-1]))
			ans=dp[i][0][0]-(sum[i]-sum[i-1]),ans1=i-0,ans2=i+0;
		for (int j=1;j<=min(i-1,n-i);j++)
		{
			dp[i][j][0]=dp[i][j-1][0]+(a[i-j]==j*2)+(a[i+j]==-j*2);
			if (ans<dp[i][j][0]-(sum[i+j]-sum[i-j-1]))
				ans=dp[i][j][0]-(sum[i+j]-sum[i-j-1]),ans1=i-j,ans2=i+j;
		}
	}
	for (int i=1;i<n;i++)
	{
		dp[i][0][1]=(a[i]==1&&a[i+1]==-1);
		if (ans<dp[i][0][1]-(sum[i+1]-sum[i-1]))
			ans=dp[i][0][1]-(sum[i+1]-sum[i-1]),ans1=i-0,ans2=i+0+1;
		for (int j=1;j<=min(i-1,n-(i+1));j++)
		{
			dp[i][j][1]=dp[i][j-1][1]+(a[i-j]==(1+j*2))+(a[i+1+j]==-(1+j*2));
			if (ans<dp[i][j][1]-(sum[i+j+1]-sum[i-j-1]))
				ans=dp[i][j][1]-(sum[i+j+1]-sum[i-j-1]),ans1=i-j,ans2=i+j+1;
		}
	}
	if (ans1==ans2)
	{
		puts("1 1");
		return 0;
	}
	print(s[ans1],' '),print(s[ans2],'\n');print(ans,'\n'),print(dp[885][152][0],'\n');
	return 0;
}
/*
1910 734
734 1037
*/