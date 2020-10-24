#include<bits/stdc++.h>
// #define int long long
#define N (int)5e7+7
#define INF 0x3f3f3f3f
using namespace std;

int n,MOD,cnt;
long long ans=0;
int pri[N],d[N]={0,1},vis[N];

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

int ksc(int x, int y)
{
    return (x*y-(int)((long double)x/MOD*y)*MOD+MOD)%MOD;     
}

signed main()
{
	n=input(),MOD=input();
	for (int i=2;i<=n;i++)
	{
		if (!vis[i])
			pri[++cnt]=i,d[i]=2;
		for (int j=1;i*pri[j]<=n;j++)
		{
			vis[i*pri[j]]=1;
			d[i*pri[j]]=d[i]<<1;
			if (i%pri[j]==0)
			{
				d[i*pri[j]]-=d[i/pri[j]];
				break;
			}
			d[i*pri[j]]=d[i]<<1;
		}
	}
	//Dirchlet前缀和
	for(int i=1;i<=cnt;i++)
		for(int j=n/pri[i];j>=0;j--)
			d[j]+=d[j*pri[i]];
	for(int i=1;i<=n;i++)
		ans=(ans+ksc(d[i],d[i]))%MOD;
	print(ans%MOD,'\n');
    return 0;
}