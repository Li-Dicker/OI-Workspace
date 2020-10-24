#include<bits/stdc++.h>
#define int long long
#define N 11111111
#define INF 0x3f3f3f3f
using namespace std;
int n,k,P,A,B,C,D,cnt=0,st,ed;
int s[N],sum1,sum2;
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
    n=input(),k=input(),P=input();
    A=input(),B=input(),C=input(),D=input();
    s[1]=A;
    for (int i=2;i<=n;i++)
        s[i]=(s[i-1]*B+C)%D;
    cnt=n/k;
    for (int i=1;i<=cnt;i++)
    {
        st=k*(i-1)+1,ed=k*i;
        sum1[st]=s[st],sum2[ed]=s[ed];
        for (int j=st+1;j<=ed;j++)
            sum1[j]=(sum1[j-1]*s[j])%P;
        for (int j=ed-1;j>=st;j--)
            sum2[j]=(sum2[j+1]*s[j])%P;
    }
    if (n%k)
    {
        st=k*cnt+1,ed=n;
        sum1[st]=s[st],sum2[ed]=s[ed];
        for (int j=st+1;j<=ed;j++)
            sum1[j]=(sum1[j-1]*s[j])%P;
        for (int j=ed-1;j>=st;j--)
            sum2[j]=(sum2[j+1]*s[j])%P;
    }
    for (int i=1;i<=n-k+1;i++)
        if (i%k==1)
            ans^=sum1[i+k-1];
        else
            ans^=()
    return 0;
}