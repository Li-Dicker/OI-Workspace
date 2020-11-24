#include<bits/stdc++.h>
#define int long long
#define N 1111111
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

int n,m,root,edgenum=0,dfs_clock=0;
int op,tmp1,tmp2;
int head[N],val[N],dfn[N],size[N];

struct Edge {
	int v,next;
}edge[N<<1];

void adde(int u,int v) {
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
}

namespace Tree {

	int tree[N<<2];

	int lowbit(int x) {
		return x&(-x);
	}

	void updata(int x,int y) {
		for (int i=x;i<=n;i+=lowbit(i))
			tree[i]+=y;
	}

	int query(int x) {
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))
			res+=tree[i];
		return res;
	}
}
using namespace Tree;

void dfs(int u,int fa) {
	dfn[u]=++dfs_clock;
	size[u]=1;
	for (int i=head[u];i;i=edge[i].next) {
		int v=edge[i].v;
		if (v==fa)
			continue ;
		dfs(v,u);
		size[u]+=size[v];
	}
}

signed main() {
	n=input(),m=input(),root=input();
	for (int i=1;i<=n;i++)
		val[i]=input();
	for (int i=1;i<n;i++) {
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2);
		adde(tmp2,tmp1);
	}
	dfs(root,0);
	for (int i=1;i<=n;i++)
		updata(dfn[i],val[i]);
	while (m--) {
		op=input(),tmp1=input();
		if (op==1) {
			tmp2=input();
			updata(dfn[tmp1],tmp2);
		}
		else 
			print(query(dfn[tmp1]+size[tmp1]-1)-query(dfn[tmp1]-1),'\n');
	}
	return 0;
}