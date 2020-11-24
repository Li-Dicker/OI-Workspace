#include<bits/stdc++.h>
#define int long long
#define N 111111
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

int n,m;
int tmp1,tmp2;
int Log[N];
int f[N][22];

int query(int l,int r)
{
	int k=Log[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}

signed main()
{
	n=input(),m=input();
	for (int i=1;i<=n;i++)
		f[i][0]=input();
	for (int j=1;j<=22;j++)
		for (int i=1;i+(1<<j)<=n+1;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	Log[1]=0,Log[2]=1;
	for (int i=3;i<=n;i++)
		Log[i]=Log[i/2]+1;
	while (m--)
	{
		tmp1=input(),tmp2=input();
		print(query(tmp1,tmp2),'\n');
	}
	return 0;
}