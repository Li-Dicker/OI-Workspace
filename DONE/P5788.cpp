#include<bits/stdc++.h>
#define int long long
#define N 3333333
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

int n,a;
int f[N];
stack<pair<int ,int > >sta;

signed main()
{
	n=input();
	for (int i=1;i<=n;i++)
	{
		a=input();
		while (!sta.empty()&&sta.top().first<a)
			f[sta.top().second]=i,sta.pop();
		sta.push(make_pair(a,i));
	}
	for (int i=1;i<=n;i++)
		print(f[i],' ');
	puts("");
	return 0;
}