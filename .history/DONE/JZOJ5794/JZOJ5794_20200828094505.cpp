#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;

int n,ans=0;
int a[N],s[N];

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
    n=input();
    for (int i=1;i<=n;i++)
        a[i]=input();
    for (int i=2;i<=n;++i)
    {
        int last=a[i];
        if(a[i]>a[i+1]&&a[i]>a[i-1])
        {
            a[i]=max(a[i-1],a[i+1]);
            ans+=last-a[i];
        }
        if(a[i]<a[i+1]&&a[i]<a[i-1])
        {
            a[i]=min(a[i-1],a[i+1]);
            ans+=a[i]-last;
        }
    }
    for (int i=2;i<=n;++i)
        ans+=abs(a[i]-a[i-1]);
    print(ans,'\n');
    return 0;
}
/*
4 4
1 2 1 10
2 4 3 5
1 3 1 5
2 4 2 7 

*/