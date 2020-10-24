#include<bits/stdc++.h>
#define int long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lyp int mid=(l+r)>>1;
#define N 222222
using namespace std;
int n,q,op,tmp1,tmp2;
int tree[N<<4],lzy[N<<4],a[N];
char c;
void pushup(int rt)
{
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void pushdown(int rt,int k)
{
	if (lzy[rt]==0)
		return ;
	tree[rt<<1]=(k-k/2)-tree[rt<<1];
	tree[rt<<1|1]=(k/2)-tree[rt<<1|1];
	lzy[rt<<1]^=1;
	lzy[rt<<1|1]^=1;
	lzy[rt]=0;
}
void build(int l,int r,int rt)
{
	if (l==r)
	{
		tree[rt]=a[l];
		return ;
	}
	lyp
	build(lson);
	build(rson);
	pushup(rt);
}
void updata(int a,int b,int l,int r,int rt)
{
	if (a<=l&&b>=r)
	{
		tree[rt]=(r-l+1-tree[rt]);
		lzy[rt]^=1;
		return ;
	}
	pushdown(rt,r-l+1);
	lyp
	if (a<=mid)
		updata(a,b,lson);
	if (b>=mid+1)
		updata(a,b,rson);
	pushup(rt);
}
int query(int a,int b,int l,int r,int rt)
{
	if (a<=l&&b>=r)
		return tree[rt];
	pushdown(rt,r-l+1);
	int res=0;
	lyp
	if (a<=mid)
		res+=query(a,b,lson);
	if (b>=mid+1)
		res+=query(a,b,rson);
	return res;
}
signed main()
{
	scanf("%lld %lld\n",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%c",&c);
		if (c=='0')
			a[i]=0;
		else if (c=='1')
			a[i]=1;
	}
	build(1,n,1);
	while (q--)
	{
		scanf("%lld %lld %lld",&op,&tmp1,&tmp2);
		if (op==0)
			updata(tmp1,tmp2,1,n,1);
		else if (op==1)
			printf("%lld\n",query(tmp1,tmp2,1,n,1));
	}
	return 0;
}