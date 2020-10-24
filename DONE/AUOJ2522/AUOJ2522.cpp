#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define INF 0x3f3f3f3f
using namespace std;

int n,m,k,edgenum=0,cirnum=0,sum=0,ans=0,scnt=0;
int tmp1,tmp2;
int head[N],dfn[N],vis[N],low[N],cir[N];

struct Edge
{
	int v,next;
}edge[N<<2];

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
	dfn[u]=dfn[fa]+1;
	vis[u]=1;
	for (int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if (v==fa)
			continue ;
		if (vis[v])
		{
			if (dfn[v]<=dfn[u])
				cir[++cirnum]=dfn[u]-dfn[v]+1,sum+=cir[cirnum];
			continue ;
		}
		else
			dfs(v,u);
	}
}

bool cmp(int a,int b)
{
	return a>b;
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
		if (!vis[i])
		{
			dfs(i,0);
			scnt++;
		}
	sort(cir+1,cir+n+1,cmp);
	int i=1;
	if (k<=m-sum)
	{
		ans=scnt+k;
		goto print_ans;
	}
	ans=scnt+(m-sum);
	k-=(m-sum);
	while (k-cir[i]>0)
	{
		ans+=(cir[i]-1);
		k-=cir[i];
		i++;
	}
	ans+=((k>=2)?(k-1):(0));
	print_ans:;
	print(ans,'\n');
    return 0;
}
/*

10 12 5
1 2
2 3
3 4
4 1
1 5
5 6
1 6
1 10
8 9
9 10
1 7
7 8

40 48 10
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
13 18
18 19
17 20
21 22
21 23
22 23
23 25
23 24
24 26
26 25
26 28
28 27
28 29
29 30
30 31
31 29
28 32
32 33
33 34
34 32 
34 35
34 36
35 37
36 37
33 38
38 39
37 40

*/