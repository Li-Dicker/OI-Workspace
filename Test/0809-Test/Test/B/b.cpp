#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n,num;
int a[N];
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

int Rand(int k)
{
	int res=0;
	for (int i=1;i<=k;i++)
		res*=10,res+=(rand()*rand())%10;
	return res;
}

signed main()
{
	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	srand(time(NULL));
	n=input();
	for (int i=1;i<=n;i++)
		a[i]=input();
	sort(a+1,a+n+1);
	for (int i=1;i<=n-2;i++)
		if (a[i]==a[i+1]&&a[i+1]==a[i+2])
		{
			puts("Sorry Matsuri");
			return 0;
		}
	int k=Rand(7)%(n-1)+1;
	print(k,' '),print(n-k,'\n');
	for (int i=1;i<=k;i++)
		print(a[i],' ');
	puts("");
	for (int i=k+1;i<=n;i++)
		print(a[i],' ');
	puts("");
	return 0;
}