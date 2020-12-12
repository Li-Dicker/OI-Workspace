#include<bits/stdc++.h>
#define int long long
#define N 555
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

struct Matrix {
	int x,y;
	int a[N][N];

	void init() {
		for (int i=1;i<=x;i++)
			for (int j=1;j<=y;j++)
				a[i][j]=0;
	}
}A,B,ans;

signed main() {
	A.x=input(),A.y=B.x=input(),B.y=input();
	for (int i=1;i<=A.x;i++)
		for (int j=1;j<=A.y;j++)
			A.a[i][j]=input();
	for (int i=1;i<=B.x;i++)
		for (int j=1;j<=B.y;j++)
			B.a[i][j]=input();
	ans.x=A.x,ans.y=B.y;
	ans.init();
	for (int i=1;i<=A.x;i++)
		for (int j=1;j<=B.y;j++)
			for (int k=1;k<=A.y;k++)
				ans.a[i][j]=(ans.a[i][j]+A.a[i][k]*B.a[k][j]+MOD)%MOD;
	for (int i=1;i<=ans.x;i++) {
		for (int j=1;j<=ans.y;j++)
			print((ans.a[i][j]+MOD)%MOD,' ');
		puts("");
	}
	return 0;
}