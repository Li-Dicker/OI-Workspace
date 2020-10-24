#include<bits/stdc++.h>
#define int long long
#define N 555
#define INF 0x3f3f3f3f
using namespace std;

int n,m,edgenum=0,tmp1,tmp2;
int head[N<<1],a[N];
int dp[N][N][2];
struct Edge
{
    int v,next;
}edge[N<<1];

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

void adde(int u,int v)
{
    edge[++edgenum].next=head[u];
    head[u]=edgenum;
    edge[edgenum].v=v;
}

void dfs(int u,int fa)
{
    for (int i=head[u];i;i=edge[i].next)
    {
        if (edge[i].v==fa)
            continue ;
        dfs(edge[i].v,u);
        for (int j=m;j>=1;j--)
            for (int k=0;k<=m;k++)
            {
                if (j-k>=2)
                {
                    dp[u][j][1]=max(dp[u][j][1],dp[u][j-k-2][1],dp[edge[i].v][k][0]);
                    dp[u][j][0]=max(dp[u][j][0],dp[u][j-k-2][0]+dp[edge[i].v][k][0]);
                }
                if (j-k>=1)
                    dp[u][j][1]=max(dp[u][j][1],dp[u][j-k-1][[0]+dp[edge[i].v][k][1]]);
            }
    }
    for (int i=m;i>=1;i--)
    {
        
    }
}

signed main()
{
    n=input(),m=input();
    for (int i=1;i<=n;i++)
        a[i]=input();
    for (int i=1;i<=n-1;i++)
    {
        tmp1=input(),tmp2=input();
        adde(tmp1,tmp2);
        adde(tmp2,tmp1);
    }
    dfs(1,0);
    print(dp[1][m][1],'\n');
    return 0;
}