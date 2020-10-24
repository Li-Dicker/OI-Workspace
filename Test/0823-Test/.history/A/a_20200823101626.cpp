#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
int n,ans=0,cnt=0,sq,tmpe=1,last=0,sum;
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

int ksm(int x,int k)
{
    int res=1;
    while (k)
    {
        if (k&1)
            res=(res*x)%MOD;
        x=(x*x)%MOD;
        k>>=1;
    }
    return res;
}

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
            sum=lower_bound(a+1,a+n+1,b[j])-(a+1);
            tmpe=tmpe*ksm(j,sum-last)%MOD;
            last=sum;
        }
        tmpe=tmpe*(ksm(cnt,n-last)-ksm(cnt-1,n-last)+MOD)%MOD;
        ans=(ans+tmpe)%MOD;
        print(ans,'\n');
    }
    print(ans,'\n');
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