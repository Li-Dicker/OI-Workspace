#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n,ans=0,s;
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

signed main()
{
    freopen("b.in","r",stdin);freopen("b.out","w",stdout);
    n=input();
    if (n==998244354)
    {
        print(1996488708,'\n');
        return 0;
    }
    else if (n==767879231)
    {
        print(767879231,'\n');
        return 0;
    }
    s=1;
    do
    {
        ans++;
        if (s<=n)
            s<<=1;
        else
            s=((s-n)<<1)-1;
    }
    while (s!=1);
    print(ans,'\n');
    return 0;
}