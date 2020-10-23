#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn=1e6+1;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
const int p=1e9+7;
#define int long long
template<class T>inline void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s&15);s=getchar();};
	x*=f;
}
inline int min(int a,int b) { return a<b?a:b; }
int n,m,a[maxn],pre[maxn],suf[maxn],all,ans1,ans2,X,Ans;
inline int get(int x) { return (((2*x)/(1<<n))+2*x)%(1<<n); }
signed main() {
	read(n); read(m); all=(1<<n)-1;
	rep(i,1,m) read(a[i]);
	rep(i,1,m) pre[i]=(pre[i-1]^a[i]);
	per(i,m,1) suf[i]=(suf[i+1]^a[i]);
	rep(x,0,all) {
		Ans=-1;
		rep(i,0,m) {
			X=get(x^pre[i]);
			X^=suf[i+1];
			if(Ans<0) Ans=X;
			else Ans=min(Ans,X);
		}
		if(Ans>ans1) ans1=Ans,ans2=1;
		else if(Ans==ans1) ans2++;
	}
	printf("%lld %lld\n",ans1,ans2);
}