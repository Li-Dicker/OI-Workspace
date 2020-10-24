#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n,m,r0,c0;
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

signed main()
{
	// T=input();
	n=input(),m=input();
	r0=input(),c0=input();
	adde(1,2),adde(1,m+1);
	adde(m,m-1),adde(m,2*m);
	adde((n-1)*m+1,(n-2)*m+1),adde((n-1)*m+1,(n-1)*m+2);
	adde(n*m,n*m-1),adde(n*m,(n-1)*m);
	for (int i=2;i<m;i++)
	{
		adde(i,i-1),adde(i,i+1),adde(i,m+i);
		adde((n-1)*m+i,(n-1)*m+i-1),adde((n-1)*m+i,(n-1)*m+i+1),adde((n-2)*m+i);
	}
	for (int i=2;i<n;i++)
	{
		adde((i-1)*m+1,(i-2)*m+1),adde((i-1)*m+1,i*m+1),adde((i-1))
	}
	return 0;
}