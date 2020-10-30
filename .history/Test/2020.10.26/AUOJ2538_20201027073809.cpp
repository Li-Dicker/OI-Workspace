#include<bits/stdc++.h>
//#define int long long
#define N 1000005
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

int n,m,edgenum=0,ans=0;
int tmp1,tmp2;
int col[N],head[N],dis[N];
struct Edge
{
	int v,next;
}edge[N<<1];

void adde(int u,int v)
{
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
}


class Sub1
{
	private:
		
	int dis1,point;
	
	void dfs(int u,int fa)
	{
		for (int i=head[u];i;i=edge[i].next)
		{
			if (edge[i].v==fa)
				continue ;
			dis[edge[i].v]=dis[u]+1;
			dfs(edge[i].v,u);
		}
	}
	
	public:
	
	void solve()
	{
		dis[1]=1;
		dfs(1,0);
		for (int i=1;i<=n;i++)
			if (dis[i]>dis1)
				dis1=dis[i],point=i;
		dis[point]=1;
		dfs(point,0);
		for (int i=1;i<=n;i++)
			ans=max(ans,dis[i]);
		print(ans,'\n');
	}
}subtask1;

class Sub2
{
	private:
		
	int vis[333][333];
	
	void dfs(int u,int fa)
	{
		vis[u][col[u]]=1;
		dis[u]=dis[fa]+1;
		for (int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].v;
			if (v==fa)
				continue;
			dfs(v,u);
			for (int j=1;j<=m;j++)
				if (vis[v][j])
					vis[u][j]=1;
		}
		int colnum=0;
		for (int i=1;i<=m;i++)
			colnum+=vis[u][i];
		if (colnum==m)
			ans=max(dis[u],ans);
	}
	
	public:
		
	void solve()
	{
		for (int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			dfs(i,0);
		}
		print(ans,'\n');
	}
	
}subtask2;

signed main()
{
//	freopen("ex_tree1.in","r",stdin);
	n=input(),m=input();
	for (int i=1;i<=n;i++)
		col[i]=input();
	for (int i=1;i<n;i++)
	{
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2);
		adde(tmp2,tmp1);
	}
	if (m==1)
		subtask1.solve();
	else
		subtask2.solve();
    return 0;
}
