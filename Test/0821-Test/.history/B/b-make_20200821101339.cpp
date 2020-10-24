#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n,ans=0;
int a[N],b[N];
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

bool check()
{
    for (int i=1;i<=n*2;i++)
        if (b[i]!=i)
            return false;
    return true;
}

signed main()
{
    // n=input();
    for (int sss=1;sss<=100;sss++)
    {
        n=sss;
        for (int i=1;i<=n*2;i++)
            a[i]=i;
        do
        {
            ans++;
            for (int i=1;i<=n;i++)
                b[i*2]=a[i];
            for (int i=1;i<=n;i++)
                b[i*2-1]=a[i+n];
            for (int i=1;i<=n*2;i++)
                // print(a[i]=b[i],' ');
                a[i]=b[i];
            // puts("");
            if (check())
            {
                print(ans,'\n');
                return 0;
            }
        }
        while (1==1);
    }
    return 0;
}
/*
1 2
2 4
3 3

4 6
5 10
6 12
7 4
8 8

9 18
10 6
11 11

12 20
13 18
14 28
15 5
16 10
17 12
18 36
19 12
20 20

21 14
22 12
23 23

24 21
25 8
26 52
27 20
28 18
29 58
30 60
31 6
32 12
33 66

*/