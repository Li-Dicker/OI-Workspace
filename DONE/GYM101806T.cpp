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

int n,ans=0,hight=0;
pair<int ,int >s[N];
priority_queue<int >q;

signed main()
{
	n=input();
	for (int i=1;i<=n;i++)
	{
		s[i].first=input(),s[i].second=input();
		s[i].first+=s[i].second;//将能达到的最高高度作为第一关键字
	}
	sort(s+1,s+n+1);//以理论最高高度作为关键字从小到大排序
	for (int i=1;i<=n;i++)
	{
		hight+=s[i].second;//加上这一个点能加的高度
		q.push(s[i].second);//将这一次增加的高度放入堆中（大根堆）
		ans++;//更新答案数量
		if (hight>s[i].first)//如果现在的高度超过了这个点的理论最高高度
		{
			hight-=q.top();//将堆中的最大的增加高度删除（一个贪心的思想，因为增加的高度越大，能用的数量就越小，所以一定是考虑删除对高度贡献最大的）
			ans--;//（答案数量减
			q.pop();
		}
	}
	print(ans,'\n');
	return 0;
}
/*
4
0 10
2 4
5 3
8 2
*/