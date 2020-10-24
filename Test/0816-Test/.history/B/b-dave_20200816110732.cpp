// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// const int maxn=1e5+5;
// int n,m,sum[maxn<<2],lz[maxn<<2],op,x,y,z;
// #define lson k<<1,l,mid
// #define rson k<<1|1,mid+1,r

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

// signed main(){
// 	freopen("b.in","r",stdin);
// 	freopen("b1.out","w",stdout);
// 	scanf("%lld%lld",&n,&m);n--;
// 	while(m--){
// 		scanf("%lld%lld%lld",&op,&x,&y);y--;
// 		if(op==1){
// 			scanf("%lld",&z);
// 			if(x>y)continue;
// 			upd(1,1,n,x,y,z);
// 		}
// 		else{
// 			if(x>y){puts("0");continue;}
// 			printf("%lld\n",query(1,1,n,x+1,y-1)*(1<<(y-x))+(x==y?query(1,1,n,x,x):(query(1,1,n,x,x)+query(1,1,n,y,y)))*(y-x+1));
// 		}
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
#define int long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define xbr int mid=(l+r)>>1;
#define N 111111
using namespace std;
int n,q,op,tmp1,tmp2,tmp3;
int tree[N<<2],lzy[N<<2];


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

void pushup(int rt)
{
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

void pushdown(int rt,int k)
{
	if (lzy[rt]==0)
		return ;
	tree[rt<<1]+=lzy[rt]*(k-k/2);
	tree[rt<<1|1]+=lzy[rt]*(k/2);
	lzy[rt<<1]+=lzy[rt];
	lzy[rt<<1|1]+=lzy[rt];
	lzy[rt]=0;
}

void build(int l,int r,int rt)
{
	lzy[rt]=0;
	if (l==r)
	{
		tree[rt]=0;
		return ;
	}
	xbr
	build(lson);
	build(rson);
	pushup(rt);
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
	xbr
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
	xbr
	int res=0;
	if (a<=mid)
		res+=query(a,b,lson);
	if (b>=mid+1)
		res+=query(a,b,rson);
	return res;
}

signed main()
{
    freopen("b.in","r",stdin);freopen("b1.out","w",stdout);
    n=input()-1,q=input();
	build(1,n,1);
    while (q--)
    {
        op=input(),tmp1=input(),tmp2=input()-1;
        if (op==1)
        {
            tmp3=input();
            if (tmp2>=tmp1)
                updata(tmp1,tmp2,tmp3,1,n,1);
        }
        else
        {
            if (tmp2>=tmp1)
                print(query(tmp1+1,tmp2-1,1,n,1)*(1<<(tmp2-tmp1))+(query(tmp1,tmp1,1,n,1)+(tmp1!=tmp2)*query(tmp2,tmp2,1,n,1))*(tmp2-tmp1+1),'\n');
            else
                print(0,'\n');
        }        
    }
	return 0;
}