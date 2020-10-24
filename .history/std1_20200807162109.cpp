#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int n,u,v,d[maxn],ans,vis[maxn],mn,md,Fa[maxn];
int cnt,head[maxn];
struct edge{
	int to,next;
}e[maxn<<1];

void adde(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int u,int fa){
	d[u]=d[fa]+1;Fa[u]=fa;
	if(d[mn]<d[u])mn=u;
	for(register int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa)continue;
		dfs(v,u);
	}
}

void dfs2(int u,int fa,int len,int m){
	if(len>m)return;vis[u]=1;
	for(register int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa)continue;
		dfs2(v,u,len+1,m);
	}
}

void dfs3(int u,int fa){
	if(!vis[u]&&d[md]<d[u])md=u;
	for(register int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa)continue;
		dfs3(v,u);
	}
}

bool check(int m){
	memset(vis,0,sizeof(vis));
	if(d[mn]<=m)return 1;
	int j=mn;
	for(register int i=1;i<=m;i++)j=Fa[j];
	dfs2(j,0,0,m);
	md=0;dfs3(1,0);
	j=md;if(d[md]<=m)return 1;
	for(register int i=1;i<=m;i++)j=Fa[j];
	dfs2(j,0,0,m);
	for(register int i=1;i<=n;i++)
		if(!vis[i])return 0;
	return 1;
}

int main(){
	scanf("%d",&n);
	for(register int i=1;i<n;i++)
		scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	d[0]=0;dfs(1,0);
	int l=0,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
