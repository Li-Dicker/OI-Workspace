#include<bits/stdc++.h>
#define int int
#define N 2222
#define INF 0x3f3f3f3f
#define pii pair<long long,long long>
using namespace std;
int n,ans=0,tmpe,edgenum=0;
int head[N*N*2],vis[N*N*2],dis[N*N*2];
int dis_ans[N][N];
priority_queue<pii,vector<pii> >q;
struct Edge
{
    int v,next;
}edge[N*N*4];
namespace IOstream
{
    #define int int
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

void dijkstra(int x)
{
	for (int i=0;i<=n+11;i++)
		dis[i]=INF,vis[i]=0;
	dis[x]=0;
	q.push(make_pair(0,x));
	while (!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u]=1;
		for (int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].v;
			if (dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}

signed main()
{
    n=input();
    memset(dis_ans,INF,sizeof(dis_ans));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            tmpe=getchar()-'0';
            if (tmpe)
                dis_ans[i][j]=1;
        }
        getchar();
    }
    if (n>=500)
    {
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    dis_ans[i][j]=min(dis_ans[i][j],dis_ans[i][k]+dis_ans[k][j]);
    }
    else
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (i==j)
                    continue ;
                if (dis_ans[i][j]!=INF)
                    adde(i,j);
            }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (dis_ans[i][j]==INF)
                {
                    dijkstra(i);
                    for (int k=1;k<=n;k++)
                        dis_ans[i][j]=min(dis_ans[i][j],dis[k]);
                }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;i++)
                print(dis_ans[i][j],' ');
            puts("");
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue ;
            if (dis_ans[i][j]==INF)
                ans+=n*n;
            else
                ans+=dis_ans[i][j]*dis_ans[i][j];
        }
    print(ans,'\n');
    return 0;
}
/*
5
11000
01101
11110
01011
10011
*/