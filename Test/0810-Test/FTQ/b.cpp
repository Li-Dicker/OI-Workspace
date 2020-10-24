#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int>g[2003];
char c[2003];
ll ans;
int d[2003];
void bfs(int s){
	for(int i=1;i<=n;i++)d[i]=n;
	d[s]=0;queue<int>que;que.push(s);
	while(!que.empty()){
		int u=que.front();que.pop();
		for(int i=0;i<g[u].size();i++)if(d[g[u][i]]==n)
			d[g[u][i]]=d[u]+1,que.push(g[u][i]);
	}
	for(int i=1;i<=n;i++)ans+=d[i]*d[i];
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		for(int j=1;j<=n;j++)
			if(c[j]=='1'&&j!=i)g[i].push_back(j);
	}
	for(int i=1;i<=n;i++)bfs(i);
	cout<<ans;
}
