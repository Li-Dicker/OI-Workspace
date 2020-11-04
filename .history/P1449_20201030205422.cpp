#include<bits/stdc++.h>
#define int long long
#define N 1111
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

int len;
int tmp1,tmp2,tmp3;
char ch;
struct STACK
{
	int val[N],head=0;
	int top()
	{
		return val[head];
	}
	
}sta;

signed main()
{
	while (ch=getchar())
	{
		if (ch>='0'&&ch<='9')
			tmp1*=10,tmp1+=(ch-'0');
		else
		{
			if (ch=='@')
			{
				print(sta.top(),'\n');
				return 0;
			}
			if (ch=='.')
				sta.push(tmp1),tmp1=0;
			else
			{
				tmp3=sta.top(),sta.pop();
				tmp2=sta.top(),sta.pop();
				if (ch=='+')
					sta.push(tmp2+tmp3);
				else if (ch=='-')
					sta.push(tmp2-tmp3);
				else if (ch=='*')
					sta.push(tmp2*tmp3);
				else if (ch=='/')
					sta.push(tmp2/tmp3);
			}
		}
	}
	return 0;
}