#include<bits/stdc++.h>
#define int long long
#define N 111111
#define M 1111
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;

int n,q;
int op,tmp1,tmp2;
int sum[M][M];
struct operation
{
	int op,l,r;
}opt[N];

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

class Seg_Tree
{
	#define lson rt<<1,l,mid
	#define rson rt<<1|1,mid+1,r
	private:

	int val[N],lzy[N];

	void pushup(int rt)
	{
		val[rt]=val[rt<1]+val[rt<<1|1];
	}

	void pushdown(int rt,int l,int r)
	{
		int mid=(l+r)>>1;
		val[rt<<1]=(val[rt<<1]+lzy[rt]*(mid-l+1))%MOD;
		val[rt<<1|1]=(val[rt<<1|1]+lzy[rt]*(r-mid))%MOD;
		lzy[rt<<1]=(lzy[rt<<1]+lzy[rt])%MOD;
		lzy[rt<<1|1]=(lzy[rt<<1|1]+lzy[rt])%MOD;
		lzy[rt]=0;
	}

	public:

	void build(int rt,int l,int r,int init)
	{
		lzy[rt]=0;
		if (l==r)
		{
			val[rt]=init;
			return ;
		}
		int mid=(l+r)>>1;
		build(lson,init);
		build(rson,init);
		pushup(rt);
	}

	void updata(int rt,int l,int r,int L,int R,int k)
	{
		if (r<L||R<l)
			return ;
		if (L<=l&&r<=R)
		{
			lzy[rt]=(lzy[rt]+k)%MOD;
			val[rt]=(val[rt]+lzy[rt]*(r-l+1))%MOD;
			return ;
		}
		int mid=(l+r)>>1;
		pushdown(rt,l,r);
		updata(lson,L,R,k);
		updata(rson,L,R,k);
		pushup(rt);
	}

	int query(int rt,int l,int r,int L,int R)
	{
		if (r<L||R<l)
			return 0;
		if (L<=l&&r<=R)
			return val[rt];
		pushdown(rt,l,r);
		int mid=(l+r)>>1;
		return (query(lson,L,R)+query(rson,L,R))%MOD;
	}

}Tree1,Tree2;

signed main()
{
	n=input(),q=input();
	for (int i=1;i<=q;i++)
		opt[i].op=input(),opt[i].l=input(),opt[i].r=input();
	if (n<=1000&&q<=1000)
	{
		for (int i=1;i<=n;i++)
			sum[0][i]=0;
		for (int i=1;i<=q;i++)
		{
			op=opt[i].op,tmp1=opt[i].l,tmp2=opt[i].r;
			if (op==1)
			{
				for (int j=1;j<tmp1;j++)
					sum[i][j]=sum[i-1][j];
				for (int j=tmp1;j<=tmp2;j++)
					sum[i][j]=(sum[i-1][j]+1)%MOD;
				for (int j=tmp2+1;j<=n;j++)
					sum[i][j]=sum[i-1][j];
			}
			else if (op==2)
			{
				for (int j=1;j<=n;j++)
					sum[i][j]=(sum[i-1][j]+sum[tmp2][j]-sum[tmp1-1][j])%MOD;
			}
		}
		for (int i=1;i<=n;i++)
			print(sum[q][i]%MOD,' ');
		puts("");
		return 0;
	}
	Tree1.build(1,1,q,1);
	Tree2.build(1,1,n,0);
	for (int i=q;i>=1;i--)
		if (opt[i].op==2)
			Tree1.updata(1,1,q,opt[i].l,opt[i].r,Tree1.query(1,1,q,i,i));
	for (int i=1;i<=q;i++)
		if (opt[i].op==1)
			Tree2.updata(1,1,n,opt[i].l,opt[i].r,Tree1.query(1,1,q,i,i));
	for (int i=1;i<=n;i++)
		print(Tree2.query(1,1,n,i,i)%MOD,' ');
	return 0;
}
/*
5 5
1 1 2
1 4 5
2 1 2
2 1 3
2 3 4
*/他就买了玻璃罐装的/xk