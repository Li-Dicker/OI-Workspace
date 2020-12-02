#include<bits/stdc++.h>
#define int long long
#define N 2222
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

int n,k,sum=0;
int a[N],vis[N];

bool cmp(int a,int b) {
	return a>b;
}

bool check(int w) {
	memset(vis,0,sizeof(vis));
	int num=0,cnt=0,now=0;
	while (num<n) {
		cnt++,now=0;
		if (cnt>k)
			return false;
		for (int i=1;i<=n;i++)
			if (vis[i]==0&&now+a[i]<=w)
				now+=a[i],vis[i]=1,num++;
	}
	return true;
}

signed main() {
	freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	n=input(),k=input();
	for (int i=1;i<=n;i++)
		a[i]=input(),sum+=a[i];
	sort(a+1,a+n+1,cmp);
//	for (int i=a[1];i<=sum;i++)
//		if (check(i)) {
//			print(i,'\n');
//			return 0;
//		}
	int l=a[1],r=sum,mid;
	while (l<r) {
		mid=(l+r)>>1;
		if (!check(mid))
			l=mid+1;
		else
			r=mid;
	}
	print(l,'\n');
	return 0;
}
/*
6 2
3 2 4 4 4 7
*/
