#include<bits/stdc++.h>
#define int long long
#define N 666
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y1 _yy_
using namespace std;
namespace IOstream {
	#define print(a,b) prints(a),putchar(b)
	int BUF[22],BUFSIZE,IONUM,SIGN;
	char GET;

	inline int input() {
		IONUM=0,SIGN=1;
		GET=getchar();
		while (GET<'0'||GET>'9') {
			if (GET=='-')
				SIGN=-1;
			GET=getchar();
		}
		while (GET>='0'&&GET<='9') {
			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
			GET=getchar();
		}
		return SIGN*IONUM;
	}

	inline void prints(int IONUM) {
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

int n,m,s,t,k=INF,edgenum=0;
int tmp1,tmp2;
int w[N],head[N],dis[N];

struct Edge{
	int v,next,id;	
}edge[N*N*3];

queue<int >q;

void adde(int u,int v,int id)
{
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
	edge[edgenum].id=id;
}

// void bfs(int s)
// {
// 	q.push(make_pair(s,0));
// 	while (!q.empty()) {
// 		int u=q.front().first;
// 		int bfs_clock=q.front().second;
// 		if (u==t) {
// 			k=max(k,bfs_clock);
// 			return ;
// 		}
// 		q.pop();
// 		for (int i=head[u];i;i=edge[i].next) {
// 			int v=edge[i].v;
// 			if (w[edge[i].id])
// 				continue ;
// 			w[edge[i].id]=bfs_clock+1;
// 			q.push(make_pair(v,w[edge[i].id]));
// 		}
// 	}
// }

void bfs(int x) {
	q.push(x);
	dis[x]=1;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (int i=head[u];i;i=edge[i].next) {
			int v=edge[i].v;
			w[edge[i].id]=min(w[edge[i].id],dis[u]);
			if (dis[v])
				continue ;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
}

signed main() {
	freopen("E:/OI-Workspace/Test/2020.12.3/graph.in","r",stdin);freopen("E:/OI-Workspace/Test/2020.12.3/graph.out","w",stdout);
	n=input(),m=input(),s=input(),t=input();
	for (int i=1;i<=m;i++) {
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2,i);
		adde(tmp2,tmp1,i);
	}
	memset(w,0x3f,sizeof(w));
	bfs(s);
	for (int i=head[t];i;i=edge[i].next)
		k=min(k,w[edge[i].id]);
	print(k,'\n');
	for (int i=1;i<=m;i++)
		print(w[i]>k?0:w[i],'\n');
	return 0;
}
