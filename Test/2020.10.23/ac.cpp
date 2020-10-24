#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
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

int n,m,q,edgenum=0;
int tmp1,tmp2;
int head[N],k[N],fa[N],ans[N];
bool mp[1111][1111];
struct Edge
{
    int next,v;
}edge[N<<1];

void adde(int u,int v)
{
    edge[++edgenum].next=head[u];
    head[u]=edgenum;
    edge[edgenum].v=v;
}

class Sub1
{
	private:

	void dfs(int u)
	{
		for (int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].v;
			if (v==fa[u])
				continue ;
			fa[v]=u;
			dfs(v);
		}
	}

	public: 

	void solve()
	{
        dfs(1);
        while (m--)
        {
			tmp1=input(),tmp2=input();
			while (1==1)
			{
				if (!tmp1)
					break ;
				if (!mp[tmp1][tmp2]&&k[tmp1]>0)
					ans[tmp1]++;
				mp[tmp1][tmp2]=1;
				k[tmp1]--;
				tmp1=fa[tmp1];
			}
        }
		q=input();
        while (q--)
			print(ans[input()],'\n');
	}

}sub1;

// struct Sub2
// {
	
// }sub2;

signed main()
{
	freopen("ac.in","r",stdin);freopen("ac.out","w",stdout);
	n=input();
    for (int i=1;i<n;i++)
    {
		tmp1=input(),tmp2=input();
		adde(tmp1,tmp2);
		adde(tmp2,tmp1);
    }
    for (int i=1;i<=n;i++)
		k[i]=input();
	m=input();
    // if (n<=1000&&m<=1000)
		sub1.solve();
    return 0;
}
/*
5
1 2
2 3
3 4
2 5
2 1 1 1 1
2
2 1
4 2
3
1
3
5

10
3 10
2 5
3 2
2 6
1 9
8 7
7 4
3 8
3 1
15 47 23 22 9 16 45 39 21 13
10
10 7
9 3
5 1
5 2
9 4
10 9
2 4
10 1
2 6
7 9
3
1
2
3
*/