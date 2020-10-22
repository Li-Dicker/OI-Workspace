#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define INF 0x3f3f3f3f3f3f
using namespace std;

int n,m,k,edgenum=0,tnum=0,bctnum=0,totnum=0,othernum=0,cenum=0;
int tmp1,tmp2;
int head[N],vis[N],vis2[N],cecnt[N];

struct Edge
{
	int v,next;
}edge[N<<2];
struct TMPE
{
	int ecnt,pcnt,cid,cnum,flag;
	
	void init()
	{
		ecnt=pcnt=cid=cnum=flag=0;
	}
}tmpe;

namespace IOstream
{
	int input()
	{
		int IN=0,SIGN=1;
		char IOCH=getchar();
		while (IOCH<'0'||IOCH>'9')
		{
			if (IOCH=='-')
				SIGN=-1;
			IOCH=getchar();
		}
		while (IOCH>='0'&&IOCH<='9')
		{
			IN=(IN<<1)+(IN<<3)+(IOCH^48);
			IOCH=getchar();
		}
		IN*=SIGN;
		return IN;
	}
	
	void print(int OUT,char OUTEND)
	{
		printf("%lld",OUT);
		putchar(OUTEND);
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
	vis[u]=1;
	tmpe.pcnt++;
	for (int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if (v==fa)
			continue ;
		if (vis[v])
			tmpe.cid=v;
		else
		{
			tmpe.ecnt++;
			dfs(v,u);
		}
	}
}

void dfsc(int u,int fa)
{
	vis2[u]=1;
	for (int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if (v==fa)
			continue ;
		if (vis2[v])
		{
			tmpe.flag=1;
			tmpe.cnum++;
			break ;
		}
		dfsc(v,u);
		if (tmpe.flag==1)
		{
			tmpe.cnum++;
			break ;
		}
	}
}

bool cmp(int a,int b)
{
	return a>b;
}

signed main()
{
	//freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	n=input(),m=input(),k=input();
	for (int i=1;i<=m;i++)
	{
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2);
		adde(tmp2,tmp1);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			totnum++;
			tmpe.init();
			dfs(i,0);
			if (tmpe.pcnt==tmpe.ecnt+1&&tmpe.cid!=0)
			{
				bctnum++;
				dfsc(tmpe.cid,0);
				cenum+=tmpe.cnum;
				cecnt[bctnum]=tmpe.cnum;
			}
			else if (tmpe.pcnt==tmpe.ecnt+1)
				tnum++;
			else
				othernum++;
		}
	if (k==0)
	{
		print(totnum,'\n');
		exit(0);
	}
	else if (totnum==tnum)
	{
		print(totnum+k,'\n');
		exit(0);
	}
	else if (totnum==tnum+bctnum)
	{
		if (m-cenum>=k)
			print(totnum+k,'\n');
		else
		{
			int ans=totnum+(m-cenum);
			k-=(m-cenum);
			sort(cecnt+1,cecnt+bctnum+1,cmp);
			int i=1;
			while (k>=cecnt[i])
			{
				k-=cecnt[i];
				ans+=cecnt[i]-1;
				i++;
			}
			ans+=((k>=2)?(k-1):0);
			print(ans,'\n');
		}
		exit(0);
	}
	return 0;
}
/*
14 14 0
1 2
1 3
2 3
2 4
4 5
5 7
7 6
6 4
8 9
10 11
11 14
14 13
13 12
12 10


20 15 3
1 2
1 3
5 6
5 7
7 13
6 8
6 9
8 10
8 11
11 12
14 15
14 16
17 1
18 19
19 20

30 30 8
1 2
1 3
2 3
3 5
2 4
1 6
1 7
1 8
8 9
8 10
11 12
11 13
14 13
13 15
12 14
11 16
11 17
11 18
18 19
18 20
21 22
30 23
22 23
23 25
22 24
21 26
21 27
21 28
28 29
28 30


*/