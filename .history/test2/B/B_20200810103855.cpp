#include<bits/stdc++.h>
#define int long long
#define N 2222
#define INF 0x3f3f3f3f
using namespace std;
int n,ans=0,tmpe;
int dis[N][N];
struct Edge
{
    int v,w,nxt;
}
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

}

signed main()
{
    n=input();
    memset(dis,INF,sizeof(dis));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            tmpe=getchar()-'0';
            if (tmpe)
                dis[i][j]=1;
        }
        getchar();
    }
    if (n<=500)
    {
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (i==j)
                    continue ;
                if (dis[i][j]==INF)
                    ans+=n*n;
                else
                    ans+=dis[i][j]*dis[i][j];
            }
        print(ans,'\n');
    }
    return 0;
}
/*
5
11000
01101
11110
01011
10011
*/