#include<bits/stdc++.h>
// #define int long long
#define N 4444444
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

int n,q,ans=0;
int tmp1,tmp2,tmp3;
int fa[N];

int find(int x) {
	if (x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}

void conbine(int x,int y) {
	fa[find(y)]=find(x);
}

signed main() {
	n=input(),q=input();
	for (int i=1;i<=n+11;i++)
		fa[i]=i;
	while (q--) {
		tmp1=input(),tmp2=input(),tmp3=input();
		if (!tmp1)
			conbine(tmp2,tmp3);
		else
			ans=(ans*2+(find(fa[tmp2])==find(fa[tmp3])))%MOD;
	}
	print(ans%MOD,'\n');
	return 0;
}