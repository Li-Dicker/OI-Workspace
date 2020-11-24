#include<bits/stdc++.h>
#define int long long
#define N 6666
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

int n,m,ans=0,cnt=0;
int fa[N];

struct Edge
{
	int u,v,w;
}edge[N*N];

bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}

int find(int x)
{
	if (x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}

void kruskal()
{
	sort(edge+1,edge+m+1,cmp);
	for (int i=0;i<=n+1;i++)
		fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if (fu==fv)
			continue ;
		ans+=edge[i].w;
		cnt++;
		fa[fu]=fv;
		if (cnt==n-1)
			break ;
	}
	if (cnt<n-1)
		puts("orz");
	else
		print(ans,'\n');
}

signed main()
{
	n=input(),m=input();
	for (int i=1;i<=m;i++)
		edge[i].u=input(),edge[i].v=input(),edge[i].w=input();
	kruskal();
	return 0;
}