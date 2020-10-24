#include<iostream>
#include<cstdio>
#include<cstring>
#define Re register
#define In inline
using namespace std;
const int maxl=20, maxn=257, inf=2e9;
int n, l=256, stx, sty, out[maxn], tp, way[maxn], a[maxl][5][5];
bool u[maxl][5][5], vis[maxl][5][5];
char t[6]={ 0, 'S', 'N', 'E', 'W', 'U' }, ans[maxn];
double now=-inf;
In void dfs(Re int k, Re int x, Re int y, Re int sum, Re int num)
{
	if (vis[k][x][y]||k>n||x<1||x>4||y<1||y>4)
		return;
	vis[k][x][y]=true;
	if (k==n&&(double)sum/(double)num>now)
	{
		now=(double)sum/(double)num;
		tp=num;
		for (Re int i=1;i<=tp;i++)
			out[i]=way[i];
	}
	way[num]=1;
	dfs(k, x+1, y, sum+a[k][x+1][y], num+1);
	way[num]=2;
	dfs(k, x-1, y, sum+a[k][x-1][y], num+1);
	way[num]=3;
	dfs(k, x, y+1, sum+a[k][x][y+1], num+1);
	way[num]=4;
	dfs(k, x, y-1, sum+a[k][x][y-1], num+1);
	if (u[k][x][y])
	{
		way[num]=5;
		dfs(k+1, x, y, sum+a[k+1][x][y], num+1);
	}
	vis[k][x][y]=false;
}
int main()
{
	scanf("%d%d%d", &n, &stx, &sty);
	for (Re int i=1;i<=n;i++)
	{
		for (Re int j=1;j<=4;j++)
			for (Re int k=1;k<=4;k++)
				scanf("%d", &a[i][j][k]);
		for (Re int j=1;j<=4;j++)
			for (Re int k=1;k<=4;k++)
				scanf("%d", &u[i][j][k]);
	}
	dfs(1, stx, sty, a[1][stx][sty], 1);
	printf("%d\n", tp-1);
	for (Re int i=1;i<=tp-1;i++)
		putchar(t[out[i]]);
	return 0;
}

