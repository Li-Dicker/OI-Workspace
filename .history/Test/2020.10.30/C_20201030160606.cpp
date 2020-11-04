#include<bits/stdc++.h>
#define int long long
#define N 100003
#define INF 0x3f3f3f3f
#define MOD ((int )1e9+7)
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

int T,m,n;
struct Bags
{
	int val,id,rk;
}a[N<<2];

struct SegTree
{
	int val,cnt;
}tree[N<<4];

namespace cmp
{
	bool cmpw(Bags a,Bags b)
	{
		return a.val<=b.val;
	}
	
	bool cmpid(Bags a,Bags b)
	{
		return a.id<=b.id;
	}
}

namespace Seg
{
	#define lson rt<<1,l,mid
	#define rson rt<<1|1,mid+1,r
	#define lyp int mid=(l+r)>>1;
	
	void pushup(int rt)
	{
		tree[rt].val=tree[rt<<1].val+tree[rt<<1|1].val;
		tree[rt].cnt=tree[rt<<1].cnt+tree[rt<<1|1].cnt;
	}
	
	void build(int rt,int l,int r)
	{
		tree[rt].val=tree[rt].cnt=0;
		if (l==r)
			return ;
		lyp
		build(lson);
		build(rson);
		pushup(rt);
	}
	
	void updata(int rt,int l,int r,int k,int s)
	{
		if (l==r)
		{
			tree[rt].val+=s;
			tree[rt].cnt++;
			return ;
		}
		lyp
		if (k<=mid)
			updata(lson,k,s);
		if (mid<k)
			updata(rson,k,s);
		pushup(rt);
	}
	
	int query(int rt,int l,int r,int s)
	{
		if (l==r)
			return tree[rt].val<=s?tree[rt].cnt:0;
		lyp
		if (tree[rt<<1].val>=s)
			return query(lson,s);
		else
			return tree[rt<<1].cnt+query(rson,s-tree[rt<<1].val);
	}
}

signed main()
{
//	freopen("gohome.in","r",stdin);freopen("gohome.out","w",stdout);
	T=input();
	while (T--)
	{
		n=input(),m=input();
		for (int i=1;i<=n;i++)
			a[i].val=input(),a[i].id=i;
		sort(a+1,a+n+1,cmp::cmpw);
		for (int i=1;i<=n;i++)
			a[i].rk=i;
		sort(a+1,a+n+1,cmp::cmpid);
		Seg::build(1,1,n);
		for (int i=1;i<=n;i++)
		{
			print(i-Seg::query(1,1,n,m-a[i].val)-1,' ');
			Seg::updata(1,1,n,a[i].rk,a[i].val);
		}
		puts("");
	}
    return 0;
}