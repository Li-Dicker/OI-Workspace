#include<bits/stdc++.h>
#define int long long
#define N 10
#define INF 0x3f3f3f3f
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

int n,m,S1,S2;
int a[N][N],b[N][N];
int dp[1<<(1<<N)];

void dfs(int statue,int person)
{
    
}

signed main()
{
	n=input(),m=input();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=input();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            b[i][j]=input();
    S1=(1<<n)-1;
    S2=((1<<n)-1)<<m;
    memset(dp,0,sizeof(dp));
    dfs(S1,0);
    return 0;
}