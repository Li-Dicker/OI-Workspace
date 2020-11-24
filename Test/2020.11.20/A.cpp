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

int n,len,ans=0;
char s[N];

signed main()
{
	n=input();
	while (n--)
	{
		ans=0;
		while (1==1)
		{
			scanf("%s",s);
			len=strlen(s);
			if (s[0]>='A'&&s[0]<='Z')
			{
				int flag=0;
				for (int i=1;i<len;i++)
					if (!(s[i]>='a'&&s[i]<='z'||(s[i]=='.'||s[i]=='?'||s[i]=='!')))
					{
						flag=1;
						break ;
					}
				if (!flag)
					ans++;
			}
			if (s[len-1]=='.'||s[len-1]=='?'||s[len-1]=='!')
				break ;
		}
		print(ans,'\n');
	}
	return 0;
}