#include<bits/stdc++.h>
#define _int long long
#define INF 0x3f3f3f3f
#define N 111111
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

class TheCowDivOne
{
	private:
	_int n,k;

	public:
	#undef N
	int find(int N,int K)
	{
		n=N,k=K;
	}
}problem;

signed main()
{
	int n,k;
	n=input(),k=input();
	print(problem.find(n,k),'\n');
	return 0;
}