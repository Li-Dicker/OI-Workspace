#include<bits/stdc++.h>
#define int long long
#define N 333333
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

int n,m,ans1=0,ans2=0;
int op,tmp1,tmp2,pos;
int s[3][N],a[3][N];

signed main()
{
	n=input(),m=input();
	for (int i=1;i<=n;i++)
		a[1][i]=s[1][i]=input();
	sort(s[1]+1,s[1]+n+1);
	for (int i=1;i<=n;i++)
		a[2][i]=s[2][i]=input();
	sort(s[2]+1,s[2]+n+1);
	for (int i=1;i<=n;i++)
		ans1+=s[1][i]*s[2][n-i+1],ans2+=s[1][i]*s[2][i];
	print(ans1,' '),print(ans2,'\n');
	while (m--)
	{
		op=input(),tmp1=input(),tmp2=input();
		if (tmp2==1)
			pos=upper_bound(s[op]+1,s[op]+n+1,a[op][tmp1])-s[op]-1;
		else
			pos=lower_bound(s[op]+1,s[op]+n+1,a[op][tmp1])-s[op];
		ans1+=tmp2*s[1+op%2][n-pos+1],ans2+=tmp2*s[1+op%2][pos];
		s[op][pos]+=tmp2;
		a[op][tmp1]+=tmp2;
		print(ans1,' '),print(ans2,'\n');
	}
	return 0;
}