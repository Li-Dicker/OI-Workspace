#include<bits/stdc++.h>
#define int long long
#define N 10
#define INF 0x3f3f3f3f
using namespace std;

int n,k;
int S;
int dp[(1<<N)][N][N][N];

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

int check_line(int x,int y)
{
    for (int i=2;i<=n-1;i++)
    {
        if (((x>>(i-1))&1)&&(((x>>i)&1)||((x>>(i-2))&1)))
            return false;
        if (((y>>(i-1))&1)&&(((y>>i)&1)||((y>>(i-2))&1)))
            return false;
        if (((x>>(i-1))&1)&&(((y>>(i-1))&1)||((y>>i)&1)||((y>>(i-2))&1)))
            return false;
    }
}

int line_num(int x)
{
    int res=0;
    while (x)
    {
        if (x&1)
            res++;
        x>>=1;
    }
    return res;
}

signed main()
{
	n=input(),k=input();
    S=(1<<n)-1;
    for (int i=1;i<=n;i++)
        for (int s=0;s<=S;s++)
            for (int l=0;l<=S;l++)
                if (check_line(l,s))
                {
                    int p=line_num(s),q=line_num(l);
                }
    return 0;
}