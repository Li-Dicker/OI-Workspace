#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second 
int n,cnt;
int p[200004];
int rt[200004];
vector<pii>g[200004];
int L[4200000],R[4200000]; 
int got(int l,int r,int id,int pos){
	if(l==r)return L[id];
	if((l+r)/2>=pos){
		if(L[id]==0)return 0;
		return got(l,(l+r)/2,L[id],pos);
	}
	if(R[id]==0)return 0;
	return got((l+r)/2+1,r,R[id],pos);
}
int upd(int l,int r,int id,int pos,int x){
	int id1=++cnt;
	if(l==r){
		L[id1]=x;
		return id1;
	}
	if((l+r)/2>=pos){
		if(id!=0)L[id1]=L[id],R[id1]=R[id];
		L[id1]=upd(l,(l+r)/2,L[id],pos,x);
		return id1;
	}
	if(id!=0)L[id1]=L[id],R[id1]=R[id];
	R[id1]=upd((l+r)/2+1,r,R[id],pos,x);
	return id1;
}
int nxt[200004];
void bfs(){
	queue<int>que;
	for(int i=0;i<g[0].size();i++){
		int col=g[0][i].fi,to=g[0][i].se;
		rt[0]=upd(1,n,rt[0],col,to);
		nxt[to]=0;
		que.push(to);
	}
	while(!que.empty()){
		int u=que.front();que.pop();
		rt[u]=rt[nxt[u]];
		for(int i=0;i<g[u].size();i++){
			int col=g[u][i].fi,to=g[u][i].se;
			nxt[to]=got(1,n,rt[nxt[u]],col);
			rt[u]=upd(1,n,rt[u],col,to);
			que.push(to);
		}
	}
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		g[p[i]].push_back(mkp(x,i)); 
	}
	bfs();
	for(int i=1;i<=n;i++)printf("%d ",nxt[i]);
}
