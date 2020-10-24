#include<bits/stdc++.h>
#include<windows.h>
#define int long long
#define N 100000
#define INF 0x3f3f3f3f
using namespace std;
int n,q;
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

int sign()
{
    int res=rand()*rand()%2;
    if (res==1)
        return 1;
    return -1;
}

signed main()
{
    srand(time(NULL));
    n=Rand(7)%N+1,q=Rand(7)%N+1;
    print(n,' ');print(q,'\n');
    while (q--)
    {
        Sleep(5);
        int op=Rand(3)%2+1;
        int l=Rand(7)%n+1,r=Rand(7)%n+1;
        if (l>r)
            swap(l,r);
        print(op,' ');print(l,' ');print(r,' ');
        if (op==1)
            print(Rand(6)%10000*sign(),' ');
        puts("");
    }
    return 0;
}