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
bool Map[1001][1001];
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
			while(1==1)
			{
				if (!tmp1)
					break ;
				if (!Map[tmp1][tmp2]&&k[tmp1]>0)
					ans[tmp1]++;
				Map[tmp1][tmp2]=1;
				k[tmp1]--;
				tmp1=fa[tmp1];
			}
        }
		q=input();
        while(q--)
        {
			print(ans[tmp1=input()],'\n');
			
        }
	}
}sub1;

int main()
{
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
    if (n<=1000&&m<=1000)
		sub1.solve();
    return 0;
}