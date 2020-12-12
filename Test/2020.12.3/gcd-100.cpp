#include<bits/stdc++.h>
#define int long long
#define N 1111
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

int n,gcdnum=0,ans=0;
int gcds[N],vis[N],gcd_get[N][N];

int gcd(int x,int y) {
	if (gcd_get[x][y])
		return gcd_get[x][y];
	return gcd_get[x][y]=gcd_get[y][x]=(y==0?x:gcd(y,x%y));
}

signed main() {
	// freopen("gcd.in","r",stdin);freopen("gcd.out","w",stdout);
	n=input();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) {
			int tmpe=gcd(i,j);
			if (!vis[tmpe])
				gcds[++gcdnum]=tmpe;
			vis[tmpe]++;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=gcdnum;j++)
			ans+=gcd(i,gcds[j])*vis[gcds[j]];
	print(ans,'\n');
	return 0;
}
