#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn=1e5+5;
int n,m,sum[maxn<<2],lz[maxn<<2],op,x,y,z;
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

void pushdown(int k,int l,int r){
	if(!lz[k])return;
	int mid=(l+r)>>1;
	sum[k<<1]+=lz[k]*(mid-l+1);lz[k<<1]+=lz[k];
	sum[k<<1|1]+=lz[k]*(r-mid);lz[k<<1|1]+=lz[k];
	lz[k]=0;
}

void upd(int k,int l,int r,int x,int y,int v){
	if(x<=l&&y>=r){sum[k]+=v*(r-l+1),lz[k]+=v;return;}
	int mid=(l+r)>>1;
	pushdown(k,l,r);
	if(x<=mid)upd(lson,x,y,v);
	if(mid<y)upd(rson,x,y,v);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}

int query(int k,int l,int r,int x,int y){
	if(l>r||x>y)return 0;
	if(l==r){return sum[k]*(y-l+1)*(l-x+1);}
	pushdown(k,l,r);
	int mid=(l+r)>>1,res=0;
	if(x<=mid)res+=query(lson,x,y);
	if(mid<y)res+=query(rson,x,y);
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
			upd(1,1,n,x,y,z);
		}
		else{
			if(x>y){puts("0");continue;}
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
	return 0;
}
