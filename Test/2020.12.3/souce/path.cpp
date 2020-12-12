#include<bits/stdc++.h>
#define int long long
#define N 300003
#define INF 0x3f3f3f3f3f3f3f3f
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

int n,m,edgenum=0,maxn=-INF;
int tmp1,tmp2,tmp3;
int head[N];

struct Edge {
	int v,w,next;
}edge[N<<1];

void adde(int u,int v,int w) {
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
	edge[edgenum].w=w;
}

//void dfs_dp(int u,int step) {
//	for (int i=head[u];i;i=edge[i].next) {
//		int v=edge[i].v,w=edge[i].w*step;
//		if (dp[v]>=max(dp[u],w)) {
//			dp[v]=max(dp[u],w);
//			dfs_dp(v,step+1);
//		}
//	}
//}

bool dfs(int u,int step,int maxedge) {
	if (u==n)
		return true;
	for (int i=head[u];i;i=edge[i].next) {
		int v=edge[i].v,w=edge[i].w*step;
		if (w>maxedge)
			continue ;
		if (dfs(v,step+1,maxedge))
			return true;
	}
	return false;
}

bool check(int x) {
	return !dfs(1,1,x);
}

signed main() {
	freopen("path.in","r",stdin);freopen("path.out","w",stdout);
	n=input(),m=input();
	for (int i=1;i<=m;i++) {
		tmp1=input(),tmp2=input(),tmp3=input();
		maxn=max(maxn,tmp3);
		adde(tmp1,tmp2,tmp3);
	}
//	if (n<=100&&m<=100) {
//		memset(dp,0x3f,sizeof(dp));
//		dp[1]=0;
//		dfs_dp(1,1);
//		print(dp[n],'\n');
//		return 0;
//	}
	int l=1,r=maxn*m,mid;
	while (l<r) {
		mid=(l+r)>>1;
		if (check(mid))
			l=mid+1;
		else
			r=mid;
	}
	print(l,'\n');
	return 0;
}
