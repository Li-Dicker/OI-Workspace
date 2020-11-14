#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define INF 0x7fffffff
#define MOD ((int)1e9+7)
#define next _nxt_
#define y1 _yy_
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

int n,m,s,edgenum=0;
int tmp1,tmp2,tmp3;
int head[N],dis[N],vis[N];

struct Edge
{
	int v,w,next;
}edge[N<<1];

queue<int >q;

void adde(int u,int v,int w)
{
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
	edge[edgenum].w=w;
}

void spfa(int x)
{
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
				if (!vis[v])
				{
					q.push(v);
					vis[v]=1;
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
	puts("");
	return 0;
}