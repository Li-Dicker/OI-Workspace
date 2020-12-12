#include<bits/stdc++.h>
#define int long long
#define N 111
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

int T,n,edgenum,freenum,whitenum,blacknum,SOLVE_FLAG,kuaicnt,sum,ans;
int tmpe;
int head[N],vis[N],color[N];
int mp[N][N],kuai[N][3],dp[N][N];

struct Edge {
	int v,next;
}edge[N*N*2];

queue<pair<int ,int > >q;

void adde(int u,int v) {
	edge[++edgenum].next=head[u];
	head[u]=edgenum;
	edge[edgenum].v=v;
}

void init() {
	edgenum=freenum=whitenum=blacknum=SOLVE_FLAG=kuaicnt=sum=0;
	memset(head,0,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(color,0,sizeof(color));
	memset(mp,1,sizeof(mp));
	memset(kuai,0,sizeof(kuai));
	q=queue<pair<int ,int > >();
}

void bfs(int x,int fa) {
	color[x]=0;
	kuai[kuaicnt][color[x]]++;
	vis[x]=1;
	for (int i=head[x];i;i=edge[i].next) {
		int v=edge[i].v;
		if (v==fa)
			continue ;
		q.push(make_pair(v,1));
	}
	while (!q.empty()) {
		int u=q.front().first;
		if (vis[u]) {
			q.pop();
			continue ;
		}
		color[u]=q.front().second;
		kuai[kuaicnt][color[u]]++;
		vis[u]=1;
		q.pop();
		for (int i=head[u];i;i=edge[i].next) {
			int v=edge[i].v;
			if (vis[v]) {
				if (color[v]!=color[u]^1) {
					SOLVE_FLAG=1;
					puts("No solution");
					return ;
				}
				continue ;
			}
			q.push(make_pair(v,color[u]^1));
		}
	}
}

void dfs(int u,int fa) {
	color[u]=color[fa]^1;
	vis[u]=1;
	kuai[kuaicnt][color[u]]++;
	for (int i=head[u];i;i=edge[i].next) {
		int v=edge[i].v;
		if (vis[v]) {
			if (color[v]!=color[fa]) {
				if (!SOLVE_FLAG)
					puts("No solution");
				SOLVE_FLAG=1;
				return ;
			}
			continue ;
		}
		dfs(v,u);
		if (SOLVE_FLAG==1)
			return ;
	}
}

signed main() {
	// freopen("team.in","r",stdin);freopen("team.out","w",stdout);
	T=input();
	while (T--) {
		init();
		n=input();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) {
				tmpe=input();
				mp[i][j]&=tmpe,mp[j][i]&=tmpe;
			}
		// for (int i=1;i<=n;i++) {
		// 	int flag=1;
		// 	for (int j=1;j<=n;j++)
		// 		if (mp[i][j]==0) {
		// 			flag=0;
		// 			break ;
		// 		}
		// 	if (flag==1)
		// 		freenum++,color[i]=-1,vis[i]=1;
		// }
		for (int i=1;i<=n;i++)
			for (int j=1;j<i;j++)
				if (mp[i][j]==0) {
					adde(i,j);
					adde(j,i);
					// print(i,' '),print(j,'\n');
				}
		for (int i=1;i<=n;i++)
			if (!vis[i]) {
				kuaicnt++;
				dfs(i,0);
				//bfs(i,0);
				if (SOLVE_FLAG)
					break ;
				sum+=kuai[kuaicnt][0]+kuai[kuaicnt][1];
				continue ;
			}
		if (n==1)
			puts("No solution");
		if (SOLVE_FLAG||n==1)
			continue ;
		// for (int i=1;i<=kuaicnt;i++)
		// 	print(sum,' '),print(kuai[i][0],' '),print(kuai[i][1],'\n');
		// for (int i=1;i<=n;i++)
		// 	if (color[i]==0)
		// 		whitenum++;
		// 	else if (color[i]==1)
		// 		blacknum++;
		// if (abs(whitenum-blacknum)>=freenum)
		// 	print(abs(whitenum-blacknum)-freenum,'\n');
		// else
		// 	print((freenum-abs(whitenum-blacknum))%2,'\n');
		memset(dp,0x3f,sizeof(dp));
		dp[1][kuai[1][0]]=kuai[1][0],dp[1][kuai[1][1]]=kuai[1][1];
		for (int i=1;i<kuaicnt;i++)
			for (int j=1;j<=sum;j++) {
				dp[i+1][j+kuai[i+1][0]]=min(dp[i+1][j+kuai[i+1][0]],dp[i][j]+kuai[i+1][0]);
				dp[i+1][j+kuai[i+1][1]]=min(dp[i+1][j+kuai[i+1][1]],dp[i][j]+kuai[i+1][1]);
			}
		ans=INF;
		for (int i=1;i<=sum;i++)
			ans=min(ans,abs(sum-i-dp[kuaicnt][i]));
		print(ans,'\n');
	}
	return 0;
}

