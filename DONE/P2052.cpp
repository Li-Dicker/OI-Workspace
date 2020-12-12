#include<bits/stdc++.h>
#define int long long
#define N 11111111
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

int n,edgenum=0,ans=0;
int tmp1,tmp2,tmp3;
int head[N],sonnum[N];

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

void dfs(int u,int fa)
{
	sonnum[u]=1;
	for (int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if (v==fa)
			continue ;
		dfs(v,u);
		sonnum[u]+=sonnum[v];
		ans+=edge[i].w*abs(sonnum[v]-(n-sonnum[v]));
	}
}

signed main()
{
	n=input();
	for (int i=1;i<n;i++)
	{
		tmp1=input(),tmp2=input(),tmp3=input();
		adde(tmp1,tmp2,tmp3);
		adde(tmp2,tmp1,tmp3);
	}
	dfs(1,0);
	print(ans,'\n');
	return 0;
}