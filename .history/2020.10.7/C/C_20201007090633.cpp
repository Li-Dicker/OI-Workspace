#include<bits/stdc++.h>
#define int long long
#define N 333
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;

int n,m,k,ans=0,res=0;
int tmp1,tmp2;
int edge[N][N];

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
	n=input(),m=input(),k=input();
	for (int i=1;i<=m;i++)
	{
		tmp1=input(),tmp2=input();
		edge[tmp1][tmp2]=edge[tmp2][tmp1]=1;
	}
	if (n<=15)
	{
		for (int S=0;S<=(1<<n)-1;S++)
		{
			res=0;
			for (int i=1;i<=n;i++)
				for (int j=1;j<=i-1;j++)
				{
					if (i==j)
						continue ;
					if (((S>>(i-1))&1)&&((S>>(j-1))&1)&&edge[i][j])
						res++;
				}
			if (k==2)
				res=res*res%MOD;
			else if (k==3)
				res=(res*res*res)%MOD;
			ans=(ans+res)%MOD;
		}
		print(ans,'\n');
	}
	else
		print(0,'\n');
	return 0;
}
/*
4 5 2
1 2
2 3
3 4
4 1
2 4
*/