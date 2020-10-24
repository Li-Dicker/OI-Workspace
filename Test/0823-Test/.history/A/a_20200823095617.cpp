#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
int n,ans=0,cnt=0,sq,tmpe=1,last=0;
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

signed main()
{
    n=input();
    for (int i=1;i<=n;i++)
        a[i]=input();
    sort(a+1,a+n+1);
    for (int i=a[n];i>=1;i--)
    {
        cnt=0,sq=sqrt(i),tmpe=1,last=0;
        for (int j=1;j<=sq;j++)
            if (i%j==0)
            {
                b[cnt++]=j;
                if (j*j!=i)
                    b[cnt++]=i/j;
            }
        sort(b,b+cnt);
        for (int j=1;j<cnt;j++)
        {
            index=lower_bound(a+1,a+n+1,b[j])-(a+1);
        }
    }
    return 0;
}
/*
1 2 3 4

1 1 1 1
1 1 1 2
1 1 1 3
1 1 1 4
1 1 2 1
1 1 2 2
1 1 2 4
1 1 3 1
1 1 3 3
1 2 1 1
1 2 1 2
1 2 1 4
1 2 2 1
1 2 2 2
1 2 2 4
*/