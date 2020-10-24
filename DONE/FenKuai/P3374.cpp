#include<bits/stdc++.h>
#define int long long
#define N 666
#define INF 0x3f3f3f3f
using namespace std;

int n,q,tmpe,cnt,Len,op,tmp1,tmp2;
struct lyp
{
    int sum;
    int val[N];
}w[N];

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

namespace FK
{
    void updata(int x,int k)
    {
        w[x/Len].val[x%Len]+=k;
        w[x/Len].sum+=k;
    }

    int query(int l,int r)
    {
        int L=l/Len+(l%Len!=0),R=r/Len,res=0;
        cout<<"AAAAAAAA"<<L<<' '<<R<<endl;
        if (l%Len!=0)
            for (int i=l%Len;i<=Len;i++)
                res+=w[L-1].val[i];
        if (r%Len!=0)
            for (int i=1;i<=r%Len;i++)
                res+=w[R+1].val[i];
        for (int i=L;i<=R;i++)
            res+=w[i].sum;
        return res;
    }
}

signed main()
{
    n=input(),q=input();
    Len=sqrt(n);
    tmpe=0,cnt=1;
    for (int i=1;i<=n;i++)
    {
        if (tmpe==Len)
        {
            cnt++,tmpe=0;
            w[cnt].sum=0;
        }
        tmpe++;
        w[cnt].val[tmpe]=input();
        w[cnt].sum+=w[cnt].val[tmpe];
    }
    while (q--)
    {
        op=input(),tmp1=input(),tmp2=input();
        if (op==1)
            FK::updata(tmp1,tmp2);
        else
            print(FK::query(tmp1,tmp2),'\n');
    }
    return 0;
}