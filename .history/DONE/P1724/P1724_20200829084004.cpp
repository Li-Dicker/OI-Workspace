#include<bits/stdc++.h>
// #define int long long?
#define N 5555
#define INF 0x3f3f3f3f
using namespace std;

int l,t,a=0,b=0,tmpe;
char s[N];

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
    cin>>s+1;
    l=strlen(s+1);
    t=input();
    loop:
    if (t<l)
        l=t;
    for (int i=1;i<=l;i++)
    {
        if (s[i]=='E')
            a++;
        else if(s[i]=='S')
            b--;
        else if(s[i]=='W')
            a--;
        else
            b++;
    }
    if (l!=t)
    {
        tmpe=t/l;
        a*=tmpe,b*=tmpe;
        t%=l;
        goto loop;
    }
    print(a,' '),print(b,'\n');
    return 0;
}