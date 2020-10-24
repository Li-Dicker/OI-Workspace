#include<iostream>
#include<cstdio>
#include<cstring>
#define In inline
using namespace std;
const int maxl=20, maxn=257, inf=2e9;
int n, l=256, stx, sty, out[maxn], tp, way[maxn], a[maxl][5][5];
bool u[maxl][5][5], vis[maxl][5][5];
char t[6]={ 0, 'S', 'N', 'E', 'W', 'U' }, ans[maxn];
double now=-inf;

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

In void dfs(int k, int x, int y, int sum, int num)
{
	if (vis[k][x][y]||k>n||x<1||x>4||y<1||y>4)
		return;
	vis[k][x][y]=true;
	if (k==n&&(double)sum/(double)num>now)
	{
		now=(double)sum/(double)num;
		tp=num;
		for (int i=1;i<=tp;i++)
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
signed main()
{
    n=input(),stx=input(),sty=input();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=4;j++)
			for (int k=1;k<=4;k++)
                a[i][j][k]=input();
		for (int j=1;j<=4;j++)
			for (int k=1;k<=4;k++)
                u[i][j][k]=input();
	}
	dfs(1, stx, sty, a[1][stx][sty], 1);
    print(tp-1,'\n');
	for (int i=1;i<=tp-1;i++)
		putchar(t[out[i]]);
	return 0;
}
