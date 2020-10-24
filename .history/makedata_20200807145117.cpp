#include<bits/stdc++.h>
#define int long long
#define N 1000
#define INF 0x3f3f3f3f
using namespace std;
int T,a,b,c,d;
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
    T=Rand(3)%10+1;
    print(T,'\n');
    while (T--)
    {
        a=Rand(5)%N+1,b=Rand(5)%N+1,c=Rand(5)%N+1,d=Rand(5)%N+1;
        print(a,' '),print(b.' '),print(c,' '),print(d,'\n');
    }
    return 0;
}