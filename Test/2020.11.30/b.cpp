#include<bits/stdc++.h>
#define int long long
#define N 11
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

double s,ans=0;
double a[N];

void dfs(int x,int num,double tmpe) {
	if (x>=11)
		return ;
	if (num>=3) {
		ans+=tmpe;
		return ;
	}
	dfs(x+1,num,tmpe*(1-a[x+1]));
	dfs(x+1,num+1,tmpe*a[x+1]);
}

signed main() {
	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	scanf("%lf",&s);
	for (int i=1;i<=10;i++)
		scanf("%lf",&a[i]);
	dfs(1,0,1-a[1]),dfs(1,1,a[1]);
	ans=(1-ans)*(1-s);
	printf("%.10lf\n",ans);
	printf("%.10lf\n",(1-ans)*(1-ans));
	return 0;
}
/*
0.5
0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5

*/
