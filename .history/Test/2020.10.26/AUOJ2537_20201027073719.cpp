#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define INF 0x3f3f3f3f
#define MOD 998244353
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

int T,n,a,b;
int dp[N][3];

void pre()
{
	dp[1][1]=1;
	for (int i=2;i<=N-11111;i++)
	{
		dp[i-1][2]=dp[i-2][1];
		dp[i][1]=(dp[i-1][1]+dp[i-2][2])%MOD;
	}
}

signed main()
{
	pre();
	T=input();
	while (T--)
	{
		n=input(),a=input(),b=input();
		if (a>b)
			swap(a,b);
		a=(a==1)?1:(a+1);
		b=(b==n)?n:(b-1);
		print(dp[b-a+1][1],'\n');
	}
    return 0;
}