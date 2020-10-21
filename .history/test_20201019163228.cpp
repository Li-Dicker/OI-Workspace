#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=114514;
const int K=13;
const int mod=1e9+7;
ll msk(ll a,int b){ll k=1;a%=mod;
	while(b){if(b&1)k=k*a%mod;a=a*a%mod,b>>=1;}return k;
}
struct edge{
	int v,nt;
}e[N*2];
ll g[N][K],sz[N][K];//��1Ϊ��ʱ 
ll dp[N][K],fz[N][K];//��xΪ��ʱ 
int n,k,tot,fa[N],hd[N],mx[N];
void add(int x,int y){
	e[++tot].v=y;e[tot].nt=hd[x];hd[x]=tot;
}
bool vs[N][K];
void dfs1(int x,int f,int d){if(vs[x][d])return;
	vs[x][d]=g[x][d]=sz[x][d]=1;if(!d)return;
	for(int i=hd[x],to;i;i=e[i].nt){to=e[i].v;
		if(to==f)continue;mx[x]=max(mx[x],mx[to]);
		for(int j=0;j<=k;j++)dfs1(to,x,j);
		g[x][d]=g[x][d]*g[to][d-1]%mod,sz[x][d]+=sz[to][d-1];
	}g[x][d]=g[x][d]*sz[x][d]%mod;mx[x]++;
}
void dfs2(int x,int f){
	dp[x][1]=dp[x][0]=fz[x][0]=1,fz[x][1]=2;
	for(int j=max(2,k-mx[x]+1);j<=k;j++){
		fz[x][j]=fz[f][j-1]+1-sz[x][j-2];
		dp[x][j]=dp[f][j-1]*((fz[x][j]-1)*msk(g[x][j-2]*fz[f][j-1],mod-2)%mod)%mod;
	}for(int d=max(1,k-mx[x]+1);d<=k;d++){
		for(int i=hd[x],to;i;i=e[i].nt){to=e[i].v;if(to==f)continue;
		dp[x][d]=dp[x][d]*g[to][d-1]%mod,fz[x][d]+=sz[to][d-1];
		}dp[x][d]=dp[x][d]*fz[x][d]%mod;
	}
	for(int i=hd[x],to;i;i=e[i].nt){to=e[i].v;
		if(to==f)continue;dfs2(to,x);
	}
}
int main(){
	// freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}for(int i=0;i<=k;i++)dfs1(1,0,i);
	for(int i=1;i<=k;i++)dp[1][i]=g[1][i],fz[1][i]=sz[1][i];
	for(int i=hd[1];i;i=e[i].nt)dfs2(e[i].v,1);
	// for(int i=1;i<=n;i++){
	// 	printf("%lld ",fz[i][k]);
	// }puts("");
	// for(int i=1;i<=n;i++){
	// 	printf("%lld ",dp[i][k]);
	// }
	for (int i=1;i<=n;i++)
		for (int j=0;j<=k;j++)
			printf("%lld ",g [i][j]);
}
