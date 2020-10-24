#include<bits/stdc++.h>
#define int long long
#define N 3333
#define INF 0x3f3f3f3f3f3f3f
using namespace std;
int n,ans=INF;
int dp[N][N];
struct point
{
    int x,c;
}a[N];
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

bool cmp(point p,point q)
{
    return p.x<q.x;
}

int min(int a,int b)
{
    return a<b?a:b;
}

signed main()
{
    n=input();
    for (int i=1;i<=n;i++)
        a[i].x=input(),a[i].c=input();
    sort(a+1,a+n+1,cmp);
    dp[1][1]=a[1].c;
    for (int i=2;i<=n;i++)
    {
        int minn=INF;
        for (int j=1;j<i;j++)
        {
            dp[i][j]=dp[i-1][j]+a[i].x-a[j].x;
            minn=min(minn,dp[i-1][j]);
        }
        dp[i][i]=minn+a[i].c;
    }
    for (int i=1;i<=n;i++)
        ans=min(ans,dp[n][i]);
    print(ans,'\n');
    return 0;
}