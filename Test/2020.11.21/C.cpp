#include<bits/stdc++.h>
#define int long long
#define N 2222
#define M 50000
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y _yy_
using namespace std;
namespace IOstream
{
	#define int long long
	#define print(a,b) prints(a),putchar(b)
	int BUF[22],BUFSIZE,IONUM,SIGN;
	char GET;

	inline int input()
	{
		IONUM=0,SIGN=1;
		GET=getchar();
		while (GET<'0'||GET>'9')
		{
			if (GET=='-')
				SIGN=-1;
			GET=getchar();
		}
		while (GET>='0'&&GET<='9')
		{
			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
			GET=getchar();
		}
		return SIGN*IONUM;
	}

	inline void prints(int IONUM)
	{
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

int n,m,V,vtmpe;
int sum1=0,sum2=0;
int f[M*111],dp[M*111];

struct Point {
	int x,y,z;
}a[N],b[N];

signed main() {
	n=input(),m=input(),V=input();
	for (int i=1;i<=n;i++)
		a[i].x=input(),a[i].y=input(),a[i].z=input();
	for(int i=1;i<=m;i++)
		b[i].x=input(),b[i].y=input(),b[i].z=input();
	for (int i=1;i<=n;i++)
		for (int v=1;v<=a[i].z;v++) {
			sum1+=a[i].y;
			for(int j=sum1;j>=a[i].y;j--)
				f[j]=max(f[j],f[j-a[i].y]+a[i].x);
		}
	for (int i=1;i<=m;i++)
		for (int v=1;v<=b[i].z;v++) {
			sum2+=b[i].y;
			for (int j=sum2;j>=b[i].y;j--)
				dp[j]=max(dp[j],dp[j-b[i].y]+b[i].x);
		}
	for (int i=0;i<=sum1;i++)
		if (f[i]>=V) {
			for (int j=0;j<=M;j++)
				if (dp[j]>=i) {
					print(j,'\n');
					return 0;
				}
		}
	return 0;
}