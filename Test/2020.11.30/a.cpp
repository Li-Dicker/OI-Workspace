#include<bits/stdc++.h>
#define int long long
#define N 111111
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

int T,n,a,b;
 
signed main() {
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	T=input();
	while (T--) {
		n=input(),a=input(),b=input();
//		a=2,b=5,n=T;
//		print(n,' ');
		n%=(a+b);
		if (a>b)
			swap(a,b);
		if (n<b) {
			n/=a;
			if (n%2==0)
				puts("0");
			else
				puts("1");
		}
		else
			puts("1");
		
	}
	return 0;
}
