#include<bits/stdc++.h>
//#define int long long
#define N 55555
#define M 555
#define INF 0x3f3f3f3f
#define MOD ((int )1e9+7)
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

int n,m;
int dp[N][M];

int min(int a,int b)
{
	return a<b?a:b;
}

int dfs(int s,int k)
{
	if (s==0)
		return (k==0)?1:0;
	if (~dp[s][k])
		return dp[s][k];
	int res=0;
	for (int i=1;i<=min(s,9);i++)
		res=(res+dfs(s-i,(k*10+i)%m))%MOD;
	return dp[s][k]=res;
}

signed main()
{
	n=input(),m=input();
	memset(dp,-1,sizeof(dp));
	print(dfs(n,m),'\n');
    return 0;
}