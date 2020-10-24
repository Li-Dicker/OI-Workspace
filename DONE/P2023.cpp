#include<bits/stdc++.h>
#define int long long
#define N 111111
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lyp int mid=(l+r)>>1;
using namespace std;
int n,q,MOD,op,tmp1,tmp2,tmp3;
int a[N],sum[N<<2],lzy_add[N<<2],lzy_mul[N<<2];
void pushup(int rt)
{
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%MOD;
}
void build(int l,int r,int rt)
{
	lzy_add[rt]=0;
	lzy_mul[rt]=1;
	if (l==r)
	{
		sum[rt]=a[l];
		return;
	}
	lyp
	build(lson);
	build(rson);
	pushup(rt);
}
void pushdown_mul(int rt,int k)
{
	if (lzy_mul[rt]==1)
		return ;
	lzy_mul[rt<<1]=(lzy_mul[rt<<1]*lzy_mul[rt])%MOD;
	lzy_mul[rt<<1|1]=(lzy_mul[rt<<1|1]*lzy_mul[rt])%MOD;
	lzy_add[rt<<1]=(lzy_add[rt<<1]*lzy_mul[rt])%MOD;
	lzy_add[rt<<1|1]=(lzy_add[rt<<1|1]*lzy_mul[rt])%MOD;
	sum[rt<<1]=(sum[rt<<1]*lzy_mul[rt])%MOD;
	sum[rt<<1|1]=(sum[rt<<1|1]*lzy_mul[rt])%MOD;
	lzy_mul[rt]=1;
}
void pushdown_add(int rt,int k)
{
	if (lzy_add[rt]==0)
		return ;
	lzy_add[rt<<1]=(lzy_add[rt<<1]+lzy_add[rt])%MOD;
	lzy_add[rt<<1|1]=(lzy_add[rt<<1|1]+lzy_add[rt])%MOD;
	sum[rt<<1]=(sum[rt<<1]+(k-k/2)*lzy_add[rt]%MOD)%MOD;
	sum[rt<<1|1]=(sum[rt<<1|1]+(k/2)*lzy_add[rt]%MOD)%MOD;
	lzy_add[rt]=0;
}
void updata_mul(int a,int b,int c,int l,int r,int rt)
{
	if (a<=l&&b>=r)
	{
		lzy_add[rt]=(lzy_add[rt]*c)%MOD;
		lzy_mul[rt]=(lzy_mul[rt]*c)%MOD;
		sum[rt]=(sum[rt]*c)%MOD;
		return ;
	}
	pushdown_mul(rt,r-l+1);
	pushdown_add(rt,r-l+1);
	lyp
	if (a<=mid)
		updata_mul(a,b,c,lson);
	if (b>=mid+1)
		updata_mul(a,b,c,rson);
	pushup(rt);
}
void updata_add(int a,int b,int c,int l,int r,int rt)
{
	if (a<=l&&b>=r)
	{
		lzy_add[rt]=(lzy_add[rt]+c)%MOD;
		sum[rt]=(sum[rt]+(r-l+1)*c%MOD)%MOD;
		return ;
	}
	pushdown_mul(rt,r-l+1);
	pushdown_add(rt,r-l+1);
	lyp
	if (a<=mid)
		updata_add(a,b,c,lson);
	if (b>=mid+1)
		updata_add(a,b,c,rson);
	pushup(rt);
}
int query(int a,int b,int l,int r,int rt)
{
	if (a<=l&&b>=r)
	  return sum[rt];
	pushdown_mul(rt,r-l+1);
	pushdown_add(rt,r-l+1);
	int res=0;
	lyp
	if (a<=mid) 
		res=(res+query(a,b,lson))%MOD;
	if (b>=mid+1)
		res=(res+query(a,b,rson))%MOD;
	return res;
}
signed main()
{
	scanf("%lld %lld",&n,&MOD);//输入元素个数，模数
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);//输入元素
	scanf("%lld",&q);//输入操作数
	build(1,n,1);//建树
	while (q--)
	{
		scanf("%lld %lld %lld",&op,&tmp1,&tmp2);
		if (op==1)
		{
			scanf("%lld",&tmp3);
			updata_mul(tmp1,tmp2,tmp3,1,n,1);
		}
		else if (op==2)
		{
			scanf("%lld",&tmp3);
			updata_add(tmp1,tmp2,tmp3,1,n,1);
		}
		else if (op==3)
			printf("%lld\n",query(tmp1,tmp2,1,n,1));
	}
	return 0;
}