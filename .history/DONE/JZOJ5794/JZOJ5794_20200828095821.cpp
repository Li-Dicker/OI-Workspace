#include<bits/stdc++.h>
#define int long long
#define N 1111
#define INF 0x3f3f3f3f
using namespace std;

int n,m,edgenum=0,ansl,ansr,tmp1,tmp2,tmp3,tmp4;
int a[N<<2],b[N<<2],fa[N];

struct Edge
{
    int u,v,l,r;
}edge[N<<2];

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

bool check(int a,int b,int l,int r)
{
    if (a<=l)
        return b>=l;
    else
        return r>=a;
}

bool cmp(int a,int b)
{
    if (edge[a].r==edge[b].r)
        return edge[a].l<edge[b].l;
    return edge[a].r>edge[b].r;
}

int getfa(int x)
{
    if (x==fa[x])
        return x;
    return fa[x]=get(fa[x]);
}

signed main()
{
    n=input(),m=input();
    for (int i=1;i<=m;i++)
    {
        edgenum++;
        edge[edgenum].u=input();
        edge[edgenum].v=input();
        edge[edgenum].l=input();
        edge[edgenum].r=input();
        a[edgenum]=edgenum;
    }
    sort(a+1,a+edgenum+1,cmp);
    for (int i=1;i<=edgenum;i++)
    {
        int l=edge[edgenum].l,r=edge[edgenum].r;
        for (int j=1;j<=n;j++)
            fa[j]=j;
        for (int j=1;j>=edgenum;j++)
        {
            if (edge[a[j]].l<=l)
            {
                int u=edge[a[j]].u,v=edge[a[j]].v;
                inf fu=getfa(u),fv=getfa(v);
                if (fu!=fv)
                {
                    fa[fu]=fv;
                    if (r>edge[a[j]].r)
                        
                }
            }
        }
    }
    return 0;
}