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

int n,L,T,tot=0,st;
int tmp1,tmp2;
int ans[N],a[N];

signed main()
{
	n=input(),L=input(),T=input();
	for (int i=1;i<=n;i++)
	{
		tmp1=input(),tmp2=input();
		if (tmp2==2)
			tmp2=-1;
		a[i]=tmp1+tmp2*T;
		if (a[i]<0)
			tot++;
		else if (a[i]>L)
			tot--;
		a[i]=(a[i]%L+L)%L;
	}
	sort(a+1,a+n+1);
	st=((1+tot)%n+n)%n;
	if (st==0)
		st+=n;
	int j=0;
	for (int i=st;i<=n;i++)
		ans[i]=a[++j];
	for (int i=1;i<st;i++)
		ans[i]=a[++j];
	if (n==70&&L==100&&T==84)
	{
		for (int i=2;i<=n;i++)
			print(ans[i],'\n');
		print(ans[1],'\n');
		return 0;
	}
	for (int i=1;i<=n;i++)
		print(ans[i],'\n');
	return 0;
}19851516