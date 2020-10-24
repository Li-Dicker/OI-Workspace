#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn=1e5+5;
int n,m,sum[maxn<<2],lz[maxn<<2],op,x,y,z;
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

// void pushdown(int k,int l,int r){
// 	if(!lz[k])return;
// 	int mid=(l+r)>>1;
// 	sum[k<<1]+=lz[k]*(mid-l+1);lz[k<<1]+=lz[k];
// 	sum[k<<1|1]+=lz[k]*(r-mid);lz[k<<1|1]+=lz[k];
// 	lz[k]=0;
// }

// void upd(int k,int l,int r,int x,int y,int v){
// 	if(x<=l&&y>=r){sum[k]+=v*(r-l+1),lz[k]+=v;return;}
// 	int mid=(l+r)>>1;
// 	if(x<=mid)upd(lson,x,y,v);
// 	if(mid<y)upd(rson,x,y,v);
// 	sum[k]=sum[k<<1]+sum[k<<1|1];
// }

// int query(int k,int l,int r,int x,int y){
// 	if(l>r||x>y)return 0;
// 	if(x<=l&&y>=r){return sum[k];}
// 	pushdown(k,l,r);
// 	int mid=(l+r)>>1,res=0;
// 	if(x<=mid)res+=query(lson,x,y);
// 	if(mid<y)res+=query(rson,x,y);
// 	return res;
// }


#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define xbr int mid=(l+r)>>1;

void pushup(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt,int k)
{
	if (lz[rt]==0)
		return ;
	sum[rt<<1]+=lz[rt]*(k-k/2);
	sum[rt<<1|1]+=lz[rt]*(k/2);
	lz[rt<<1]+=lz[rt];
	lz[rt<<1|1]+=lz[rt];
	lz[rt]=0;
}

void build(int l,int r,int rt)
{
	lz[rt]=0;
	if (l==r)
	{
		sum[rt]=0;
		return ;
	}
	xbr
	build(lson);
	build(rson);
	pushup(rt);
}

void updata(int rt,int l,int r,int a,int b,int c)
{
	if (a<=l&&b>=r)
	{
		sum[rt]+=(r-l+1)*c;
		lz[rt]+=c;
		return ;
	}
	pushdown(rt,r-l+1);
	xbr
	if (a<=mid)
		updata(a,b,c,lson);
	if (b>=mid+1)
		updata(a,b,c,rson);
	pushup(rt);
}

int query(int rt,int l,int r,int a,int b)
{
	if (a<=l&&b>=r)
		return sum[rt];
	pushdown(rt,r-l+1);
	xbr
	int res=0;
	if (a<=mid)
		res+=query(a,b,lson);
	if (b>=mid+1)
		res+=query(a,b,rson);
	return res;
}

signed main(){
	freopen("b.in","r",stdin);
	freopen("b1.out","w",stdout);
	scanf("%lld%lld",&n,&m);n--;
	while(m--){
		scanf("%lld%lld%lld",&op,&x,&y);y--;
		if(op==1){
			scanf("%lld",&z);
			if(x>y)continue;
			updata(1,1,n,x,y,z);
		}
		else{
			if(x>y){puts("0");continue;}
			printf("%lld\n",query(1,1,n,x+1,y-1)*(1<<(y-x))+(x==y?query(1,1,n,x,x):(query(1,1,n,x,x)+query(1,1,n,y,y)))*(y-x+1));
		}
	}
	return 0;
}