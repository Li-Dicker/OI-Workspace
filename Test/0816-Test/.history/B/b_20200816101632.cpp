#include<bits/stdc++.h>
#define int long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define xbr int mid=(l+r)>>1;
#define N 111111
using namespace std;
int n,q,op,tmp1,tmp2,tmp3;
int a[N],tree[N<<2],lzy[N<<2];


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
	// pushdown(rt,r-l+1);
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
        }        
    }
	return 0;
}