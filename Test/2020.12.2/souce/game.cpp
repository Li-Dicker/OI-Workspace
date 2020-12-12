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

int n,pos=0,ans=0;
int a[N],suf[N];

signed main() {
	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	n=input();
	for (int i=1;i<=n;i++)
		a[i]=input();
	suf[n]=a[n];
	for (int i=n-1;i>=1;i--)
		suf[i]=max(suf[i+1],a[i]);
	pos=0;
	for (int i=1;i<=n;i++)
		if (suf[i]==a[i]) {
			ans+=(i-pos)*a[i];
			pos=i;
		}
	print(ans,'\n');
	return 0;
}

