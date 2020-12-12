#include<bits/stdc++.h>
#define int long long
#define N 1111111
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

int n,q;
int tmp1,tmp2,tmp3;
int a[N];

namespace Tree {
	int tree1[N],tree2[N];

	int lowbit(int x) {
		return x&(-x);
	}

	void updata(int x,int y) {
		for (int i=x;i<=n;i+=lowbit(i))
			tree1[i]+=y,tree2[i]+=(x-1)*y;
	}

	int query(int x) {
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))
			res+=tree1[i]*x,res-=tree2[i];
		return res;
	}
}

signed main() {
	n=input(),q=input();
	for (int i=1;i<=n;i++) {
		a[i]=input();
		Tree::updata(i,a[i]-a[i-1]);//差分存储
	}	
	while (q--) {
		tmp1=input(),tmp2=input(),tmp3=input();
		if (tmp1==1) {
			tmp1=input();
			Tree::updata(tmp2,tmp1);
			Tree::updata(tmp3+1,-tmp1);//区间差分为两个前缀和
		}
		else
			print(Tree::query(tmp3)-Tree::query(tmp2-1),'\n');
	}
	return 0;
}