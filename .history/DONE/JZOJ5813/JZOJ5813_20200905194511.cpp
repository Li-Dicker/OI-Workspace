#include<bits/stdc++.h>
#define int long long
#define N 11111
#define INF 0x3f3f3f3f
#define MOD 998244353
using namespace std;
int n,m,tot=1,num,ans,maxn;
int dp[N][222];
int cont[111];

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

int ksm(int x,int k)
{
    int res=1;
    while (k)
    {
        if (k&1)
            res=res*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return res;
}

signed main()
{
    n=input(),m=input();
    num=n;
    for (int i=2;i*i<=n;i++)
        if (!(num % i))·
        {
            int cnt = 1;
            while (!(num % i))
                num/=i,cnt++;
            cont[++cont[0]]=cnt-1;
            tot*=cnt;
        }
    if (num>1)
        tot<<=1,cont[++cont[0]]=1;
    num=1;
    for (int l=1;l<=cont[0];l++)
    {
        memset(dp,0,sizeof(dp));
        maxn=cont[l]*m;
        dp[0][0]=1;
        for (int i=0;i<=maxn;i++)
            for (int j=1;j<=m*2;j++)
            {
                for (int k=0;k<=min(i,cont[l]);k++)
                    dp[i][j]+=dp[i-k][j-1];
                dp[i][j] %= MOD;
            }
        num=num*dp[maxn][m<<1]%MOD;
        if (num>=MOD)
            num-=MOD;
    }
    ans=(ksm(tot,m<<1)+num)*ksm(2,MOD-2)%MOD;
    printf("%lld\n", ans);
    return 0;
}