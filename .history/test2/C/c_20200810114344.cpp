#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define INF 0x3f3f3f3f
using namespace std;
int n,pointnum=0;
char s[N];
struct lyp
{
	int nxt,cnt;
	int son[33];
}tree[N];
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

	#undef int
}
using namespace IOstream;

namespace AC
{
	namespace Trie
	{
		void insert(char *s)
		{
			int len=strlen(s),u=0;
			for (int i=0;i<len;i++)
			{
				if (tree[u].son[s[i]-'a']==0)
					tree[u].son[s[i]-'a']=++pointnum;
				u=tree[u].son[s[i]-'a'];
			}
			tree[u].cnt++;
		}
	}
	void getnxt()
	{
		queue<int >q;
		for (int i=0;i<26;i++)
			if (tree[0].son[i]!=0)
			{
				tree[tree[0].son[i]].nxt=0;
				q.push(tree[0].son[i]);
			}
		int u=0;
		while (!q.empty())
		{
			u=q.front();
			q.pop();
			for (int i=0;i<26;i++)
			{
				if (tree[u].son[i]!=0)
				{
					tree[tree[u].son[i]].nxt=tree[tree[u].nxt].son[i];
					q.push(tree[u].son[i]);
				}
				else
					tree[u].son[i]=tree[tree[u].nxt].son[i];
			}
		}
	}
	int query(char *s)
	{
		int len=strlen(s),u=0,ans=0;
		for (int i=0;i<len;i++)
		{
			u=tree[u].son[s[i]-'a'];
			for (int j=u;j&&tree[j].cnt!=-1;j=tree[j].nxt)
			{
				ans+=tree[j].cnt;
				tree[j].cnt=-1;
			}
		}
		return ans;
	}
}

signed main()
{
	n=input();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		AC::Trie::insert(s);
	}
	tree[0].nxt=0;
	AC::getnxt();
	scanf("%s",s);
	print(AC::query(s),'\n');
	return 0;
}