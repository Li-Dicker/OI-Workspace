#include<bits/stdc++.h>
#define int long long
#define N 11111
#define INF 0x3f3f3f3f
#define MOD 998244353
using namespace std;
int n,m,tot=1,all;
int dp[N][222];
int cc[111];

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

int main()
{
    n=input(),m=input();
    num=n;
    for (register int i = 2; i * i <= n; ++i)
    {
        if (!(nn % i))
        {
            register int cnt = 1;
            while (!(nn % i))
            {
                nn /= i;
                cnt++;
            }
            cc[++cc[0]] = cnt - 1;
            tot *= cnt;
        }
    }
    if (nn > 1)
        tot <<= 1, cc[++cc[0]] = 1;
    int all = 1;
    for (register int l = 1; l <= cc[0]; ++l)
    {
        memset(dp, 0, sizeof dp);
        register int lim = cc[l] * m;
        dp[0][0] = 1;
        for (register int i = 0; i <= lim; ++i)
        {
            for (register int j = 1; j <= m * 2; ++j)
            {
                for (register int k = 0; k <= min(i, cc[l]); ++k)
                {
                    dp[i][j] += dp[i - k][j - 1];
                }
                dp[i][j] %= MOD;
            }
        }
        all = all * dp[lim][m << 1] % MOD;
        if (all >= MOD)
            all -= MOD;
    }
    int ans = (ksm(tot, m << 1) + all) * ksm(2, MOD - 2) % MOD;
    printf("%lld\n", ans);
    return 0;
}