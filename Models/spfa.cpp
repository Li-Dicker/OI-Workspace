#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define INF 0x7fffffff
#define next _nxt_
#define y1 _yy_
using namespace std;
namespace IOstream
{
	int input()
	{
		int IONUM=0,SIGN=1;
		char GETCH;
		GETCH=getchar();
		while (GETCH<'0'||GETCH>'9')
		{
			if (GETCH=='-')
				SIGN=-1;
			GETCH=getchar();
		}
		while (GETCH>='0'&&GETCH<='9')
		{
			IONUM=IONUM*10+GETCH-'0';
			GETCH=getchar(); 
		}
		return IONUM*SIGN;
	}
	
	void print(int IONUM,char ENDCH=0)
	{
		int BUFSIZE=0;
		char BUF[22];
		if (IONUM<0)
		{
			putchar('-');
			IONUM*=-1;
		}
		do
		{
			BUF[++BUFSIZE]=IONUM%10+'0';
			IONUM/=10;
		}
		while(IONUM);
		while (BUFSIZE)
		{
			putchar(BUF[BUFSIZE]);
			BUFSIZE--;
		}
		if (ENDCH)
			putchar(ENDCH);
	}
}
using namespace IOstream;

int n,m,s,edgenum=0;
int tmp1,tmp2,tmp3;
int head[N],dis[N],vis[N],cnt[N];

struct Edge
{
	int v,w,next;
}edge[N<<1];

void adde(int u,int v,int w)
{
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
	edge[edgenum].w=w;
}

void spfa(int x)
{
	queue<int >q;
	dis[x]=0,vis[x]=1;
	q.push(x);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for (int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].v;
			if (dis[v]>dis[u]+edge[i].w)
			{
				dis[v]=dis[u]+edge[i].w;
				cnt[v]=cnt[u]+1;
				if (cnt[v]>=n)
					return ;
				if (!vis[v])
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
	n=input(),m=input(),s=input();
	for (int i=1;i<=m;i++)
	{
		tmp1=input(),tmp2=input(),tmp3=input();
		adde(tmp1,tmp2,tmp3);
	}
	for (int i=0;i<=n+11;i++)
		dis[i]=INF,vis[i]=0;
	spfa(s);
	for (int i=1;i<=n;i++)
		print(dis[i],' ');
	return 0;
}