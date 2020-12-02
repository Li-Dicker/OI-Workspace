#include<bits/stdc++.h>
#define int long long
#define N 2222
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

int n,m,ans;
int tmpe;
int l[N],r[N];


int ksm(int x,int k) {
	int res=1;
	if (k==0)
		return 1;
	while (k) {
		if (k&1)
			res=res*x%MOD;
		x=x*x%MOD;
		k>>=1;
	}
	return res;
}

signed main() {
	// freopen("666.in","r",stdin);freopen("666.out","w",stdout);
	n=input(),m=input();
	for (int i=1;i<=m;i++)
		l[i]=input(),r[i]=input();
	for (int i=1;i<=ksm(10,n)-1;i++) {
		for(int j=1;j<=m;j++) {
			tmpe=1;
			for (int k=l[j];k<=r[j];k++)
				tmpe*=i/ksm(10,k-1)%10;
			if (tmpe%6==0)
				ans++;
		}
		if (ans==MOD)
			ans=0;
	}
	print(ans+1,'\n');
	return 0;
}
