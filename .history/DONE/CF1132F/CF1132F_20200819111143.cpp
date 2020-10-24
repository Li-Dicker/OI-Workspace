#include<bits/stdc++.h>
#define int long long
#define N 555
#define INF 0x3f3f3f3f
using namespace std;
int n;
int dp[N][N];
char a[N];
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
	scanf("%s",a+1);
	memset(dp,INF,sizeof(dp));
	//dp[i][j]表示区间[i,j]的代价
	for (int i=1;i<=n;i++)
		dp[i][i-1]=0,dp[i][i]=1;
	for (int len=2;len<=n;len++)//枚举区间长度
		for (int i=1;i+len-1<=n;i++)//枚举左端点
		{
			int j=i+len-1;//根据左端点计算右端点
			for (int k=i;k<j;k++)//计算断点
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j-1]+1-(a[k]==a[j]));
		}
	print(dp[1][n],'\n');
	return 0;
}