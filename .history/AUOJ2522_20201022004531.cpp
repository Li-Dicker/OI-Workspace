#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;

int n,m,k,edgenum=1,cirnum=0;
int tmp1,tmp2;
int head[N],cir[N];

struct Edge
{
	int v,next,vis,vis2,dfn,low;
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
	edge[edgenum].vis=0;
}

void dfs(int u,int fa,int from)
{
	for (int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if (v==fa)
			continue ;
		if (edge[i].vis)
		{
			cir[++cirnum]=edge[from].dfn-edge[i].dfn+1;
			continue ;
		}
		edge[i].vis=edge[i^1].vis=1;
		edge[i].dfn=edge[i^1].dfn=edge[from].dfn+1;
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
	for (int i=1;i<=n;i++)
	{
		if (!edge[head[i]].vis)
		{
			dfs(i,0,0);
		}
	}
	for (int i=1;i<=cirnum;i++)
		print(cir[i],'\n');
    return 0;
}