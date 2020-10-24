#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;

int n,m,q,ans=0,x,y;
int fa[N],size[N],dis[N],dep[N];

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

int getfa(int x)
{
    if (fa[x]==x)
    {
        dep[x]=0;
        return x;
    }
    int Fa=getfa(fa[x]);
    dep[x]=dep[fa[x]]+1;
    return Fa;
}

void adde(int u,int v,int k)
{
    int fu=getfa(u),fv=getfa(v);
    if (fu!=fv)
    {
        if (size[fu]>size[fv])
            swap(fu,fv);
        fa[fu]=fv;
        size[fv]=max(size[fv],size[fu]+1);
        dis[fu]=k;
    }
}

signed main()
{
    n=input(),m=input(),q=input();
    for (int i=1;i<=n;i++)
        fa[i]=i,size[i]=1;
    for (int i=1;i<=m;i++)
    {
        int k=m-i+1;
        for (int j=1;k*(j+1)<=n;j++)
            adde(k*j,k*(j+1),i);
    }
    for (int i=1;i<=q;i++)
    {
        x=input(),y=input();
        ans=0;
        int fx=getfa(x),fy=getfa(y);
        if (dep[x]<dep[y])
            swap(x,y);
        while (dep[x]>dep[y])
        {
            ans=max(ans,dis[x]);
            x=fa[x];
        }
        while (x!=y)
        {
            ans=max(ans,dis[x]);
            x=fa[x];
            ans=max(ans,dis[y]);
            y=fa[y];
        }
        print(ans,'\n');
    }
    return 0;
}
/*
8 3 3
2 5
3 6
4 8

*/