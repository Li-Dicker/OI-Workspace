#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;

int n,k,edgenum=0,segnum=0;
int tmp1,tmp2;
int head[N],vis[N];
struct Edge
{
    int v,next;
}edge[N<<1];
struct Segments
{
    int maxn,minn;
}seg[N];

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

void adde(int u,int v)
{
    edge[++edgenum].next=head[u];
    head[u]=edgenum;
    edge[edgenum].v=v;
}

void dfs(int u)
{
    seg[segnum].maxn=max(seg[seg].maxn,)
}

signed main()
{
	n=input(),k=input();
    for (int i=1;i<=k;i++)
    {
        tmp1=input(),tmp2=input();
        adde(tmp1,tmp2);
        adde(tmp2,tmp1);
    }
    for (int i=1;i<=k;i++)
        if (!vis[i])
            dfs(i);
    return 0;
}