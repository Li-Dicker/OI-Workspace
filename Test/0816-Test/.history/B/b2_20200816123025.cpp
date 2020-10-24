#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100012
using namespace std;
struct node
{
	int l,r;
	long long w,sum,sum2,lzy;
	void operator=(const node &b)
	{
		l=b.l;
		r=b.r;
		w=b.w;
		sum=b.sum;
		sum2=b.sum2;
	}
};
struct segtree
{
	node tr[N*4];
	void up(int l,int r,int rt)
	{
		int m=(l+r)>>1,sizl,sizr;
		sizl=m-l+1;sizr=r-m;
		tr[rt].sum=tr[rt<<1].sum+tr[rt<<1|1].sum;
		tr[rt].sum2=tr[rt<<1].sum2+tr[rt<<1|1].sum2+tr[rt<<1].sum*sizr;
		tr[rt].w=tr[rt<<1].w+tr[rt<<1|1].w+sizl*(tr[rt<<1|1].sum2+tr[rt<<1].sum*sizr)-(tr[rt<<1].sum2-tr[rt<<1].sum)*sizr;
	}
	void down(int l,int r,int rt)
	{
		int m=(l+r)>>1,sizl,sizr,c;
		sizl=m-l+1;sizr=r-m;c=tr[rt].lzy;
		tr[rt<<1].sum+=sizl*c;
		tr[rt<<1].sum2+=c*sizl*(sizl+1)/2;
		tr[rt<<1].w+=c*(sizl*sizl*(sizl+1)/2-(sizl-1)*sizl*(sizl+1)/3);
		tr[rt<<1].lzy+=c;

		tr[rt<<1|1].sum+=sizr*c;
		tr[rt<<1|1].sum2+=c*sizr*(sizr+1)/2;
		tr[rt<<1|1].w+=c*(sizr*sizr*(sizr+1)/2-(sizr-1)*sizr*(sizr+1)/3);
		tr[rt<<1|1].lzy+=c;
		tr[rt].lzy=0;
	}
	void mk(int rt)
	{
		int l=tr[rt].l,r=tr[rt].r,m=(tr[rt].l+tr[rt].r)>>1;
		if(l==r)
		{
			tr[rt].w=0;
			tr[rt].lzy=0;
			return;
		}
		tr[rt<<1].l=l;tr[rt<<1].r=m;mk(rt<<1);
		tr[rt<<1|1].l=m+1;tr[rt<<1|1].r=r;mk(rt<<1|1);
		return;
	}
	void add(int a,int b,long long c,int rt)
	{
		int l=tr[rt].l,r=tr[rt].r,m=(tr[rt].l+tr[rt].r)>>1,siz;
		siz=r-l+1;
		if(a<=l&&b>=r)
		{
			tr[rt].sum+=(r-l+1)*c;
			tr[rt].sum2+=siz*(siz+1)/2*c;
			tr[rt].w+=c*(siz*siz*(siz+1)/2-(siz-1)*siz*(siz+1)/3);
			tr[rt].lzy+=c;
			return;
		}
		if(tr[rt].lzy)down(l,r,rt);
		if(a<=m)add(a,b,c,rt<<1);
		if(b>m)add(a,b,c,rt<<1|1);
		up(l,r,rt);
	}
	node que(int a,int b,int rt)
	{
		int l=tr[rt].l,r=tr[rt].r,m=(tr[rt].l+tr[rt].r)>>1;
		node lans,rans,ans;
		if(a<=l&&b>=r)return tr[rt];
		if(tr[rt].lzy)down(l,r,rt);
		if(a<=m&&b>m)
		{
			lans=que(a,b,rt<<1);
			rans=que(a,b,rt<<1|1);
			int sizl=lans.r-lans.l+1,sizr=rans.r-rans.l+1;
			ans.l=lans.l;ans.r=rans.r;
			ans.sum=lans.sum+rans.sum;
			ans.sum2=lans.sum2+rans.sum2+lans.sum*sizr;
			ans.w=lans.w+rans.w+sizl*(rans.sum2+lans.sum*sizr-lans.sum2+lans.sum);
			return ans;
		}
		if(a<=m)
			return que(a,b,rt<<1);
		if(b>m)
			return que(a,b,rt<<1|1);
		return ans;
	}
}tree;
int main()
{
freopen("b.in","r",stdin);
freopen("b1.out","w",stdout);
	
	int i,n,m,type,a,b;
	long long c;
	scanf("%d %d",&n,&m);
	tree.tr[1].l=1;tree.tr[1].r=n-1;tree.mk(1);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d %d %lld",&a,&b,&c);
			tree.add(a,b-1,c,1);
		}
		else
		{
			scanf("%d %d",&a,&b);
			printf("%lld\n",tree.que(a,b-1,1).w);
		}
	}
	return 0;
}
/*
4 5
1 1 4 2
1 1 2 -1
2 1 2
2 2 4
2 1 4
*/
