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

struct Sub2
{
	private:

	bool cmp(node a,node b){return a.c<b.c;}
	void add(int x,int y)
	{
		e[++cnt].nxt=head[x];
		e[cnt].to=y;
		head[x]=cnt;
	}
	void insert(int &x,int k,int l,int r)
	{
		if(!x)x=++tot;
		if(l==r)
		{
			trsum[x]=1;
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)insert(ls[x],k,l,mid);
		else insert(rs[x],k,mid+1,r);
		trsum[x]=trsum[ls[x]]+trsum[rs[x]];
	}
	int merge(int x,int fl,int l,int r)//合并
	{
		if(!x||!fl)return x+fl;
		if(l==r)
		{
			trsum[x]=trsum[x]||trsum[fl];
			return x;
		}
		int mid=(l+r)>>1;
		ls[x]=merge(ls[x],ls[fl],l,mid);
		rs[x]=merge(rs[x],rs[fl],mid+1,r);
		trsum[x]=trsum[ls[x]]+trsum[rs[x]];
		return x;
	}
	void dfs(int x)
	{
		vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt)
			if(!vis[e[i].to])
			{
				dfs(e[i].to);
				root[x]=merge(root[x],root[e[i].to],1,M);
			}
		ans[x]=trsum[root[x]];
	}
	void solve()
	{
		scanf("%d",&N);
		for(int i=1;i<N;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		for(int i=1;i<=N;i++)
			scanf("%d",&k[i]);
		scanf("%d",&M);
		for(int i=1;i<=M;i++)
			scanf("%d%d",&q[i].x,&q[i].c);
		sort(q+1,q+M+1,cmp);
		for(int i=1;i<=M;i++)
		{
			if(q[i].c!=q[i-1].c)sum++;//算是一个预处理吧，思路有些清奇
			insert(root[q[i].x],sum,1,M);
		}
		dfs(1);
		scanf("%d",&Q);
		while(Q--)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",ans[x]);
		}
		return 0;
	}
}sub2;

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