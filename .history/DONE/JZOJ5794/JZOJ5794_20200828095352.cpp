#include<bits/stdc++.h>
#define int long long
#define N 1111
#define INF 0x3f3f3f3f
using namespace std;

int n,m,e,ansl,ansr;
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
        return b>=l
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
        tmp1=input()
    }
    return 0;
}