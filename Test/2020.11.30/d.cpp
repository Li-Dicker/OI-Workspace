#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y1 _yy_
using namespace std;
namespace IOstream {
	#define print(a,b) prints(a),putchar(b)
	int BUF[22],BUFSIZE,IONUM,SIGN;
	char GET;

	inline int input() {
		IONUM=0,SIGN=1;
		GET=getchar();
		while (GET<'0'||GET>'9') {
			if (GET=='-')
				SIGN=-1;
			GET=getchar();
		}
		while (GET>='0'&&GET<='9') {
			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
			GET=getchar();
		}
		return SIGN*IONUM;
	}

	inline void prints(int IONUM) {
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

int n,flag1=1,flag2=1;

int Ans[N];

struct Point {
	int x,y,len,id;
	Point(){}
	Point(int x,int y):x(x),y(y){}
	bool operator < (const Point a) const {
		if (x==a.x)
			return y<a.y;
		return x<a.x;
	}
}point[N];

map<pair<int ,int >,int >mp;

bool cmp(Point a,Point b) {
	return a.id<b.id;
}

void work(int x) {
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (i==x)
			continue ;
		if (abs(point[x].x-point[i].x)+abs(point[x].y-point[i].y)<=point[i].len)
			ans++;
	}
	print(ans,' ');
}

void doit(int x) {
	int l=lower_bound(point+1,point+n+1,Point(point[x].x-point[x].len,point[x].y))-point;
	int r=upper_bound(point+1,point+n+1,Point(point[x].x+point[x].len,point[x].y))-point-1;
	Ans[point[x].id]=r-l+1;
}

signed main() {
	freopen("d.in","r",stdin);freopen("d.out","w",stdout);
	n=input();
	for (int i=1;i<=n;i++) {
		point[i].x=input(),point[i].y=input(),point[i].len=input();
		point[i].id=i;
		if (point[i].y!=point[1].y)
			flag1=0;
		if (point[i].len>1)
			flag2=0;
	}
	if (flag1==1) {
		sort(point+1,point+n+1);
		for (int i=1;i<=n;i++)
			doit(i);
		for (int i=1;i<=n;i++)
			print(Ans[i],' ');
		return 0;
	}
	if (flag2==1) {
		for (int i=1;i<=n;i++)
			mp[make_pair(point[i].x,point[i].y)]=1;
		for (int i=1;i<=n;i++) {
			int ans=0;
			if (mp[make_pair(point[i].x+1,point[i].y)]==point[i].len)
				ans++;
			if (mp[make_pair(point[i].x-1,point[i].y)]==point[i].len)
				ans++;
			if (mp[make_pair(point[i].x,point[i].y+1)]==point[i].len)
				ans++;
			if (mp[make_pair(point[i].x,point[i].y-1)]==point[i].len)
				ans++;
			print(ans,' ');
		}
		return 0;
	}
	for (int i=1;i<=n;i++)
		work(i);
	return 0;
}
