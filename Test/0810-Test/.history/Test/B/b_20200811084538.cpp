#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define N 2222
#define M (N>>6)+1
#define INF 0x3f3f3f3f
using namespace std;

int n;
int dis[N];
char tmpe[N];

struct BITSET
{
    ull bitset_[M];

    void Bitset()
    {
        memset(bitset_,0,sizeof(bitset_));
    }

    ull& operator [](int index)
    {
        return bitset_[index];
    }

    ull operator [](int index) const
    {
        return bitset_[index];
    }

    void set(int i)
    {
        bitset_[i>>6]|=1ull <<(i&63);
    }

    void unset(int i)
    {
        bitset_[i>>6]&=!(1ull<<(i&63));
    }
}edge[N],uvis;

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

int bfs(int s)
{
    for (int i=0;i<n;i++)
    {
        uvis.set(i);
        dis[i]=n;
    }
    uvis.unset(s);
    dis[s]=0;
    queue<int >q;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<M;i++)
        {
            ull tmp1=uvis[i]&edge[u][i];
            while (tmp1>0)
            {
                int j=
            }
        }
    }
}

signed main()
{
    
    return 0;
}