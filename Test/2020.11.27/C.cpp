#include<bits/stdc++.h>
// #define int long long
#define N 1111111
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

int n,gcd_all=0,tmpe,ans=0;
int a[N];

int gcd(int x,int y) {
	return y==0?x:gcd(y,x%y);
}

signed main() {
	n=input();
	gcd_all=a[1]=input();
	for (int i=2;i<=n;i++) {
		a[i]=input();
		gcd_all=gcd(gcd_all,a[i]);
	}
	for (int i=1;i<=n;i++)
		a[i]/=gcd_all;
	for (int i=1;i<=n;i++)
		for (int j=2;j*j<=a[i];j++)
			while (a[i]%j==0)
				a[i]/=j,ans++;
	for (int i=1;i<=n;i++)
		if (a[i]>1)
			ans++;
	print(ans,'\n');
	return 0;
}