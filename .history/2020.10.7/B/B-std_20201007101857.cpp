#include<bits/stdc++.h>
#define mid (l+(r-l)/2)
#define len r-l+1
#define mod 1000000007
using namespace std;
inline int read()
{
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n,m;
int a[100011],l[100011],r[100011];
int tr[400011],add[400011],tr2[400011],add2[400011];
inline void build2(int rt,int l,int r)
{
	add2[rt]=0;
	if(l==r)
	{
		tr2[rt]=0;
		return;
	}
	else
	{
		build2(rt<<1,l,mid);
		build2(rt<<1|1,mid+1,r);
		tr2[rt]=(tr2[rt<<1]+tr2[rt<<1|1])%mod;
	}
	return;
}
inline void build(int rt,int l,int r)
{
	add[rt]=0;
	if(l==r)
	{
		tr[rt]=1;
		return;
	}
	else
	{
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		tr[rt]=(tr[rt<<1]+tr[rt<<1|1])%mod;
	}
	return;
}
inline void pushdown2(int rt,int l,int r)
{
	tr2[rt<<1]=(tr2[rt<<1]+add2[rt]*(mid-l+1))%mod;
	tr2[rt<<1|1]=(tr2[rt<<1|1]+add2[rt]*(r-mid))%mod;
	add2[rt<<1]=(add2[rt<<1]+add2[rt])%mod;
	add2[rt<<1|1]=(add2[rt<<1|1]+add2[rt])%mod;
	add2[rt]=0;
	return;
}
inline void pushdown(int rt,int l,int r)
{
	tr[rt<<1]=(tr[rt<<1]+add[rt]*(mid-l+1))%mod;
	tr[rt<<1|1]=(tr[rt<<1|1]+add[rt]*(r-mid))%mod;
	add[rt<<1]=(add[rt<<1]+add[rt])%mod;
	add[rt<<1|1]=(add[rt<<1|1]+add[rt])%mod;
	add[rt]=0;
	return;
}
inline void update2(int rt,int l,int r,int L,int R,int k)
{
	if(r<L||R<l)return;
	if(L<=l&&r<=R)
	{
		add2[rt]=(add2[rt]+k)%mod;
		tr2[rt]=(tr2[rt]+add2[rt]*len)%mod;
		return;
	}
	pushdown2(rt,l,r);
	update2(rt<<1,l,mid,L,R,k);
	update2(rt<<1|1,mid+1,r,L,R,k);
	tr2[rt]=(tr2[rt<<1]+tr2[rt<<1|1])%mod;
}
inline void update(int rt,int l,int r,int L,int R,int k)
{
	if(r<L||R<l)return;
	if(L<=l&&r<=R)
	{
		add[rt]=(add[rt]+k)%mod;
		tr[rt]=(tr[rt]+add[rt]*len)%mod;
		return;
	}
	pushdown(rt,l,r);
	update(rt<<1,l,mid,L,R,k);
	update(rt<<1|1,mid+1,r,L,R,k);
	tr[rt]=(tr[rt<<1]+tr[rt<<1|1])%mod;
}
inline int query2(int rt,int l,int r,int L,int R)
{
	if(R<l||r<L)return 0;
	if(L<=l&&r<=R)return tr2[rt];
	pushdown2(rt,l,r);
	return (query2(rt<<1,l,mid,L,R)+query2(rt<<1|1,mid+1,r,L,R))%mod;
}
inline int query(int rt,int l,int r,int L,int R)
{
	if(R<l||r<L)return 0;
	if(L<=l&&r<=R)return tr[rt];
	pushdown(rt,l,r);
	return (query(rt<<1,l,mid,L,R)+query(rt<<1|1,mid+1,r,L,R))%mod;
}
int main()
{
	n=read();m=read();
	build(1,1,m);
	build2(1,1,n);
	for(int i=1;i<=m;++i)
	{
		a[i]=read();
		l[i]=read();
		r[i]=read();
	}
	for(int i=m;i>=1;--i)
		if(a[i]==2)	
			update(1,1,m,l[i],r[i],query(1,1,n,i,i));
	for(int i=1;i<=n;++i)
		if(a[i]==1)
			update2(1,1,n,l[i],r[i],query(1,1,n,i,i));
	for(int i=1;i<=n;++i)
	printf("%d ",query2(1,1,n,i,i));
	return 0;
}
/*
5 5 
1 1 2
1 4 5
2 1 2
2 1 3
2 3 4
*/