#include <bits/stdc++.h>
#define int long long
#define N 222
#define INF 0x3f3f3f3f
using namespace std;

int n, l1, l2, del, ans;
int s1[N * 10], s2[N * 10], s[N], a[N], b[N];
int v[N][N];
char c;
map<int, int> mp;
struct lyp
{
    int a, b, id;
};
vector<lyp> f;

namespace IOstream
{
#define int long long
#define print(a, b) prints(a), putchar(b)
    int BUF[22], BUFSIZE, IONUM, SIGN;
    char GET;

    inline int input()
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

    inline void prints(int IONUM)
    {
        if (IONUM < 0)
            IONUM = -IONUM, putchar('-');
        do
            BUF[++BUFSIZE] = IONUM % 10, IONUM /= 10;
        while (IONUM);
        while (BUFSIZE)
            putchar(BUF[BUFSIZE--] + '0');
    }

} // namespace IOstream
using namespace IOstream;

bool cmp1(lyp x, lyp y)
{
    if (x.a == y.a && x.b == y.b)
        return x.id < y.id;
    if (x.a == y.a)
        return x.b < y.b;
    return x.a < y.a;
}

bool cmp2(lyp x, lyp y)
{
    return x.id < y.id;
}

signed main()
{
    freopen("a.in", "r", stdin);freopen("a.out", "w", stdout);
    while ((c = getchar()) != '\n')
        s[++n] = c, mp[c] = n;
    while ((c = getchar()) != '\n')
        s1[++l1] = c;
    while ((c = getchar()) != '\n')
        s2[++l2] = c;
    for (int i = 1; v[i][0] = INF, i <= n; i++)
        for (int j = 1; v[0][j] = INF, j <= n; j++)
            v[i][j] = input(), a[i] = v[i][a[i]] > v[i][j] ? j : a[i], b[j] = v[b[j]][j] > v[i][j] ? i : b[j];
    for (int i = 1; i <= l1; i++)
        f.push_back((lyp){s1[i], s[a[mp[s1[i]]]], i});
    for (int i = 1; i <= l2; i++)
        f.push_back((lyp){s[b[mp[s2[i]]]], s2[i], i + l1});
    sort(f.begin(), f.end(), cmp1);
    for (int i = 0; i < f.size(); i++)
        if (f[i].a == f[i + 1].a && f[i].b == f[i + 1].b)
            f[i + 1].id = INF, del++, i++;
    sort(f.begin(), f.end(), cmp2);
    ans = 0;
    for (int i = 0; i < f.size() - del; i++)
        ans += v[mp[f[i].a]][mp[f[i].b]];
    printf("%lld\n", ans);
    for (int i = 0; i < f.size() - del; i++)
        printf("%c", f[i].a);
    puts("");
    for (int i = 0; i < f.size() - del; i++)
        printf("%c", f[i].b);
    puts("");
    return 0;
}
