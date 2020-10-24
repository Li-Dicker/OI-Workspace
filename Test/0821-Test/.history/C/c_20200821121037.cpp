#include<bits/stdc++.h>
#define int long long
#define N 1111
#define INF 0x3f3f3f3f
using namespace std;
int n,sum=0,flag=1;
int c[N][N], v[N], dp[N][N * 20];
char ch[N];
int main()
{
    scanf("%d", &n);
    int pd = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", ch + 1);
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = ch[j] - '0';
            if (c[i][j] == 1)
                pd = 0;
        }
    }
    if (pd)
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
        cout << sum - ans * 2;
        return 0;
    }
    else
    {
        int ans = 1e9;
        for (int i = 0; i <= (1 << n) - 1; i++)
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
        cout << ans;
        return 0;
    }
}