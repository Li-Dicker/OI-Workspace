#include <bits/stdc++.h>
#define int long long
#define N 222
#define INF 0x3f3f3f3f
using namespace std;

int n, l1, l2, del, ans;
int s1[N * 10], s2[N * 10], s[N], ml[N], mc[N];
int v[N][N];
char c;
map<int, int> mp;
struct node
{
    int a, b, id;
};
vector<node> f;

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

bool cmp1(node x, node y)
{
    if (x.a == y.a && x.b == y.b)
        return x.id < y.id;
    if (x.a == y.a)
        return x.b < y.b;
    return x.a < y.a;
}

bool cmp2(node x, node y)
{
    return x.id < y.id;
}

signed main()
{
    // freopen("a.in", "r", stdin);freopen("a.out", "w", stdout);
    while ((c = getchar()) != '\n')
        s[++n] = c, mp[c] = n;
    while ((c = getchar()) != '\n')
        s1[++l1] = c;
    while ((c = getchar()) != '\n')
        s2[++l2] = c;
    for (int i = 1; v[i][0] = INF, i <= n; i++)
        for (int j = 1; v[0][j] = INF, j <= n; j++)
            v[i][j] = input(), ml[i] = v[i][ml[i]] > v[i][j] ? j : ml[i], mc[j] = v[mc[j]][j] > v[i][j] ? i : mc[j];
    for (int i = 1; i <= l1; i++)
        f.push_back((node){s1[i], s[ml[mp[s1[i]]]], i});
    for (int i = 1; i <= l2; i++)
        f.push_back((node){s[mc[mp[s2[i]]]], s2[i], i + l1});
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