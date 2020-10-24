#include<bits/stdc++.h>
#define N 1111111
#define INF 0x3f3f3f3f
using namespace std;
int len1,len2,p;
int nxt[N];
char a[N],b[N];
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
    #undef int
}
using namespace IOstream;
void getnxt()
{
	p=0,nxt[1]=0;
	for (int i=2;i<=len2;i++)
	{
		while (p&&b[i]!=b[p+1])
			p=nxt[p];
		if (b[p+1]==b[i])
			p++;
		nxt[i]=p;
	}
}
void KMP()
{
	p=0;
	for (int i=1;i<=len1;i++)
	{
		while (p&&b[p+1]!=a[i])
			p=nxt[p];
		if (b[p+1]==a[i])
			p++;
		if (p==len2)
		{
			p=nxt[p];
			print(i-len2+1,'\n');
		}
	}
}
signed main()
{
	scanf("%s %s",a+1,b+1);
	len1=strlen(a+1);
	len2=strlen(b+1);
	getnxt();
	for (int i=1;i<=len2;i++)
		print(nxt[i],' ');
	puts("");
	return 0;
}