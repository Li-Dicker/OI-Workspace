#include<bits/stdc++.h>
#define int long long
#define N
#define M 1111
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;

int n,q;
int op,tmp1,tmp2;
int sum[M][M];
struct operation
{
	int op,l,r;
}opt[N];

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
	n=input(),q=input();
	for (int i=1;i<=n;i++)
		sum[0][i]=0;
	for (int i=1;i<=q;i++)
	{
		op=input(),tmp1=input(),tmp2=input();
		if (op==1)
		{
			for (int j=1;j<tmp1;j++)
				sum[i][j]=sum[i-1][j];
			for (int j=tmp1;j<=tmp2;j++)
				sum[i][j]=(sum[i-1][j]+1)%MOD;
			for (int j=tmp2+1;j<=n;j++)
				sum[i][j]=sum[i-1][j];
		}
		else if (op==2)
		{
			for (int j=1;j<=n;j++)
				sum[i][j]=(sum[i-1][j]+sum[tmp2][j]-sum[tmp1-1][j])%MOD;
		}
	}
	for (int i=1;i<=n;i++)
		print(sum[q][i]%MOD,' ');
	puts("");
	return 0;
}
/*
5 5
1 1 2
1 4 5
2 1 2
2 1 3
2 3 4
*/