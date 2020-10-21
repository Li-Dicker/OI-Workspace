#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;

int n,k,q,edgenum=0,segnum=0,qnum=1;
int tmp1,tmp2;
int head[N],vis[N],ans[N];
struct Edge
{
    int v,next;
}edge[N<<1];
struct Segments
{
    int maxn,minn;
}seg[N];
struct CHECKER
{
    int maxn=-INF,minn=INF;
    int ecnt=0,pcnt=0;

    void init()
    {
        maxn=-INF,minn=INF,ecnt=0,pcnt=0;
    }

    bool checker()
    {
        return ecnt==pcnt-1;
    }
    
}kuai;
struct query
{
    int l,r,id,ans;
}que[N];

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

void dfs(int u,int fa)
{
    kuai.maxn=max(kuai.maxn,u),kuai.minn=min(kuai.minn,u);
    kuai.pcnt++;
    vis[u]=1;
    for (int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa)
            continue ;
        kuai.ecnt++;
        if (!vis[v])
            dfs(v,u);
    }
}

bool cmp(Segments a,Segments b)
{
    if (a.minn==b.minn)
        return a.maxn<b.maxn;
    return a.minn<b.minn;
}

bool comp1(query a,query b)
{
    if (a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}

// bool comp2(query a,query b)
// {
//     return a.id<b.id;
// }

signed main()
{
	n=input(),k=input();
    for (int i=1;i<=k;i++)
    {
        tmp1=input(),tmp2=input();
        adde(tmp1,tmp2);
        adde(tmp2,tmp1);
    }
    for (int i=1;i<=n;i++)
        if (!vis[i])
        {
            kuai.init();
            dfs(i,0);
            if (kuai.checker())
                seg[++segnum].maxn=kuai.maxn,seg[segnum].minn=kuai.minn;
        }
    sort(seg+1,seg+segnum+1,cmp);
    q=input();
    for (int i=1;i<=q;i++)
        que[i].l=input(),que[i].r=input(),que[i].id=i;
    sort(que+1,que+q+1,comp1);
    int j=1;
    for (int i=1;i=)
    // for (int i=1;i<=segnum;i++)
    // {
    //     if (qnum>q)
    //         break ;
    //     while (seg[i].minn<que[qnum].l||seg[i].maxn>que[qnum].r&&qnum<=q)
    //     {
    //         que[qnum].ans=0;
    //         qnum++;
    //     }
    //     while (seg[i].minn>=que[qnum].l&&seg[i].maxn<=que[qnum].r&&qnum<=q)
    //     {
    //         que[qnum].ans=1;
    //         qnum++;
    //     }
    // }
    // sort(que+1,que+q+1,comp2);
    // for (int i=1;i<=q;i++)
    //     puts((que[i].ans==1)?"No":"Yes");
    return 0;
}
/*
11 7
1 2
2 7
3 4
4 9
5 6
6 11
10 10
1
2 8
*/