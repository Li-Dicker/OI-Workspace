#include<bits/stdc++.h>
#define int long long
#define N 666
#define INF 0x7fffffff
#define MOD ((int)1e9+7)
#define next _nxt_
#define y1 _yy_
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

int n,K,tot=0;
int tmp1=0;
int a[N],sum[N];
int dp[N][N];

void print_ans(int x)
{
	int flag=1;
	for (int i=x;i>=1;i--)
	{
		if (sum[x]-sum[i-1]<=dp[K][n])
			continue ;
		print_ans(i);
		print(i+1,' ');
		print(x,'\n');
		flag=0;
		break ;
	}
	if (flag==1)
		print(1,' '),print(x,'\n');
	
}

signed main()
{
	n=input(),K=input();
	sum[0]=0;
	for (int i=1;i<=K+11;i++)
		for (int j=1;j<=n;j++)
			dp[i][j]=INF;
	for (int i=1;i<=n;i++)
		a[i]=input(),dp[1][i]=sum[i]=sum[i-1]+a[i];
	for (int i=2;i<=K;i++)
		for (int j=i;j<=n;j++)
			for (int k=1;k<=j-1;k++)
				dp[i][j]=min(dp[i][j],max(dp[i-1][k],sum[j]-sum[k]));
	print_ans(n);
	return 0;
}	