#include<bits/stdc++.h>
#define int long long
#define N 3333
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y1 _yy_
using namespace std;
namespace IOstream
{
	#define int long long
	#define print(a,b) prints(a),putchar(b)
	int BUF[22],BUFSIZE,IONUM,SIGN;
	char GET;

	inline int input()
	{
		IONUM=0,SIGN=1;
		GET=getchar();
		while (GET<'0'||GET>'9')
		{
			if (GET=='-')
				SIGN=-1;
			GET=getchar();
		}
		while (GET>='0'&&GET<='9')
		{
			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
			GET=getchar();
		}
		return SIGN*IONUM;
	}

	inline void prints(int IONUM)
	{
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

int n,m,ans;
int X[]={0,0,1},Y[]={0,1,0};
char sss[N];
char mp[N][N];
queue<int>qu,tmpe;
map<pair<int ,int >,int >vis;

void dfs(int x,int y)
{
	putchar(mp[x][y]);
	if (x==n&&y==m)
	{
		puts("");
		return ;
	}
	if (x==n)
		dfs(x,y+1);
	else if (y==m)
		dfs(x+1,y);
	else
	{
		if (mp[x+1][y]<mp[x][y+1])
			dfs(x+1,y);
		else
			dfs(x,y+1);
	}
}

void bfs()
{
	putchar(mp[1][1]);
	qu.push(1);
	for (int i=2;i<=n+m-1;i++)
	{
		ans=INF;
		vis.clear();
		while (!qu.empty())
		{
			int y=qu.front();
			int x=i-y;
			qu.pop();
			if (x>n||y>m)
				continue ;
			for (int i=1;i<=2;i++)
				if (x+X[i]<=n&&y+Y[i]<=m&&!vis[make_pair(x,y+Y[i])])
				{
					vis[make_pair(x,y+Y[i])]=1;
					int next=mp[x+X[i]][y+Y[i]];
					if (next<ans)
					{
						ans=next;
						while (!tmpe.empty())
							tmpe.pop();
					}
					if (next==ans)
						tmpe.push(y+Y[i]);
				}
		}
		putchar(ans);
		while (!tmpe.empty())
		{
			qu.push(tmpe.front());
			tmpe.pop();
		}
	}
}

signed main()
{
	n=input(),m=input();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",sss+1);
		for (int j=1;j<=m;j++)
			mp[i][j]=sss[j];
	}
	// dfs(1,1);
	bfs();
	puts("");
	return 0;
}
/*
3 6
xuiotp
dwhajv
fzqzyc
*/