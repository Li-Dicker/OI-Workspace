#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n,ans=0;
int a[N],b[N];
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

void getbasic()
{
	for (int i=1;i<=n;i++)
		for (int j=63;j>=0;j--)
		{
			if (!(a[i]>>j))
				continue ;
			if (!b[j])
			{
				b[j]=a[i];
				for (int k=j-1;k>=0;k--)
					if (b[j]>>k&1)
						b[j]^=b[k];
				for (int k=j+1;k<=63;k++)
					if (b[k]>>j&1)
						b[k]^=b[j];
				break ;
			}
			a[i]^=b[j];
		}
}

signed main()
{
	n=input();
	for (int i=1;i<=n;i++)
		a[i]=input();
	getbasic();
	for (int i=0;i<=63;i++)
		ans^=b[i];
	print(ans,'\n');
	return 0;
}