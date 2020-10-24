#include<bits/stdc++.h>
#define int long long
#define N 1111
#define INF 0x3f3f3f3f
using namespace std;

int n,m,tmp1,tmp2,edgenum=0;
int head[N*N*2];
int mp[N][N];
struct Edge
{
    int v,next;
}edge[N*N*2];

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
    head[u]
}

signed main()
{
    memset(mp,1,sizeof(mp));
    n=input(),m=input();
    for (int i=1;i<=m;i++)
    {
        tmp1=input(),tmp2=input();
        mp[tmp1][tmp2]=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (mp[i][j])
            {
                adde(i,j);
                adde(j,i);
            }
    return 0;
}