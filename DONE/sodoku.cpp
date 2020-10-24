#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,num,flag;
int mp[11][11],vis[11][11];
const int dx[11]={0,1,0,-1,0},dy[11]={0,0,1,0,-1};
struct stick
{
	int x,y,num;
}point[111];
bool check()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (mp[i][j]==0)
				return 0;
	return 1;
}
void dfs(int x,int y)
{
	int ss[11];
	memset(ss,0,sizeof(ss));
	for (int i=1;i<=n;i++)
		ss[mp[i][y]]=1,ss[mp[x][i]]=1;
	int xs,xt,ys,yt;
	if ((x-1)%3==0)
		xs=x,xt=x+3;
	else
		xs=1+(x-1)%3*3,xt=xs+3;
	if ((y-1)%3==0)
		ys=x,yt=x+3;
	else
		ys=1+(x-1)%3*3,yt=ys+3;
	for (int i=xs;i<=xt;i++)
		for (int j=ys;j<=yt;j++)
			ss[mp[i][j]]=1;
	int xx,yy;
	for (int i=1;i<=4;i++)
	{
		xx=x+dx[i],yy=y+dy[i];
		if (!vis[xx][yy]&&xx>=1&&xx<=n&&yy>=1&&yy<=n)
			break;
	}
	vis[x][y]=1;
	for (int i=1;i<=9;i++)
		mp[x][y]=ss[i],dfs(x,y);
	if (check())
		flag=1;
}
signed main()
{
	n=9,flag=0;
	cin>>num;
	for (int i=1;i<=num;i++)
	{
		cin>>point[i].x>>point[i].y>>point[i].num;
		mp[point[i].x][point[i].y]=num;
		vis[point[i].x][point[i].y]=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!vis[i][j])
			{
				dfs(i,j);
				goto loop;
			}
	loop:
	if (!flag)
		printf("No Anser\n");
	else
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				cout<<mp[i][j]<<' ';
			cout<<endl;
		}
	return 0;
}
/*
32
1 4 2
1 6 9
1 7 3
1 9 7
2 2 5
2 7 2
2 9 1
3 1 4
3 2 2
3 4 7
3 9 5
4 3 7
4 5 4
4 7 6
4 8 3
5 4 6
5 6 5
6 2 3
6 3 6
6 5 9
6 7 5
7 1 3
7 6 1
7 8 2
7 9 8
8 1 8
8 3 4
8 8 9
9 1 1
9 3 2
9 4 4
9 6 3
*/