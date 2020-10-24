#include<bits/stdc++.h>
#include"windows.h"
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n;
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
    freopen("b.in","w",stdout);
    print(n=rand(),'\n');
    system("b-dave");
    if ((double)clock() / CLOCKS_PER_SEC>=2)
    {
        freopen("hack.txt","a",stdin);
        print(n,'\n');
        return 0;
    }
    return 0;
}