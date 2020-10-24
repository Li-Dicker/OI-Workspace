#include<bits/stdc++.h>
#define int long long
#define N 66666
#define INF 0x3f3f3f3f
using namespace std;
int n,tot=0,tmpe,MAX=-INF,ans=0;
bool isprime[N];
int prime[N],miu[N],f[N],c[N];

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

void init()
{
	tot=0,miu[1]=1;
	memset(isprime,0xff,sizeof(isprime));
	for (int i=2;i<=N;i++)
	{
		if (isprime[i])
			prime[++tot]=i,miu[i]=-1;
		for (int j=1;j<=tot&&i*prime[j]<N;j++)
		{
			isprime[i*prime[i]]=0;
			if (i%prime[j])
				miu[i*prime[j]]=-miu[i],f[i*prime[j]]=f[i]*f[prime[j]];
			else
			{
				miu[i*prime[j]]=0;
				f[i*prime[j]]=0;
				break ;
			}
		}
	}
}

signed main()
{
    n=input();
	init();
	for (int i=1;i<=n;i++)
		tmpe=input(),c[tmpe]++,MAX=max(MAX,tmpe);
	ans=0,n=MAX;
	for (int T=1;T<=n;T++)
	{
		tmpe=0;
		for (int i=1;i<=n/T;i++)
			tmpe=i*
	}
    return 0;
}
