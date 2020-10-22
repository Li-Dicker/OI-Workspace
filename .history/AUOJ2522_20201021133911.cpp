#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;

int n,m,k,edgenum=0,cirnum=0;
int tmp1,tmp2;
int head[N],dfn[N],low[N],vis[N],vis2[N],cir[N];

struct Edge
{
	int v,next;
}edge[N<<1];

map<int ,int >mp;

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
	dfn[u]=low[u]=dfn[fa]+1;
	vis[u]=1;
	for (int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if (v==fa)
			continue ;
		if (vis[v])
		{
			low[u]=low[v];
			continue ;
		}
		else
			dfs(v,u);
		if (low[v]!=dfn[v])
			low[u]=min(low[u],low[v]);
	}
}

void add(int x,int y)
{
	if (!mp[x])
		mp[x]=++cirnum;
	cir[mp[x]]=max(cir[mp[x]],y-x+1);
}

void getcir(int u,int fa)
{
	vis2[u]=1;
	add(low[u],dfn[u]);
	for (int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].next;
		if (v==fa)
			continue ;
		if (!vis2[v])
			getcir(u,v);
	}
}

signed main()
{
	n=input(),m=input(),k=input();
	for (int i=1;i<=m;i++)
	{
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2);
		adde(tmp2,tmp1);
	}
	dfn[0]=low[0]=0;
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			mp.clear();
			dfs(i,0);
			getcir(i,0);
		}
	}
	for (int i=1;i<=n;i++)
		print(i,' '),print(dfn[i],' '),print(low[i],'\n');
	for (int i=1;i<=cirnum;i++)
		print(cir[i],'\n');
    return 0;
}
/*

17 21 6
1 2
1 3
2 3
3 5
3 4
4 6
6 5
6 8
8 7
8 9
9 10
10 11
11 9
8 12
12 13
13 14
14 12 
14 15
14 16
15 17
16 17

*/