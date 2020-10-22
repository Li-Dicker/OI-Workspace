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
		dfs(v,u,i);
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
	edge[1].dfn=0;
	for (int i=1;i<=n;i++)
	{
		if (!edge[head[i]].vis)
		{
			dfs(i,0,1);
		}
	}
	for (int i=1;i<=cirnum;i++)
		print(cir[i],'\n');
	/*
		错误。
		简单的例子，下面的样例中从14->16->17->15->14之后，from边是15->14这一条，然后就会走到14->12，出现奇怪的错误，暂时无法解决，所以无法完全在边上进行判断
	*/
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