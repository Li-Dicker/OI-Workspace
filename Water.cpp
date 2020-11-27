#include<bits/stdc++.h>
// #define int long long
#define N 11
#define M 3333
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

int n,m,s,edgenum=0,stop_sum=0,S,ans=INF;
int head[M],water[N],dis[M],vis[M];
int lenth[N][N],dp[1<<N][N];

struct Warp_Point {
	int x,y,t1,t2;
}point[N];

struct Edge {
	int v,w,next;
}edge[M*M*2];

priority_queue<pair<int ,int > >q;

void adde(int u,int v,int w) {
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
	edge[edgenum].w=w;
}

int calcdis(int a,int b,int k) {
	if (k==3)
		return abs(point[a].x-point[b].x);
	return abs(point[a].x+point[a].y-point[b].x-point[b].y);
}

void init_dijkstra() {
	for (int i=0;i<=3000+11;i++)
		dis[i]=INF,vis[i]=0;
	q=priority_queue<pair<int ,int > >();
}

void dijkstra(int x) {
	init_dijkstra();
	dis[x]=0;
	q.push(make_pair(-dis[x],x));
	while (!q.empty()) {
		int u=q.top().second;
		q.pop();
		if (vis[u])
			continue ;
		vis[u]=1;
		for (int i=head[u];i;i=edge[i].next) {
			int v=edge[i].v;
			if (dis[v]>dis[u]+edge[i].w) {
				dis[v]=dis[u]+edge[i].w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}

void DP() {
	S=(1<<m)-1;
	memset(dp,INF,sizeof(dp));
	dp[1][1]=0;
	for (int i=1;i<=S;i++)
		if (i&1)
			for (int j=1;j<=m;j++)
				if ((i>>(j-1))&1)
					for (int k=1;k<=m;k++)
						if (!((i>>(k-1))&1))
							dp[i|(1<<(k-1))][k]=min(dp[i|(1<<(k-1))][k],dp[i][j]+lenth[j][k]);
}

signed main()
{
	n=input(),m=input()+1,water[1]=s=input();
	for (int i=2;i<=m;i++)
		water[i]=input()+n,stop_sum+=input();
	for (int i=1;i<=n;i++) {
		point[i].x=input()+input()+input(),point[i].y=input();
		point[i].t1=input(),point[i].t2=input();
		adde(i,i+n,point[i].t1);
		adde(i+n,i,point[i].t2);
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) {
			adde(i,j,calcdis(i,j,3));
			adde(j,i,calcdis(j,i,3));
			adde(i+n,j+n,calcdis(i,j,4));
			adde(j+n,i+n,calcdis(j,i,4));
		}
	for (int i=1;i<=m;i++) {
		dijkstra(water[i]);
		for (int j=1;j<=m;j++)
			lenth[i][j]=dis[water[j]];
	}
	DP();
	for (int i=1;i<=m;i++)
		ans=min(ans,dp[S][i]+lenth[i][1]);
	print(ans+stop_sum,'\n');
	return 0;
}