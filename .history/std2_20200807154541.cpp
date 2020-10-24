#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
#define PII 3.141592653589793
using namespace std;
int T,a,b,c,d;
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

bool check(double x1,double y1,double x2,double y2)
{
	if (x1>=x2&&y1>=y2)
		return true;
	else if (x1<x2&&y1<y2)
		return false;
	x1=x1/2.0,y1=y1/2.0,x2=x2/2.0,y2=y2/2.0;
	double l1=sqrt(x1*x1+y1*y1),l2=sqrt(x2*x2+y2*y2),tmpe,t1,t2;
	if (l1<l2)
		return false;
	if (l2<=x1)
		t1=0;
	else
	{
		t1=atan2(sqrt(l2*l2-x1*x1),x1)*180/PII;
	}
	if (l2<=y1)
		t2=0;
	else
	{
		t2=atan2(sqrt(l2*l2-y1*y1),y1)*180/PII;
	}
	return atan2(x2,y2)*180/PII*2<=(90-t1-t2);
}

signed main()
{
	T=input();
	while (T--)
	{
		a=input(),b=input(),c=input(),d=input();
		if (a>b)
			swap(a,b);
		if (c>d)
			swap(c,d);
		if (check(a,b,c,d)||check(c,d,a,b))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}