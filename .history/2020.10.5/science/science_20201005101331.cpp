#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;

int n,q,lnum=0,rnum=0;
int pos[N],des;
char dest[N];
struct Point
{
	int id,pos;
}ld[N],rd[N];

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

bool cmp(Point a,Point b)
{
	return a.pos<b.pos;
}

signed main()
{
	n=input(),q=input();
	for (int i=0;i<n;i++)
		pos[i]=input();
	cin>>dest;
	for (int i=0;i<n;i++)
	{
		if (dest[i]=='L')
			des[i]=0,ld[++lnum].id=i,ld[lnum].pos=pos[i];
		else
			des[i]=1,rd[++rnum].id=i,rd[rnum].pos=pos[i];
	}
	sort(ld+1,ld+lnum+1,cmp);
	sort(rd+1,rd+rnum+1,cmp);
	return 0;
}