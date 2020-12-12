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

int n;
int tmpe;
multiset<int >s;
multiset<int >::iterator pos;

signed main() {
	n=input();
	while (n--) {
		tmpe=input();
		if (tmpe==1) {
			tmpe=input();
			s.insert(tmpe);
		}
		else if (tmpe==2) {
			tmpe=input();
			pos=s.find(tmpe);
			if (pos!=s.end())
				s.erase(pos);
		}
		else if (tmpe==5) {
			tmpe=input();
			pos=s.lower_bound(tmpe);
			pos--;
			print(*pos,'\n');
		}
		else if (tmpe==6) {
			tmpe=input();
			pos=s.upper_bound(tmpe);
			print(*pos,'\n');
		}
		else
			tmpe=input(),puts("Not Support");
	}
	return 0;
}