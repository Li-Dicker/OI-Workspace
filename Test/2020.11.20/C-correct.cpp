#include<bits/stdc++.h>
#define N 555555
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y1 _yy_
using namespace std;
namespace IOstream
{
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

int n;
int origin[N*2],sum[N*2],tong[N*2];

struct Point
{
	int x,y,z;
}point[N*2],ans[N*2];

bool cmp(Point a,Point b)
{
	if (abs(a.x-a.y)==abs(b.x-b.y))
		return min(a.x,a.y)<min(b.x,b.y);
	return abs(a.x-a.y)<abs(b.x-b.y);
}

bool cmpans(Point a,Point b)
{
	if (a.z==b.z)
	{
		if (a.y-a.x==b.y-b.x)
			return a.x<b.x;
		return a.y-a.x<b.y-b.x;
	}
	return a.z>b.z;
}

signed main()
{
	n=input();
	sum[0]=0;
	for (int i=1;i<=n;i++)
	{
		origin[i]=point[i].x=input(),point[i].y=i;
		point[i].z=abs(point[i].x+point[i].y)/2+(abs(point[i].x-point[i].y)%2==1)*n;
		sum[i]=sum[i-1]+(point[i].x==point[i].y);
	}
	sort(point+1,point+n+1,cmp);
	memset(tong,0,sizeof(tong));
	for (int i=1;i<=n;i++)
	{
		tong[point[i].z]++;
		ans[i].x=min(point[i].x,point[i].y),ans[i].y=max(point[i].x,point[i].y);
		ans[i].z=tong[point[i].z]-(sum[ans[i].y]-sum[ans[i].x-1]);
	}
	sort(ans+1,ans+n+1,cmpans);
	if (ans[1].x==ans[1].y)
		puts("1 1");
	else
		print(origin[ans[1].x],' '),print(origin[ans[1].y],'\n');
	return 0;
}
/*
1910 734
734 1037
*/