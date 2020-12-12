#include<bits/stdc++.h>
#define int long long
#define N 222222
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y1 _yy_
using namespace std;
namespace IOstream {
	#define print(a,b) prints(a),putchar(b)
	int BUF[22],BUFSIZE,IONUM,SIGN;
	char GET;
	
	inline int input() {
		IONUM=0,SIGN=1;
		GET=getchar();
		while (GET<'0'||GET>'9') {
			if (GET=='-')
				SIGN=-1;
			GET=getchar();
		}
		while (GET>='0'&&GET<='9') {
			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
			GET=getchar();
		}
		return SIGN*IONUM;
	}

	inline void prints(int IONUM) {
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

int n,m,ans=0;
int fa[N];

struct Edge {
	int u,v,w;
	bool operator < (const Edge x) const {
		return w<x.w;
	}
}edge[N<<2];

int find(int x) {
	if (x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}

void combine(int x,int y) {
	fa[find(fa[x])]=find(fa[y]);
}

void kruskal() {
	sort(edge+1,edge+m+1);
	for (int i=0;i<=n+11;i++)
		fa[i]=i;
	int cnt=0;
	for (int i=1;i<=m;i++) {
		if (cnt==n-1)
			break ;
		int u=edge[i].u,v=edge[i].v;
		if (find(fa[u])==find(fa[v]))
			continue ;
		ans+=edge[i].w;
		combine(u,v);
		cnt++;
	}
	if (cnt<n-1)
		puts("0");
	else
		print(ans,'\n');
}

signed main() {
	n=input(),m=input();
	for (int i=1;i<=m;i++)
		edge[i].u=input(),edge[i].v=input(),edge[i].w=input();
	kruskal();
	return 0;
}