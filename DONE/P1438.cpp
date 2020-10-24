#include<bits/stdc++.h>
#define int long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lyp int mid=(l+r)>>1;
#define N 111111
using namespace std;
int n,q,op,tmp1,tmp2,tmp3,tmp4,tmp5;
int tree[N<<2],lzy[N<<2],a[N];
void pushup(int rt)
{
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void pushdown(int rt,int k)
{
	if (lzy[rt]==0)
		return ;
	tree[rt<<1]+=(k-k/2)*lzy[rt];
	tree[rt<<1|1]+=(k/2)*lzy[rt];
	lzy[rt<<1]+=lzy[rt];
	lzy[rt<<1|1]+=lzy[rt];
	lzy[rt]=0;
}
void updata(int a,int b,int c,int l,int r,int rt)
{
	if (a<=l&&b>=r)
	{
		tree[rt]+=(r-l+1)*c;
		lzy[rt]+=c;
		return ;
	}
	pushdown(rt,r-l+1);
	lyp
	if (a<=mid)
		updata(a,b,c,lson);
	if (b>=mid+1)
		updata(a,b,c,rson);
	pushup(rt);
}
int query(int a,int b,int l,int r,int rt)
{
	if (a<=l&&b>=r)
		return tree[rt];
	pushdown(rt,r-l+1);
	lyp
	int res=0;
	if (a<=mid)
		res+=query(a,b,lson);
	if (b>=mid+1)
		res+=query(a,b,rson);
	return res;
}
signed main()
{
	scanf("%lld %lld",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	while (q--)
	{
		scanf("%lld %lld",&op,&tmp1);
		if (op==1)
		{
			scanf("%lld %lld %lld",&tmp2,&tmp3,&tmp4);
			updata(tmp1,tmp1,tmp3,1,n,1);
			updata(tmp1+1,tmp2,tmp4,1,n,1);
			tmp5=tmp2-tmp1+1;
			if (tmp5!=n)
				updata(tmp2+1,tmp2+1,-(tmp3+(tmp5-1)*tmp4),1,n,1);
		}
		else if (op==2)
			printf("%lld\n",a[tmp1]+query(1,tmp1,1,n,1));
	}
	return 0;
}