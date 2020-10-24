#include<bits/stdc++.h>
#define int long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lyp int mid=(l+r)>>1;
#define N 111111
using namespace std;
int n,q,op,tmp1,tmp2;
double tmp3,ans=0;
double a[N],sum1[N<<2],sum2[N<<2],lzy1[N<<2],lzy2[N<<2];
void pushup(int rt)
{
	sum1[rt]=sum1[rt<<1]+sum1[rt<<1|1];
	sum2[rt]=sum2[rt<<1]+sum2[rt<<1|1];
}
void pushdown(int rt,int k)
{
	if (lzy1[rt]==0&&lzy2[rt]==0)
		return ;
	lzy2[rt<<1]+=lzy2[rt];
	sum2[rt<<1]+=sum1[rt<<1]*(2*lzy2[rt])+(k-k/2)*(lzy2[rt]*lzy2[rt]);
	lzy2[rt<<1|1]+=lzy2[rt];
	sum2[rt<<1|1]+=sum1[rt<<1|1]*(2*lzy2[rt])+(k/2)*(lzy2[rt]*lzy2[rt]);
	lzy2[rt]=0;
	lzy1[rt<<1]+=lzy1[rt];
	sum1[rt<<1]+=(k-k/2)*lzy1[rt];
	lzy1[rt<<1|1]+=lzy1[rt];
	sum1[rt<<1|1]+=(k/2)*lzy1[rt];
	lzy1[rt]=0;
}
void build(int l,int r,int rt)
{
	sum1[rt]=sum2[rt]=0;
	if (l==r)
	{
		sum1[rt]=a[l];
		sum2[rt]=a[l]*a[l];
		return ;
	}
	lyp
	build(lson);
	build(rson);
	pushup(rt);
}
void updata(int a,int b,double c,int l,int r,int rt)
{
	if (a<=l&&b>=r)
	{
		lzy2[rt]+=c;
		sum2[rt]+=sum1[rt]*(2*c)+(r-l+1)*(c*c);
		lzy1[rt]+=c;
		sum1[rt]+=c*(r-l+1);
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
double query1(int a,int b,int l,int r,int rt)
{
	if (a<=l&&b>=r)
		return sum1[rt];
	pushdown(rt,r-l+1);
	lyp
	double res=0;
	if (a<=mid)
		res+=query1(a,b,lson);
	if (b>=mid+1)
		res+=query1(a,b,rson);
	return res;
}
double query2(int a,int b,int l,int r,int rt)
{
	if (a<=l&&b>=r)
		return sum2[rt];
	pushdown(rt,r-l+1);
	lyp
	double res=0;
	if (a<=mid)
		res+=query2(a,b,lson);
	if (b>=mid+1)
		res+=query2(a,b,rson);
	return res;
}
double pf(double a)
{
	return a*a;
}
signed main()
{
	scanf("%lld %lld",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	memset(lzy1,0,sizeof(lzy1));
	memset(lzy2,0,sizeof(lzy2));
	build(1,n,1);
	while (q--)
	{
		scanf("%lld %lld %lld",&op,&tmp1,&tmp2);
		if (op==1)
		{
			scanf("%lf",&tmp3);
			updata(tmp1,tmp2,tmp3,1,n,1);
		}
		else if (op==2)
		{
			ans=query1(tmp1,tmp2,1,n,1)/(tmp2-tmp1+1);
			printf("%.4lf\n",ans);
		}
		else if (op==3)
		{
			ans=query2(tmp1,tmp2,1,n,1)/(tmp2-tmp1+1)-pf(query1(tmp1,tmp2,1,n,1)/n);
			printf("%.4lf\n",ans);
		}
	}
	return 0;
}