#include<bits/stdc++.h>
#define int long long
#define N 66666
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

int n,m,edgenum=0,tot=0,SUM,MAX;
char op[11];
int tmp1,tmp2;
int head[N],father[N],seg[N],rk[N],son[N],size[N],top[N],dep[N],a[N];

struct Edge
{
	int v,next;
}edge[N<<1];

void adde(int u,int v)
{
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
}

namespace Seg
{
	#define lson rt<<1,l,mid
	#define rson rt<<1|1,mid+1,r
	#define lyp int mid=(l+r)>>1;

	struct SegTree
	{
		int sum,max;
	}tree[N<<2];

	void pushup(int rt)
	{
		tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
		tree[rt].max=max(tree[rt<<1].max,tree[rt<<1|1].max);
	}

	void build(int rt,int l,int r)
	{
		if (l==r)
		{
			tree[rt].sum=tree[rt].max=a[rk[l]];
			return ;
		}
		lyp
		build(lson);
		build(rson);
		pushup(rt);
	}

	void updata(int rt,int l,int r,int k,int s)
	{
		if (l==r)
		{
			tree[rt].sum=tree[rt].max=s;
			return ;
		}
		lyp
		if (mid>=k)
			updata(lson,k,s);
		else
			updata(rson,k,s);
		pushup(rt);
	}

	void query(int rt,int l,int r,int L,int R)
	{
		if (L<=l&&r<=R)
		{
			SUM+=tree[rt].sum,MAX=max(MAX,tree[rt].max);
			return ;
		}
		lyp
		if (L<=mid)
			query(lson,L,R);
		if (R>=mid+1)
			query(rson,L,R);
	}

	#undef lson
	#undef rson
	#undef lyp
}

namespace SP
{
	void dfs1(int u,int fa)
	{
		father[u]=fa;
		dep[u]=dep[fa]+1;
		size[u]=1;
		for (int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].v;
			if (v==fa)
				continue ;
			dfs1(v,u);
			size[u]+=size[v];
			if (son[v]==-1||size[v]>size[son[u]])
				son[u]=v;
		}
	}

	void dfs2(int u,int s)
	{
		top[u]=s;
		seg[u]=++tot;
		rk[seg[u]]=u;
		if (son[u]==-1)
			return ;
		dfs2(son[u],s);
		for (int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].v;
			if (v==father[u]||v==son[u])
				continue ;
			dfs2(v,v);
		}
	}

	void updata(int x,int y)
	{
		Seg::updata(1,1,tot,seg[x],y);
	}

	void query(int x,int y)
	{
		int fx=top[x],fy=top[y];
		while (fx!=fy)
		{
			if (dep[fx]<dep[fy])
				swap(x,y),swap(fx,fy);
			Seg::query(1,1,tot,seg[fx],seg[x]);
			x=father[fx],fx=top[x];
		}
		if (dep[x]>dep[y])
			swap(x,y);
		Seg::query(1,1,tot,seg[x],seg[y]);
	}
}

void init()
{
	tot=edgenum=0;
	seg[1]=rk[1]=top[1]=1;
	memset(son,-1,sizeof(son));
}

signed main()
{
	n=input();
	init();
	for (int i=1;i<=n-1;i++)
	{
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2);
		adde(tmp2,tmp1);
	}
	for (int i=1;i<=n;i++)
		a[i]=input();
	SP::dfs1(1,0);
	SP::dfs2(1,1);
	Seg::build(1,1,tot);
	m=input();
	while (m--)
	{
		scanf("%s",op);
		tmp1=input(),tmp2=input();
		if (op[0]=='Q')
		{
			MAX=-INF,SUM=0;
			SP::query(tmp1,tmp2);
			if (op[1]=='M')
				print(MAX,'\n');
			else
				print(SUM,'\n');
		}
		else
			SP::updata(tmp1,tmp2);
	}
	return 0;
}