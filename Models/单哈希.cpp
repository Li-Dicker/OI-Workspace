#include<bits/stdc++.h>
#define int long long
#define N 11111
#define INF 0x3f3f3f3f
#define MOD (511702200508170253)
#define base 133
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

int n,ans=1;
int hash_map[N];
char s[N];

int get_hash(char a[]) {
	int len=strlen(a),res=0;
	for (int i=0;i<len;i++)
		res=(res*base+a[i])%MOD;
	return res;
}

signed main() {
	n=input();
	for (int i=1;i<=n;i++) {
		scanf("%s",s);
		hash_map[i]=get_hash(s);
	}
	sort(hash_map+1,hash_map+n+1);
	for (int i=2;i<=n;i++)
		if (hash_map[i]!=hash_map[i-1])
			ans++;
	print(ans,'\n');
	return 0;
}