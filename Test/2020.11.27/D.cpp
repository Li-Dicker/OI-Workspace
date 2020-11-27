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

int n,m,tmpe,ans=0;
struct lyp{
	int id,l,r;
}p[N];

bool cmp(lyp a,lyp b) {
	return a.id<b.id;
}

signed main() {
	n=input(),m=input();
	for (int i=1;i<=m;i++)
		p[i].id=input(),p[i].l=input(),p[i].r=input();
	sort(p+1,p+1+m,cmp);
	for (int i=1;i<=m;i++) {
		if (p[i].id>tmpe)
			ans+=p[i].id-1-tmpe,tmpe=p[i].id-1;
		if (ans+1<p[i].l)
			ans++,tmpe=p[i].id;
		else {
			if (ans>p[i].r)
				ans++,tmpe=p[i].id;
			else
				ans=p[i].r+1,tmpe=p[i].id;
		}
	}
	if (tmpe<=n)
		ans+=n+1-tmpe;
	print(ans,'\n');
	return 0;
}
/*
4 2
1 2 50
3 2 5
*/