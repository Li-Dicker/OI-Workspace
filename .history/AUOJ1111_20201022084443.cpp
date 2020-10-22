#include<bits/stdc++.h>
#define int long long
#define N 10
#define INF 0x3f3f3f3f
using namespace std;

int n,K,ans=0;
int S;
int calc[N];
int dp[N][(1<<N)][N*N];

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

int check_line(int x,int y)
{
    for (int i=2;i<=n-1;i++)
    {
        if (((x>>(i-1))&1)&&(((x>>i)&1)||((x>>(i-2))&1)||((y>>(i-1))&1)||((y>>i)&1)||((y>>(i-2))&1)))
            return false;
        if (((y>>(i-1))&1)&&(((y>>i)&1)||((y>>(i-2))&1)||((x>>(i-1))&1)||((x>>i)&1)||((x>>(i-2))&1)))
            return false;
    }
    return true;
}

int line_num(int x)
{
    int res=0;
    while (x)
    {
        if (x&1)
            res++;
        x>>=1;
    }
    return res;
}

signed main()
{
	n=input(),K=input();
    memset(dp,0,sizeof(dp));
    S=(1<<n)-1;
    for (int i=0;i<=S;i++)
        if(check_line(i,0))
            calc[i]=line_num(i),dp[1][i][calc[i]]=1;
    for (int i=2;i<=n;i++)
        for (int j=0;j<=S;j++)
            for (int k=0;k<=S;k++)
                if (check_line(k,j))
                    for (int l=calc[j]+calc[k];l<=K;l++)
                        dp[i][j][l]+=dp[i-1][k][l-calc[j]];
    for (int i=0;i<=S;i++)
        if (check_line(i))
        ans+=dp[n][i][K],print(dp[n][i][K],'\n');
    print(ans,'\n');
    return 0;
}