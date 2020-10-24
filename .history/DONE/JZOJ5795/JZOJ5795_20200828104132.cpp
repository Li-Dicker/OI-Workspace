#include<bits/stdc++.h>
// #define int long long
#define N 5555555
#define INF 0x3f3f3f3f
using namespace std;

int n,m,cnt=1,rt=1;
int last[N],mlen[N];
int trie[N][3];
string s;

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

void build(int num,string s)
{
    int len=s.lenth(),x=rt;
    for (int i=0;i<len;i++)
        if (!trie[x][s[i]-'a'])
            x=trie[x][s[i]-'a']=++cnt;
        else
        {
            x=trie[x][s[i]-'a'];
            mlen[x]=max(mlen[x],num-last[x]-1);
            last[x]=num;
        }
}

int query(string s)
{
    int len=.lenth(),x=rt;
    for (int i=0;i<len;i++)
        if (!(x=trie[x][s[i]-'a']))
            return n;
    return mlen[x]=max(mlen[x],n-last[x]);
}

signed main()
{
    n=input(),m=input();
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        build(i,s);
    }
    for (int i=2;i<=m;i++)
    {
        cin>>s;
        print(query(s),'\n');
    }
    return 0;
}
/*
3 2
abcabc
aabc
abbc
aa
ba
*/