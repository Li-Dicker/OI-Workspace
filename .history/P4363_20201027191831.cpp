#include<bits/stdc++.h>
#define int long long
#define next _nxt_
#define y _yy_
#define N 10
#define INF 0x3f3f3f3f
using namespace std;
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

int n,m,S1,S2,ans;
int a[N][N],b[N][N];
int dp[1<<(1<<N)];

bool check(int x,int k)
{
    if (k>=n+m)
        return false;
    x>>=(k-1);
    if (!(x&1))
        return false;
    if ((x>>1)&1)
        return false;
    return true;
}

int change(int x,int k)
{
    x^=(1<<(k-1));
    x|=(1<<k);
    return x;
}

int dfs(int statue,bool person)
{
    if (!statue)
        return dp[S2];
    int x=n+1,y=1;
    dp[statue]=(person)?(INF):(-INF);
    for (int i=1;i<n+m;i++)
    {
        if (statue>>(i-1)&1)
            x--;
        else
            y++;
        if (check(statue,i))
        {
            int next=change(statue,i);
            if (person==0)
                dp[statue]=max(dp[statue],dfs(next,person^1)+a[x][y]);
            else
                dp[statue]=min(dp[statue],dfs(next,person^1)-b[x][y]);
        }
    }
    return dp[statue];
}

signed main()
{
	n=input(),m=input();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=input();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            b[i][j]=input();
    S1=(1<<n)-1;
    S2=((1<<n)-1)<<m;
    memset(dp,INF,sizeof(dp));
    dp[S2]=0;
    print(dfs(S1,0),'\n');
    return 0;
}