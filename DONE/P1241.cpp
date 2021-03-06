#include<bits/stdc++.h>
#define int long long
#define N 111
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
int vis[N];
char s[N];
stack<int >sta;

signed main()
{
	cin>>s+1;
	len=strlen(s+1);
	for (int i=1;i<=len;i++)
	{
		if (s[i]==')')
		{
			if (sta.empty()||s[sta.top()]!='(')
				vis[i]=1;
			else
				sta.pop();
		}
		else if (s[i]==']')
		{
			if (sta.empty()||s[sta.top()]!='[')
				vis[i]=1;
			else
				sta.pop();
		}
		else if (s[i]=='('||s[i]=='[')
			sta.push(i);
	}
	while (!sta.empty())
		vis[sta.top()]=1,sta.pop();
	for (int i=1;i<=len;i++)
	{
		if (vis[i]==1)
		{
			if (s[i]==')')
				putchar('(');
			else if (s[i]==']')
				putchar('[');
		}
		putchar(s[i]);
		if (vis[i]==1)
		{
			if (s[i]=='(')
				putchar(')');
			else if (s[i]=='[')
				putchar(']');
		}
	}
	puts("");
	return 0;
}