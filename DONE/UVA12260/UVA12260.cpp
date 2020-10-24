#include<bits/stdc++.h>
#define int long long
#define N 1111
#define INF 0x3f3f3f3f
using namespace std;
int T,n,sum=0,cnt=0;
int dp[N][N],cost[N][N];
char name[11];
struct point
{
    int x,y;
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
    if (p.x==q.x)
        return p.y<q.y;
    return p.x>q.x;
}

int min(int a,int b)
{
    return a<b?a:b;
}

signed main()
{
    T=input();
    while (T--)
    {
        sum=cnt=0;
        memset(dp,0,sizeof(dp));
        memset(cost,0,sizeof(cost));
        n=input();
        gets(name+1);
        scanf("%s",name+1);
        for (int i=1;i<=n;i++)
            a[i].x=input(),a[i].y=input(),sum+=a[i].x;
        sort(a+1,a+n+1,cmp);
        for (int i=(name[1]=='P'?2:1);i<=n;i++)
        {
            cnt++;
            for (int j=1;j<=(cnt+1)/2;j++)
            {
                if (dp[i-1][j]==dp[i-1][j-1]+a[i].y)
                {
                    dp[i][j]=dp[i-1][j];
                    cost[i][j]=min(cost[i-1][j],cost[i-1][j-1]+a[i].x);
                }
                else if (dp[i-1][j]>dp[i-1][j-1]+a[i].y)
                {
                    

                    dp[i][j]=dp[i-1][j];
                    cost[i][j]=cost[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j-1]+a[i].y;
                    cost[i][j]=cost[i-1][j-1]+a[i].x;
                }
            }
        }
        print(sum-cost[n][(cnt+1)/2],' ');
        print(dp[n][(cnt+1)/2],'\n');
    }
    return 0;
}