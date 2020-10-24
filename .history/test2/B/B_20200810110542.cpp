#include<bits/stdc++.h>
#define int long long
#define N 2222
#define INF 0x3f3f3f3f
using namespace std;
int n;
int dis_ans[N][N];
char tmpe[N];
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
    {
        scanf("%s",tmpe+1);
        for (int j=1;j<=n;j++)
        {
            if (tmpe[j]-'0'==1)
                dis_ans[i][j]=1;
            else
                dis_ans[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            prints(dia_ans[i][j]);
        puts("");
    }
    return 0;
}
/*
5
11000
01101
11110
01011
10011
*/