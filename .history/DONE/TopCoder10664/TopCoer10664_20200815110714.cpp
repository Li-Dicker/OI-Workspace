#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#define N 111
#define inf 0x3f3f3f3f3f3f
#define ninfll 0xc0c0c0c0c0c0c0c0
using namespace std;

namespace IOstream
{
    #define print(a, b) prints(a), putchar(b)
    long long BUF[22], BUFSIZE, IONUM, SIGN;
    char GET;

    inline long long input()
    {
        IONUM = 0, SIGN = 1;
        GET = getchar();
        while (GET < '0' || GET > '9')
        {
            if (GET == '-')
                SIGN = -1;
            GET = getchar();
        }
        while (GET >= '0' && GET <= '9')
        {
            IONUM = (IONUM << 3) + (IONUM << 1) + (GET & 15);
            GET = getchar();
        }
        return SIGN * IONUM;
    }

    inline void prints(long long IONUM)
    {
        if (IONUM < 0)
            IONUM = -IONUM, putchar('-');
        do
            BUF[++BUFSIZE] = IONUM % 10, IONUM /= 10;
        while (IONUM);
        while (BUFSIZE)
            putchar(BUF[BUFSIZE--] + '0');
    }

}
using namespace IOstream;

class RowGame
{
private:

    long long n, m, sum, ans = 0;
    long long maxc[N], val[N], step[N];
    long long mp[N][N];

    long long max(long long a, long long b)
    {
        return a > b ? a : b;
    }

    void init()
    {
        memset(mp, 0xc0, sizeof(mp));
        memset(maxc, 0xc0, sizeof(maxc));
        memset(step, 0x3f, sizeof(step));
        memset(val, 0xc0, sizeof(val));
    }

    void DP()
    {
        step[1] = val[1] = 0;
        for (long long KK = 1; KK < m; KK++)
        {
            for (long long i = 1; i <= m; i++)
            {
                if (step[i] == inf)
                    continue;
                for (long long j = 1; j <= m; j++)
                {
                    if (mp[i][j] == ninfll)
                        continue;
                    long long tmp1 = step[i], tmp2 = val[i];
                    if (tmp2 + mp[i][j] < 0)
                    {
                        if (maxc[i] <= 0)
                            continue;
                        long long shua = (-(tmp2 + mp[i][j]) + maxc[i] - 1) / maxc[i];
                        tmp1 += shua * 2, tmp2 += shua * maxc[i];
                    }
                    tmp1++, tmp2 += mp[i][j];
                    if (tmp1 < step[j] || (tmp1 == step[j] && tmp2 > val[j]))
                        step[j] = tmp1, val[j] = tmp2;
                }
            }
        }
    }

public:

    long long score(vector<int> board, int k)
    {
        n = board.size(), m = n << 1;
        init();
        for (long long i = 1; i <= n; i++)
        {
            sum = 0;
            for (long long j = i; j <= n; j++)
            {
                sum += board[j - 1];
                mp[i][j + n] = mp[j + n][i] = sum;
            }
        }
        for (long long i = 1; i <= m; i++)
            for (long long j = 1; j <= m; j++)
                maxc[i] = max(maxc[i], mp[i][j] + mp[j][i]);
        DP();
        ans = 0;
        for (long long i = 1; i <= m; i++)
        {
            // printf("%d %d %lld\n", i, step[i], val[i]);
            if (step[i] > k)
                continue;
            ans = max(ans, val[i]);
            if (maxc[i] >= 0)
            {
                ans = max(ans, val[i] + (k - step[i]) / 2 * maxc[i]);
                if (step[i] < k)
                    for (long long j = 1; j <= m; j++)
                        if (mp[i][j] != ninfll)
                            ans = max(ans, val[i] + (k - step[i] - 1) / 2 * maxc[i] + mp[i][j]);
            }
        }
        return ans;
    }
}Problem;
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
vector<int> board;
long long n, m, x;
signed main()
{
    n = input(), m = input();
    for (long long i = 1; i <= n; i++)
    {
        x = input();
        board.push_back(x);
    }
    print(Problem.score(board, m), '\n');
    return 0;
}
#endif