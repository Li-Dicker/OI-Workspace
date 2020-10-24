#include<bits/stdc++.h>
#define int long long
#define N 333
#define INF 0x3f3f3f3f3f3f
using namespace std;
int n, sx, sy, cnt;
int out[N], op[N], a[22][5][5];
int dx[]={ 0, 1, -1, 0, 0 }, dy[]={ 0, 0, 0, 1, -1 };
bool pval[22][5][5], vis[22][5][5];
char ch[6]={ 0, 'S', 'N', 'E', 'W', 'U' };
double ans=-INF;

namespace IOstream
{
    #define int long long
    #define print(a,b) prints(a),putchar(b)
    int BUF[22], BUFSIZE, IONUM, SIGN;
    char GET;

    inline int input()
    {
        IONUM=0, SIGN=1;
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
            IONUM=-IONUM, putchar('-');
        do
            BUF[++BUFSIZE]=IONUM%10, IONUM/=10;
        while (IONUM);
        while (BUFSIZE)
            putchar(BUF[BUFSIZE--]+'0');
    }

}
using namespace IOstream;

void dfs(int k, int x, int y, int s, int mnum)
{
    if (vis[k][x][y]||k>n||x<1||x>4||y<1||y>4)
        return;
    vis[k][x][y]=true;
    if (k==n&&(double)s/mnum>ans)
    {
        ans=(double)s/mnum;
        cnt=mnum;
        for (int i=1;i<=cnt;i++)
            out[i]=op[i];
    }
    for (int i=1;i<=4;i++)
    {
        op[mnum]=i;
        dfs(k, x+dx[i], y+dy[i], s+a[k][x+dx[i]][y+dy[i]], mnum+1);
    }
    if (pval[k][x][y])
    {
        op[mnum]=5;
        dfs(k+1, x, y, s+a[k+1][x][y], mnum+1);
    }
    vis[k][x][y]=0;
}

signed main()
{
    n=input(), sx=input(), sy=input();
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=4;j++)
            for (int k=1;k<=4;k++)
                a[i][j][k]=input();
        for (int j=1;j<=4;j++)
            for (int k=1;k<=4;k++)
                pval[i][j][k]=input();
    }
    dfs(1, sx, sy, a[1][sx][sy], 1);
    print(cnt-1, '\n');
    for (int i=1;i<=cnt-1;i++)
        putchar(ch[out[i]]);
    puts("");
    return 0;
}

