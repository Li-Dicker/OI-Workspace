#include<bits/stdc++.h>
#define int long long
#define N 1111111
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

int n,k,cnt,flag=0;
bool vis[21];

struct Premutation {
	int bit[21],pos;

	void init() {
		pos=n>9?9:n;
		if (n>9)
			flag=1;
		for (int i=1;i<=n;i++)
			bit[i]=0;
	}
}ans[N],now;

bool cmp(Premutation x,Premutation y)
{
	if (flag==1&&x.bit[1]!=y.bit[1]) {
		if (x.bit[1]<y.bit[1])
			return 1;
		return 0;
	}
	for (int i=2;i<=x.pos;i++) {
		int X=x.bit[i]-x.bit[i-1],Y=y.bit[i]-y.bit[i-1];
		if (X==Y)
			continue ;
		if (X<Y)
			return 1;
		return 0;
	}
	return 0;
}

void next_permutation(int u) {
	if (!u) {
		ans[++cnt]=now;
		return ;
	}
	for (int i=1;i<=n;i++) {
		if (vis[i])
			continue ;
		vis[i]=1;
		now.bit[n-u+1]=i;
		next_permutation(u-1);
		vis[i]=0;
	}
}

signed main() {
	n=input(),k=input();
	if (n>9) {
		now.init();
		print(n--,' ');
		int num=0;
		for (int i=1;i<=n-9;i++)
			print(i,' '),num=i;
		n=9;
		next_permutation(9);
		sort(ans+1,ans+cnt+1,cmp);
		for(int i=1;i<=9;i++)
			print(ans[k].bit[i]+num,' ');
	}
	else {
		now.init();
		next_permutation(n);
		sort(ans+1,ans+cnt+1,cmp);
		for(int i=1;i<=n;i++)
			print(ans[k].bit[i],' ');
	}
	puts("");
	return 0;
}