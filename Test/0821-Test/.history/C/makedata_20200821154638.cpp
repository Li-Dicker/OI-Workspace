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

int Rand(int k)
{
    int res=0;
    for (int i=1;i<=k;i++)
        res*=10,res+=(rand()*rand())%10;
    return res;
}

signed main()
{
    srand(time(NULL));
    int op=rand()%2,n=Rand(4)%100+1;
    if (op)
        n%=15+1;
    print(n,'\n');
    for (int i=1;i<=n;i++)
        print(Rand(5)%20+1,' ');
    puts("");
    if (op)
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                prints(0);
            puts("");
        }
    else
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                prints(rand()%2);
            puts("");
        }
    }
    
    return 0;
}