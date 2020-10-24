#include<bits/stdc++.h>
#define int long long
#define N 1111
#define INF 0x3f3f3f3f
using namespace std;
int n,tmpe,t=0,ans=0;
int dp[N][N][3],num[N][N][3];
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

void Print_map(int i,int j,int k)
{
	if (i==1&&j==1)
	{
		putchar(k?'D':'R');
		return ;
	}
	if (i==1)
		Print_map(i,j-1,0);
	else if (j==1)
		Print_map(i-1,j,1);
	else if (dp[i][j][t]==dp[i][j-1][t]+num[i][j][t])
		Print_map(i,j-1,0);
	else
		Print_map(i-1,j,1);
	if (i!=n||j!=n)
		putchar(k?'D':'R');
}

signed main()
{
	n=input();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			tmpe=input();
			if (tmpe==0)
			{
				num[i][j][0]=num[i][j][1]=1;
				t=i;
			}
			else
			{
				num[i][j][0]=num[i][j][1]=0;
				while (tmpe%2==0)
					num[i][j][0]++,tmpe/=2;
				while (tmpe%5==0)
					num[i][j][1]++,tmpe/=5;
			}
		}
	memset(dp,INF,sizeof(dp));
	dp[1][1][0]=num[1][1][0];
	dp[1][1][1]=num[1][1][1];
	for (int k=0;k<=1;k++)
		for (int i=1;i<=n;i++)
			for (int j=1+(i==1);j<=n;j++)
				dp[i][j][k]=min(dp[i-1][j][k],dp[i][j-1][k])+num[i][j][k];
	ans=min(dp[n][n][0],dp[n][n][1]);
	if (t&&ans)
	{
		puts("1");
		for (int i=1;i<t;i++)
			putchar('D');
		for (int i=1;i<n;i++)
			putchar('R');
		for (int i=t;i<n;i++)
			putchar('D');
	}
	else
	{
		print(ans,'\n');
		t=(dp[n][n][0]>dp[n][n][1]);
		Print_map(n,n,0);
	}
	return 0;
}