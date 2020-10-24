#include<bits/stdc++.h>
#define int long long
#define lson tree[x].l,l,mid
#define rson tree[x].r,mid+1,r
#define N 1111111
using namespace std;
int n,m,cnt,l,r,k;
int a[N<<4],root[N<<4];
vector<int >v;
struct lyp
{
	int l,r,val;
}tree[N<<4];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-')
			f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int adde(int x)
{
	cnt++;
	tree[cnt]=tree[x];
	return cnt;
}
int updata(int x,int l,int r,int k)
{
	int rt=adde(x);
	tree[rt].val++;
	if (l==r)
		return rt;
	int mid=(l+r)>>1;
	if (k<=mid)
		tree[rt].l=updata(lson,k);
	else
		tree[rt].r=updata(rson,k);
	return rt;
}
int query(int L,int R,int l,int r,int k)
{
	if (l==r)
		return l;
	int mid=(l+r)>>1;
	int dif=tree[tree[R].l].val-tree[tree[L].l].val;
	if (k<=dif)
		return query(tree[L].l,tree[R].l,l,mid,k);
	else
		return query(tree[L].r,tree[R].r,mid+1,r,k-dif);
}
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		v.push_back(a[i]=read());
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for (int i=1;i<=n;i++)
		root[i]=updata(root[i-1],1,n,getid(a[i]));
	for (int i=1;i<=m;i++)
	{
		l=read(),r=read(),k=read();
		printf("%lld\n",v[query(root[l-1],root[r],1,n,k)-1]);
	}
	return 0;
}