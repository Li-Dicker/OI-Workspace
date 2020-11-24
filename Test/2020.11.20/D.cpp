#include<bits/stdc++.h>
#define N 511
#define M 100011
#define INF 0x3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y1 _yy_
using namespace std;
namespace IOstream
{
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

int n,sum=0,ans=INF;
int a[N];
int dp[N][M];

signed main()
{
	n=input();
    for(int i=1;i<=n;i++)
        a[i]=input(),sum+=a[i];
    sort(a+1,a+n+1);
	memset(dp,-INF,sizeof(dp));
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=sum-a[i];j++)
			dp[i][j]=max(max(dp[i][j],dp[i-1][j]),max(dp[i-1][j+a[i]],dp[i-1][abs(j-a[i])])+a[i]);
	print(sum-dp[n][0]/2,'\n');
	// print((sizeof(dp)+sizeof(a))/1024/1024,'\n');
	return 0;
}