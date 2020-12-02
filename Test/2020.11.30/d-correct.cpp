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

int n,lim;
int tmp1,tmp2,a,b,c,d;
int ans[N];

vector<int >A,B,mp[N];
vector<pair<int ,int > >s[N];

struct Point {
	int x,y,d;
}point[N];

namespace Tree {
	int tree[N<<1];

	int lowbit(int x) {
		return x&(-x);
	}

	void updata(int x,int y) {
		while (x<=lim) {
			tree[x]+=y;
			x+=lowbit(x);
		}
	}

	int query(int x) {
		int res=0;
		while (x>0) {
			res+=tree[x];
			x-=lowbit(x);
		}
		return res;
	}
}

signed main()
{
	n=input();
	for (int i=1;i<=n;i++) {
		tmp1=input(),tmp2=input(),point[i].d=input();
		A.push_back(point[i].x=tmp1+tmp2);
		B.push_back(point[i].y=tmp1-tmp2);
	}
	sort(A.begin(),A.end()),sort(B.begin(),B.end());
	A.resize(unique(A.begin(),A.end())-A.begin());
	B.resize(unique(B.begin(),B.end())-B.begin());
	lim=B.size();
	for (int i=1;i<=n;i++) {
		a=lower_bound(A.begin(),A.end(),point[i].x-point[i].d)-A.begin()+1;
		b=upper_bound(A.begin(),A.end(),point[i].x+point[i].d)-A.begin();
		c=lower_bound(B.begin(),B.end(),point[i].y-point[i].d)-B.begin()+1;
		d=upper_bound(B.begin(),B.end(),point[i].y+point[i].d)-B.begin();
		mp[a].push_back(c),mp[b+1].push_back(-c);
		mp[a].push_back(-d-1),mp[b+1].push_back(d+1);
	}
	for (int i=1;i<=n;i++)
		s[lower_bound(A.begin(),A.end(),point[i].x)-A.begin()+1].push_back(make_pair(lower_bound(B.begin(),B.end(),point[i].y)-B.begin()+1,i));
	for (int i=1;i<=A.size();i++) {
		for (int j=0;j<mp[i].size();j++)
			Tree::updata(abs(mp[i][j]),(mp[i][j]>0)?1:-1);
		for (int j=0;j<s[i].size();j++)
			ans[s[i][j].second]=Tree::query(s[i][j].first)-1;
	}
	for (int i=1;i<=n;i++)
		print(ans[i],' ');
	return 0;
}