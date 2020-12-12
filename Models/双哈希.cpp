#include<bits/stdc++.h>
#define int long long
#define N 11111
#define INF 0x3f3f3f3f
#define MOD1 ((int )1e9+7)
#define MOD2 (998244353) 
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
char s[N];

struct Hash_Map {
	int hash1,hash2;
}hash_map[N];

Hash_Map get_hash(char a[]) {
	int len=strlen(a),res1=0,res2=0;
	Hash_Map res;
	for (int i=0;i<len;i++)
		res1=(res1*base+a[i])%MOD1,res2=(res2*base+a[i])%MOD2;
	res.hash1=res1,res.hash2=res2;
	return res;
}

bool cmp(Hash_Map a,Hash_Map b) {
	if (a.hash1==b.hash1)
		return a.hash2<b.hash2;
	return a.hash1<b.hash1;
}

signed main() {
	n=input();
	for (int i=1;i<=n;i++) {
		scanf("%s",s);
		hash_map[i]=get_hash(s);
	}
	sort(hash_map+1,hash_map+n+1,cmp);
	for (int i=2;i<=n;i++)
		if (hash_map[i].hash1!=hash_map[i-1].hash1||hash_map[i].hash2!=hash_map[i-1].hash2)
			ans++;
	print(ans,'\n');
	return 0;
}