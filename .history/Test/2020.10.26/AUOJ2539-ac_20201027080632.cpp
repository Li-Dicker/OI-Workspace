#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
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

int n,head_max,head_min,ans=0;
int sta_max[N],sta_min[N];
map<int ,int>last;

class Seg_Tree
{
	#define lson rt<<1,l,mid
	#define rson rt<<1|1,mid+1,r
	#define lyp int mid=(l+r)>>1;
	private:
	
	struct tree
	{
		int l,r,minn,val,lzy;
	}tree[N<<2];

	void doit(int rt,int s)
	{
		tree[rt].minn+=s;
		tree[rt].lzy+=s;
	}

	void pushup(int rt)
	{
		tree[rt].minn=min(tree[rt<<1].minn,tree[rt<<1|1].minn);
		tree[rt].val=((tree[rt].minn==tree[rt<<1].minn)?tree[rt<<1].val:0)+((tree[rt].minn,tree[rt<<1|1].minn)?tree[rt].val:tree[rt].0);
	}

	void build(int rt,int l,int r)
	{
		tree[rt].l=l,tree[rt].r=r,tree[rt].val=r-l+1;
		if (l==r)
			return ;
		lyp
		build(lson);
		build(rson);
	}

	void pushdown(int rt)
	{
		if (!tree[rt].lzy)
			return ;
		doit(rt<<1,tree[rt].lzy);
		doit(rt<<1|1,tree[rt].lzy);
		tree[rt].lzy=0;
	}

	void updata(int rt,int l,int r,int L,int R,int s)
	{
		if (L>r||R<l)
			return ;
		if (L<=l&&r>R)
			return doit(rt,s);
		pushdown(rt);
		lyp
		updata(lson,L,R,s);
		updata(rson,L,R,s);
		pushup(rt);
	}
}tree;

signed main()
{
	
	return 0;
}