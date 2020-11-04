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
	int res=ksm(x,k>>1,MOD)%MOD;
	res=res*res%MOD;
	if (k&1)
		res=res*x%MOD;
	return res%MOD;
}

signed main()
{
	b=input(),p=input(),MOD=input();
	if (b==0&&p==0)
	{
		printf("%lld^%lld mod %lld=0\n",b,p,MOD);
		return 0;
	}
	printf("%lld^%lld mod %lld=",b,p,MOD);
	print(ksm(b,p,MOD),'\n');
	return 0;
}