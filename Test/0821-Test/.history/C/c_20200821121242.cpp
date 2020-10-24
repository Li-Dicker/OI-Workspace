#include<bits/stdc++.h>
#define int long long
#define N 1111
#define INF 0x3f3f3f3f
using namespace std;
int n,sum=0,flag=1,ans=INF;
int c[N][N], v[N], dp[N][N * 20];
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

signed main()
{
    n=input();
    for (int i = 1; i <= n; i++)
        sum += v[i]=input();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", ch + 1);
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = ch[j] - '0';
            if (c[i][j] == 1)
                flag = 0;
        }
    }
    if (flag)
    {
        int ans;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= sum / 2; j++)
                dp[i][j] = 1e9;
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= sum / 2; j++)
                if (j - v[i] >= 0)
                    dp[i][j] = min(dp[i - 1][j - v[i]] + v[i], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
        for (int j = 0; j <= sum / 2; j++)
            if (dp[n][j] <= 1e9)
                ans = j;
        print(sum - ans * 2,'\n');
        return 0;
    }
    else
    {
        int S=(1 << n) - 1;
        for (int i = 0; i <= S; i++)
        {
            int p = 0;
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    if (c[j][k] && (((1 << (j - 1)) & i) == ((1 << (k - 1)) & i)))
                        p = 1;
            if (p)
                continue;
            int cnt = 0;
            for (int j = 1; j <= n; j++)
                if ((1 << (j - 1)) & i)
                    cnt += v[j];
                else
                    cnt -= v[j];
            ans = min(ans, abs(cnt));
        }
        print(ans,'\n');
        return 0;
    }
}