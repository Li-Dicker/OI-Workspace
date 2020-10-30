#include<bits/stdc++.h>
#define int long long
#define N 2222
#define INF 0x3f3f3f3f
using namespace std;
int n,k,edgenum=0;
int tmp1,tmp2,tmp3;
int head[N],size[N];
int dp[N][N];
struct Edge
{
    int v,w,next;
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

void adde(int u,int v,int w)
{
    edge[++edgenum].next=head[u];
    head[u]=edgenum;
    edge[edgenum].v=v;
    edge[edgenum].w=w;
}

void dfs(int u,int fa)
{
    size[u]=1;
    dp[u][0]=dp[u][1]=0;
    //dp[u][1]=0,we use it to load in the loop in line 75,if not,the ans is wrong
    for (int I=head[u];I;I=edge[I].next)
    {
        int v=edge[I].v;
        if (v==fa)
            continue ;
        dfs(v,u);
        size[u]+=size[v];
        for (int i=min(k,size[u]);i>=0;i--)
            for (int j=0;j<=min(i,size[v]);j++)
                if (dp[u][i-j]!=-1)
                    dp[u][i]=max(dp[u][i],
                    dp[u][i-j]+dp[v][j]+(j*(k-j)+(size[v]-j)*(n-k+j-size[v]))*edge[I].w);
                    //every edge has a contribution for the black point pairs and white point pairs
    }
}

signed main()
{
	n=input(),k=input();
    for (int i=1;i<n;i++)
    {
        tmp1=input(),tmp2=input(),tmp3=input();
        adde(tmp1,tmp2,tmp3);
        adde(tmp2,tmp1,tmp3);
    }//add edges
    memset(dp,-1,sizeof(dp));
    dfs(1,0);
    print(dp[1][k],'\n');
    //the subtree rooted as 1,ans has k points in black
    return 0;
}