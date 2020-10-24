#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define INF 0x3f3f3f3f
using namespace std;
int T,n,m,last,cnt;
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

int check(int a,int b,int c)
{
	if (a!=-1)
		return 0;
	else
	{
		if (b!=-1&&c!=-1)
			return 1;
		else
			
	}
}

signed main()
{
	T=input();
	loop:
	while (T--)
	{
		n=input(),m=input();
		for (int i=1;i<=n;i++)
			a[i]=input();
		if (a[1]!=-1&&a[2]!=-1&&a[3]!=-1)
		{
			if (a[1]+a[2]+a[3]<m)
			{
				puts("Impossible");
				goto loop;
			}
		}
		else
		{
			if (a[1]==-1&&a[2]!=-1&&a[3]!=-1)
				a[1]=m-a[2]-a[3];
			else if (a[1]!=-1&&a[2]==-1&&a[3]!=-1)
				a[2]=m-a[1]-a[3];
			else if (a[1]!=-1&&a[2]!=-1&&a[3]==-1)
				a[3]=m-a[1]-a[2];
			else if (a[1]==-1&&a[2]==-1&&a[3]!=-1)
				a[1]=0,a[2]=m-a[3];
			else if (a[1]==-1&&a[2]!=-1&&a[3]==-1)
				a[1]=0,a[3]=m-a[2];
			else if (a[1]!=-1&&a[2]==-1&&a[3]==-1)
				a[2]=0,a[3]=m-a[1];
			else if (a[1]==-1&&a[2]==-1&&a[3]==-1)
				a[1]=a[2]=-1,a[3]=m;
		}
		last=a[1]+a[2]+a[3];
		for (int i=4;i<=n;i++)
		{
			if (check(a[i],a[i+1],a[i+2])==0)
			{
				last=a[i-2]+a[i-1]+a[i];
				if (last<m)
				{
					puts("Impossible");
					goto loop;
				}
			}
			else if (check(a[i],a[i+1],a[i+2])==1)
			{
				a[i]=m-min(a[i-2]+a[i-1],a[i+1]+a[i+2]);
				last=a[i]+a[i-1]+a[i-2];
			}
			else if (check(a[i],a[i+1],a[i+2]==2))
			{
				a[i]
			}
		}
	}
	return 0;
}