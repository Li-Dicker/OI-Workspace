#include<bits/stdc++.h>
#define int long long
#define N 222
#define INF 0x3f3f3f3f
using namespace std;
int T,n,ans=0;
int a[N],b[N];
int dp[N][N];
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
    T=input();
    for (int CASE=1;CASE<=T;CASE++)
    {
        n=input();
        for (int i=1;i<=n;i++)
            a[i]=input();
        for (int i=1;i<=n;i++)
            b[i]=input();
        b[0]=b[n+1]=0;
        memset(dp,INF,sizeof(dp));
        for (int i=1;i<=n;i++)
            dp[i][i]=a[i]+b[i-1]+b[i+1];
        for (int len=1;len<n;len++)
            for (int i=1;i+len<=n;i++)
                for (int j=0;j<len;j++)
                    dp[i][i+len]=min(dp[i][i+len],dp[i][i+j]+dp[i+j+1][i+len]+min(b[i-1]-b[i+j],b[i+len+1]-b[i+j+1]));
        printf("Case #%lld: %lld\n",CASE,dp[1][n]);
    }
    return 0;
}
/*
2
3
3 5 7
8 2 0
10
1 3 5 7 9 2 4 6 8 10
9 4 1 2 1 2 1 4 5 1

Case #1: 17
Case #2: 74
*/