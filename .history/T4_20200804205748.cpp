#include<bits/stdc++.h>
#define int long long
#define N 333333
#define INF 0x3f3f3f3f
using namespace std;

int T,n,q;
int s[N];
char a[N];
struct lyp
{
	int val,lzy;
}tree[N<<2];

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

bool check_black(char x,char y)
{
	if ((x=='o'&&y=='b')||(x=='b'&&y=='o')||(x=='p'&&y=='y')||(x=='y'&&y=='p')||(x=='g'&&y=='r')||(x=='r'&&y=='g'))
		return 1;
	return 0;
}

void pushup(int x)
{
	tree[x].val=max(tree[x<<1].val,tree[x<<1|1].val);
}

void build(int l,int r,int x);

signed main()
{
	T=input();
	while (T--)
	{
		n=input(),q=input();
		a[1]=getchar();
		for (int i=2;i<=n;i++)
			a[i]=getchar(),s[i-1]=check_black(a[i-1],a[i]);
		build(1,n,1);
	}
	return 0;
}