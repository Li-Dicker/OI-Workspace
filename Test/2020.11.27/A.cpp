#include<bits/stdc++.h>
#define int long long
#define N 10000011
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

int l,r,ans=0,cnt=0,tmpe,num;
int isprime[N],vis[N],test[N];

void prime(int last) {
	for (int i=2;i<=last+1;i++) {
		if (!vis[i])
			isprime[++cnt]=i;
		for (int j=1;j<=cnt&&(i*isprime[j])<=last+1;j++) {
			vis[i*isprime[j]]=1;
			if (!(i%isprime[j]))
				break ;
		}
	}
}

signed main() {
	l=input(),r=input();
	ans=r-l+1;
	prime(N);
	memset(test,0,sizeof(test));
	for (int i=1;i<=cnt&&isprime[i]<=r;i++) {
		tmpe=1,num=1;
		while (tmpe<=r) {
			if (tmpe>=l&&tmpe<=r&&!test[tmpe])
				ans+=(isprime[i]-1),test[tmpe]=1;
			tmpe*=isprime[i];
		}
	}
	print(ans,'\n');
	return 0;
}