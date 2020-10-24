#include <bits/stdc++.h>
#define int long long
#define N 333333
#define INF 0x3f3f3f3f
#define MOD 998244353
using namespace std;
typedef long long LL;
int n, m, tot = 1;
LL dp[N][111];

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

inline LL qui_pow(LL x, int y)
{
    if (y == 1)
        return x;
    LL t = qui_pow(x, y / 2);
    if (y & 1)
        return t * t % MOD * x % MOD;
    else
        return t * t % MOD;
}

signed main()
{
    n=input(),m=input();
    int nn = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (!(nn % i))
        {
            int cnt = 1;
            while (!(nn % i))
            {
                nn /= i;
                cnt++;
            }
            tot *= cnt;
        }
    }
    if (nn > 1)
        tot <<= 1;
    int lim = (tot + 1) * m;
    dp[0][0] = 1;
    for (int i = 1; i <= lim; ++i)
    {
        for (int j = 1; j <= m * 2; ++j)
        {
            for (int k = 1; k <= min(i, tot); ++k)
            {
                dp[i][j] += dp[i - k][j - 1];
            }
            dp[i][j] %= MOD;
        }
    }
    LL ans = (qui_pow(tot, m << 1) + dp[lim][m * 2]) * qui_pow(2, MOD - 2) % MOD;
    printf("%lld\n", ans);
    return 0;
}