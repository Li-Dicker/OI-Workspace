#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a,b,n,m,r,k,p,ans;
int d[N],dis[N],vis[N],head[N],mark[N];
struct Edge
{
	int v,w,next;
}e[N<<1];

void adde(int u,int v,int w)
{
	e[++k].v=v;
	e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}
void dijkstra(int s)
{
	queue<int>q;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[s]=1;
		for(register int i=head[u];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
signed main()
{
	scanf("%d%d%d",&n,&m,&r);
	memset(mark,0,sizeof(mark));
	memset(head,-1,sizeof(head));
	for (int i=1;i<=m;i++)
		scanf("%d",&d[i]),mark[d[i]]=1;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		adde(a,b,1),adde(b,a,1);
	}
	for (int i=1;i<=n;i++)
	{
		dijkstra(i);
		p=0;
		for (int j=1;j<=m;j++)
		{
			if (i==d[j])
				continue;
			if(dis[d[j]]>r)
			{
				p=1;
				break;
			}
		}
		if (!p)
			ans++;
	}
	printf("%d",ans);
	return 0;
}
