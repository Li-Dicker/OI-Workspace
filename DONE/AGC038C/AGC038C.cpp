#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#define int long long
#define main mian
#define N 1111111
#define INF 0x3f3f3f3f
#define MOD 998244353
using namespace std;
int n,tot=0,tmpe,MAX=-INF,ans=0,sum=0;
bool vis[N+11];
int prime[N+11],miu[N+11],f[N+11],c[N+11];

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
	for (int i=2;i<=n;i++)
	{
		if (!vis[i])
			prime[++tot]=i,miu[i]=-1;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			vis[i*prime[j]]=1;
			if (i%prime[j]==0)
			{
				miu[i*prime[j]]=0;
				break ;
			}
			else
				miu[i*prime[j]]=-miu[i];
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			f[j]+=miu[i]*i;
}

int max(int a,int b)
{
	return a>b?a:b;
}

int ksc(int x, int y)
{
    return (x*y-(int)((long double)x/MOD*y)*MOD+MOD)%MOD;     
}

signed main()
{
    n=input();
	for (int i=1;i<=n;i++)
		tmpe=input(),c[tmpe]++,MAX=max(MAX,tmpe),sum+=tmpe;
	ans=0,n=MAX;
	init();
	for (int T=1;T<=n;T++)
	{
		tmpe=0;
		for (int i=1;i<=n/T;i++)
            tmpe+=ksc(i,c[i*T]);
        ans+=ksc(ksc(T,f[T]),ksc(tmpe,tmpe));
	}
	print((ans-sum)>>1,'\n');
    return 0;
}

