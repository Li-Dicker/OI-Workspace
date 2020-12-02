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

int n,edgenum=0,ans=0;
int tmp1,tmp2;
int head[N],father[N],a[N],size[N];

struct Edge {
	int v,next;
}edge[N<<1];

void adde(int u,int v) {
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
}

void dfs_pre(int u,int fa) {
	size[u]=a[u],father[u]=fa;
	for (int i=head[u];i;i=edge[i].next) {
		int v=edge[i].v;
		if (v==fa)
			continue ;
		dfs_pre(v,u);
		size[u]+=size[v];
	}
}

void dfs(int u,int fa) {
	int x=fa;
	while (x) {
		if ((a[x]^a[u])==size[x]-size[u])
			ans++;
		if (size[x]-size[u]>a[x]+a[u])
			break ;
		x=father[x];
	}
	for (int i=head[u];i;i=edge[i].next) {
		int v=edge[i].v;
		if (v==fa)
			continue ;
		dfs(v,u);
	}
}


signed main() {
	// freopen("cactus.in","r",stdin);freopen("cactus.out","w",stdout);
	n=input();
	for (int i=1;i<=n;i++)
		a[i]=input();
	for (int i=1;i<n;i++) {
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2);
		adde(tmp2,tmp1);
	}
	dfs_pre(1,0);
	// for (int i=1;i<=n;i++) {
	// 	int x=father[i];
	// 	while (x) {
	// 		if (x==0)
	// 			break ;
	// 		if((a[x]^a[i])==size[x]-size[i])
	// 			ans++;
	// 		x=father[x];
	// 	}
	// }
	dfs(1,0);
	print(ans,'\n');
	return 0;
}
/*
5
1 3 6 2 1
1 5
1 2
2 3
2 4
*/
