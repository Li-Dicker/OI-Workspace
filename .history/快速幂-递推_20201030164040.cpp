#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
// #define MOD ((int)1e9+7)
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

int b,p,MOD;

// @return (x^k)%MOD 的值
int ksm(int x,int k,int MOD)
{
	if (k==1)
		return x%MOD;
	else if (k==0)
		return 1;
	int res=1;
	if (k&1)
		res*=x;
	return (res*ksm(x*x%MOD,k>>1,MOD))%MOD;
}

signed main()
{
	b=input(),p=input(),MOD=input();
	printf("%lld^%lld mod %lld=",b,p,MOD);
	print(ksm(b,p,MOD),'\n');
	return 0;
}