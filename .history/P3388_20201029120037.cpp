// #include<bits/stdc++.h>
// #define int long long
// #define N 111111
// #define INF 0x3f3f3f3f
// #define MOD ((int)1e9+7)
// #define next _nxt_
// #define y _yy_
// using namespace std;
// namespace IOstream
// {
// 	#define int long long
// 	#define print(a,b) prints(a),putchar(b)
// 	int BUF[22],BUFSIZE,IONUM,SIGN;
// 	char GET;

// 	inline int input()
// 	{
// 		IONUM=0,SIGN=1;
// 		GET=getchar();
// 		while (GET<'0'||GET>'9')
// 		{
// 			if (GET=='-')
// 				SIGN=-1;
// 			GET=getchar();
// 		}
// 		while (GET>='0'&&GET<='9')
// 		{
// 			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
// 			GET=getchar();
// 		}
// 		return SIGN*IONUM;
// 	}

// 	inline void prints(int IONUM)
// 	{
// 		if (IONUM<0)
// 			IONUM=-IONUM,putchar('-');
// 		do
// 			BUF[++BUFSIZE]=IONUM%10,IONUM/=10;
// 		while (IONUM);
// 		while (BUFSIZE)
// 			putchar(BUF[BUFSIZE--]+'0');
// 	}

// }
// using namespace IOstream;

// int n,m,edgenum=0,dfnnum=0,ans=0;
// int tmp1,tmp2;
// int head[N],dfn[N],low[N];
// bool cut[N];

// struct Edge
// {
// 	int v,next;
// }edge[N<<1];

// void adde(int u,int v)
// {
// 	edge[++edgenum].next=head[u];
// 	head[u]=edgenum;
// 	edge[edgenum].v=v;
// }

// void dfs(int rt,int u,int fa)
// {
// 	dfn[u]=low[u]=++dfnnum;//dfn[u]=low[u] initially equals to dfn clock
// 	int soncnt=0;
// 	for (int i=head[u];i;i=edge[i].next)
// 	{
// 		int v=edge[i].v;
// 		if (v==fa)
// 			continue ;
// 		if (!dfn[v])//not vistied
// 		{
// 			soncnt++;//real son num
// 			dfs(rt,v,u);//dfs son
// 			low[u]=min(low[u],low[v]);//update low
// 			if (low[v]>=dfn[u]&&u!=rt)//cutpoint
// 				cut[u]=1;
// 		}
// 		else
// 			low[u]=min(low[u],dfn[v]);//update low[u]
// 	}
// 	if (soncnt>=2&&u==rt)
// 		cut[u]=1;//spceial for root
// }

// signed main()
// {
// 	n=input(),m=input();
// 	for (int i=1;i<=m;i++)
// 	{
// 		tmp1=input(),tmp2=input();
// 		adde(tmp1,tmp2);
// 		adde(tmp2,tmp1);
// 	}// add edge
// 	for (int i=1;i<=n;i++)
// 		if (!dfn[i])//dfs graphs
// 			dfs(i,i,0);//use i as root,dfs start at i
// 	for (int i=1;i<=n;i++)
// 		if (cut[i])
// 			ans++;
// 	print(ans,'\n');
// 	for (int i=1;i<=n;i++)
// 		if (cut[i])
// 			print(i,' ');
// 	return 0;
// }
#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y _yy_
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

int n,m,edgenum=0,dfnnum=0,ans=0;
int tmp1,tmp2;
int head[N],dfn[N],low[N],cut[N];

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

void dfs(int rt,int u,int fa)
{
	dfn[u]=low[u]=++dfnnum;
	int soncnt=0;
	for (int i=head[u];i;i=edge[i].nexy)
	{
		int v=edge[i].v;
		if (v==fa)
			continue ;
		if (!dfn[v])
		{
			soncnt++;
			dfs(rt,v,u);
			low[u]=min(low[u],low[v]);
			if (low[v]>=dfn[u])
				cut[u]=1;
		}
		else
			low[u]=min(low[u],dfn[v]);
	}
	if (soncnt>=2&&u==rt)
		cut[u]=1;
}

signed main()
{
	n=input(),m=input();
	for (int i=1;i<=n;i++)
	{
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2);
		adde(tmp2,tmp1);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			dfs(i,i,0);
	for (int i=1;i<=n;i++)
		if (cut[i])
			ans++;
	print(ans,'\n');
	for (int i=1;i<=n;i++)
		if (cut[i])
			print(i,' ');
	puts("");
	return 0;
}