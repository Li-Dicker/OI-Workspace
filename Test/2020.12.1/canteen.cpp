#include<bits/stdc++.h>
#define int long long
#define N 1011
#define INF 0x3f3f3f3f
#define MOD (998244353)
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

int n,m,ans1=0,ans2=1,num=0;
const int dx[]={0,1,0,-1,0},dy[]={0,0,1,0,-1};
int mp[N][N],vis[N][N],kong[N][N];
char s[N];

namespace Fib {
	
	struct Matrix {
		int a[6][6];
	}A,E,Ans;
	
	Matrix muti(Matrix a,Matrix b) {
		Matrix res;
		for (int i=1;i<=2;i++)
			for (int j=1;j<=2;j++)
			{
				res.a[i][j]=0;
				for (int k=1;k<=2;k++)
					res.a[i][j]=(res.a[i][j]+a.a[i][k]*b.a[k][j]%MOD)%MOD;
			}
		return res;
	}
	
	Matrix jzcf(Matrix a,Matrix b) {
		Matrix res;
		for (int i=1;i<=1;i++)
			for (int j=1;j<=2;j++) {
				res.a[i][j]=0;
				for (int k=1;k<=2;k++)
					res.a[i][j]=(res.a[i][j]+a.a[i][k]*b.a[k][j]%MOD)%MOD;
			}
		return res;
	}
	
	Matrix ksm(Matrix A,int k) {
		Matrix res=E;
		while (k) {
			if (k&1)
				res=muti(res,A);
			A=muti(A,A);
			k>>=1;
		}
		return res;
	}
	
	void pre() {
		A.a[1][1]=1,A.a[1][2]=1,
		A.a[2][1]=1,A.a[2][2]=0;
		E.a[1][1]=1,E.a[1][2]=0,
		E.a[2][1]=0,E.a[2][2]=1;
	}
	
	int query(int x)
	{
		Ans.a[1][1]=2,Ans.a[1][2]=1;
		x++;
		if (x<=2)
			return x;
		Ans=jzcf(Ans,ksm(A,x-2));
		return Ans.a[1][1];
	}
}

void dfs_calc(int x,int y) {
	vis[x][y]=1;
	int xx,yy;
	for (int i=1;i<=4;i++) {
		xx=x+dx[i],yy=y+dy[i];
		kong[x][y]+=(mp[xx][yy]==0&&(xx>=1&&xx<=n&&yy>=1&&yy<=m));
	}
	for (int i=1;i<=4;i++) {
		xx=x+dx[i],yy=y+dy[i];
		if (mp[xx][yy]&&!vis[xx][yy])
			dfs_calc(xx,yy);
	}
}

int dfs(int x,int y) {
	vis[x][y]=1,num+=kong[x][y];
	bool border=(x==1||x==n||y==1||y==m);
	for (int i=1;i<=4;i++) {
		int xx=x+dx[i],yy=y+dy[i];
		if (mp[xx][yy]&&!vis[xx][yy])
			border|=dfs(xx,yy);
	}
	return border;
}

signed main() {
	freopen("canteen.in","r",stdin);freopen("canteen.out","w",stdout);
	n=input(),m=input();
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			mp[i][j]=(s[j]=='#');
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (mp[i][j]&&!vis[i][j])
				dfs_calc(i,j);
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=m;j++)
//			print(kong[i][j],' ');
//		puts("");
//	}
	memset(vis,0,sizeof(vis));
	Fib::pre();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (mp[i][j]&&!vis[i][j]) {
				num=0;
				if (dfs(i,j)>0)
					ans1+=(num+1)/2,ans2=(ans2*Fib::query(num))%MOD;
				else
					ans1+=num/2,ans2=(ans2*(Fib::query(num-1)+Fib::query(num-3)))%MOD;
			}
	print(ans1,' '),print(ans2,'\n');
	return 0;
}
/*
5 5
.....
..#..
.###.
..#..
...#.

8 1610
*/
