#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n,flag=1,sum=0;
int val[N];
int c[N][N],dp[N][N];
char ch[N];
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

int min(int a,int b)
{
    return a<b?a:b;
}

signed main()
{
    n=input();
    for (int i=1;i<=n;i++)
    {
        val[i]=input();
        sum+=val[i];
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%s",ch+1);
        for (int j=1;j<=n;j++)
        {
            c[i][j]=ch[i][j]-'0';
            if (c[i][j])
                flag=0;
        }
    }
    if (flag)
    {
        for (int i=0;i<=n;i++)
            for (int j=0;j<=sum;j++)
                dp[i][j]=INF;
        dp[0][0]=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=(sum>>1);j++)
            {
                dp[i][j]=dp[i-1][j];
                if (j-val[i]>=0)
                    dp[i][j]=min(dp[i][j],dp[i-1][j-val[i]]+val[i])
            }
        for (int j=0;j<=(sum>>1);j++)
            
    }
    return 0;
}