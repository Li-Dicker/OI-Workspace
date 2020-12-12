#include<bits/stdc++.h>
#define int long long
#define N 111111
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

int n,m,ans1,ans2,edgenum=0,top=0;
int tmp1,tmp2;
int head[N],s[N],f[N],g[N],vis[N],w[N];
int h[N][3];

struct E{
	int v,next;
}edge[N<<1];

void adde(int u,int v) {
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
}

void dfs(int u) {
	bool flag=0;
	for (int i=head[u];i;i=edge[i].next) {
		int v=edge[i].v;
		if (vis[v])
			continue ;
		flag=1;
		vis[v]=1;
		s[++top]=v;
		dfs(v);
		vis[v]=0;
		top--;
	}
	if (!flag) {
		f[0]=g[top+1]=0;
		h[0][0]=h[top+1][1]=0;
		int res1=0,res2=0;
		for (int i=1;i<=top;i++) {
			f[i]=max(f[i-1]+w[s[i]],w[s[i]]);
			h[i][0]=max(h[i-1][0],f[i]);
		}
		for (int i=top;i;i--) {
			g[i]=max(g[i+1]+w[s[i]],w[s[i]]);
			h[i][1]=max(h[i+1][1],g[i]);
		}
		for (int i=1;i<=top;i++)
			if(h[i][0]>res1)
				res1=h[i][0],res2=h[i+1][1];
			else if(h[i][0]==res1)
				res2=max(res2,h[i+1][1]);
		for (int i=top;i;i--)
			if (h[i][1]>res1)
				res1=h[i][1],res2=h[i-1][0];
			else if (h[i][1]==res1)
				res2=max(res2,h[i-1][0]);
		if (res1>ans1)
			ans1=res1,ans2=res2;
	}
}

signed main() {
	freopen("necklace.in","r",stdin);freopen("necklace.out","w",stdout);
	n=input(),m=input();
	for (int i=1;i<=n;i++)
		w[i]=input();
	for (int i=1;i<=m;i++) {
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2);
	}
	for (int i=1;i<=n;i++) {
		vis[i]=1;
		s[++top]=i;
		dfs(i);
		vis[i]=0;
		top--;
	}
	print(ans1,' '),print(ans2,'\n');
	return 0;
}
