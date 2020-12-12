#include<bits/stdc++.h>
#define int long long
#define N 555555
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

int T,n,ans,s,flag1=1,flag2=1;
int a[N],ten[N],jc[N];
map<int ,int >mp;

void sswap(int x,int y) {
	int dx=(s%ten[x])/ten[x-1],dy=(s%ten[y])/ten[y-1];
	s-=dx*ten[x-1],s+=dy*ten[x-1];
	s-=dy*ten[y-1],s+=dx*ten[y-1];
}

void dfs(int pos) {
	if (pos==n+1) {
		if (mp[s]!=1)
			mp[s]=1,ans++;
		return ;
	}
	dfs(pos+1);
	if (a[pos]==1) {
		a[pos]--;
		for (int i=1;i<=n;i++) {
			if (i==pos||a[i]==0)
				continue ;
			sswap(pos,i);
			a[i]--;
			dfs(pos+1);
			sswap(pos,i);
			a[i]++;
		}
		a[pos]++;
	}
	if (a[pos]==2) {
		a[pos]--;
		for (int i=1;i<=n;i++) {
			if (i==pos||a[i]==0)
				continue ;
			sswap(pos,i);
			a[i]--;
			dfs(pos+1);
			a[pos]--;
			for (int j=1;j<=n;j++) {
				if (j==pos||a[j]==0)
					continue ;
				sswap(pos,j);
				a[j]--;
				dfs(pos+1);
				sswap(pos,j);
				a[j]++;
			}
			a[pos]++;
			sswap(pos,i);
			a[i]++;
		}
		a[pos]++;
	}
}

void init() {
	jc[1]=1;
	for (int i=2;i<=500005;i++)
		jc[i]=(jc[i-1]*i)%MOD;
}

signed main() {
	freopen("throw.in","r",stdin);freopen("throw.out","w",stdout);
	T=input();
	init();
	while (T--) {
		flag1=flag2=1;
		n=input();
		for (int i=1;i<=n;i++) {
			a[i]=input();
			if (a[i]!=1)
				flag1=0;
			if (a[i]!=2)
				flag2=0;
		}
		if (flag2==1) {
			print(jc[n],'\n');
			continue ;
		}
		if (n<=10) {
			s=0,ans=0;
			ten[0]=1;
			for (int i=1;i<=n;i++)
				s*=10,s+=i-1,ten[i]=ten[i-1]*10;
			dfs(1);
			print(ans,'\n');
		}
	}
	return 0;
}//1,2,4,10,26,76,232,764,2620

