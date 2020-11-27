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

int n,m,tmpe,maxn=-INF;
int arr[N],pre[N],suf[N];

bool check(int x,int op) {
	int tmp1=tmpe,tmp2,tmp3;
	if (op==1)
		tmp2=pre[x];
	else
		tmp2=suf[x];
	tmp3=max(tmp1,tmp2);
	while (tmp3>0) {
		if ((tmp2&1)<(tmp1&1))
			return false;
		tmp2>>=1,tmp1>>=1,tmp3>>=1;
	}
	return true;
}

bool find(int x) {
	if (x>maxn)
		return false;
	int l=1,r=n,mid,tmp1,tmp2;
	while (l<r) {
		mid=(l+r)>>1;
		if (check(mid,1)==0)
			l=mid+1;
		else
			r=mid;
	}
	tmp1=l;
	l=1,r=n;
	while (l<r) {
		mid=(l+r)>>1;
		if (check(mid,2)!=0)
			l=mid+1;
		else
			r=mid;
	}
	tmp2=l-(check(l,2)==0);
	if (tmp1>tmp2)
		return false;
	return true;
}

signed main() {
	// freopen("in.txt","r",stdin);
	n=input(),m=input();
	for (int i=1;i<=n;i++)
		arr[i]=input(),maxn=max(maxn,arr[i]);
	sort(arr+1,arr+n+1);
	pre[1]=arr[1];
	for (int i=2;i<=n;i++)
		pre[i]=pre[i-1]|arr[i];
	suf[n]=arr[n];
	for (int i=n-1;i>=1;i--)
		suf[i]=suf[i+1]|arr[i];
	while (m--) {
		tmpe=input();
		if (find(tmpe))
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
/*
4 10
2 5 9 12
3
4
5
6
7
8
9
10
11
12
*/