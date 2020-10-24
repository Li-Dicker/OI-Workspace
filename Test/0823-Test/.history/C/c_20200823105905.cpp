#include<bits/stdc++.h>
using namespace std;
int n,m,s,k,v,tmp1,tmp2;
int a[555555],head[555555],d[555555];
int f[555555][22];
struct lyp
{
	int v,next;
}edge[555555*2];
void adde(int u,int v)
{
	edge[++k].next=head[u];
	head[u]=k;
	edge[k].v=v;
}
void dfs(int u,int fa)
{
	d[u]=d[fa]+1;
	f[u][0]=fa;
	for (int i=1;i<=20;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for (int i=head[u];i;i=edge[i].next)
	{
		v=edge[i].v;
		if (v!=fa)
			dfs(v,u);
	}
}
int lca(int a,int b)
{
	if (d[a]>d[b])
		swap(a,b);
	for (int i=20;i>=0;i--)
		if (d[a]<=d[b]-(1<<i))
			b=f[b][i];
	if (a==b)
		return a;
	for (int i=20;i>=0;i--)
	{
		if (f[a][i]==f[b][i])
			continue;
		a=f[a][i],b=f[b][i];
	}
	return f[a][0];
}
int main()
{
	scanf("%d%d",&n,&m);
    s=1;
	for (int i=0;i<=n+10;i++)
		head[i]=-1;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&tmp1,&tmp2);
		adde(tmp1,tmp2);
		adde(tmp2,tmp1);
	}
	dfs(s,0);
    scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&tmp1,&tmp2);
		// if ((d[tmp1]+d[tmp2]-d[lca(tmp1,tmp2)])%2)
        //     puts("Yes");
        // else
        //     puts("No");
		cout<<d[tmp1]<<' '<<d[tmp2]<<' '<<d[lca(tmp1,tmp2)]<<endl;
	}
	return 0;
}
/*
7 6
1 2
1 3
2 4
2 5
3 6
5 7
4
4 6
4 5
6 7
4 7

*/