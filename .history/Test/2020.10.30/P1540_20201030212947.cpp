#include<bits/stdc++.h>
#define int long long
#define N 1111
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

int n,m,ans;
int tmp1;
int vis[N];

class QUEUE
{
	private:

	int head=1,tail=0;
	int q[N<<1];

	public:

	bool empty()
	{
		return tail>=head;
	}

	void push(int x)
	{
		vis[x]=1;
		q[++tail]=x;
	}

	int top()
	{
		return q[head];
	}

	void pop()
	{
		vis[q[head]]=0;
		head++;
	}

	int size()
	{
		return tail-head+1;
	}
}q;

signed main()
{
	n=input(),m=input();
	for (int i=1;i<=n;i++)
	{
		tmp1=input();
		if (!vis[tmp1])
		{
			if (q.size()==m)
			{
				q.pop();
				ans++;
			}
			q.push(tmp1);
		}
	}
	ans+=q.size();
	print(ans,'\n');
	return 0;
}