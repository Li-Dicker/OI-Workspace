#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
using namespace std;
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

int n,m,S,half,res,ans,cnt;
int tmp1;
int a[N],sum1[N],sum2[N];
int get(int x)
{
    return (((2*x)/(1<<n))+2*x)%(1<<n);
}
signed main()
{
    
    n=input(),m=input();
    for (int i=1;i<=m;i++)
        a[i]=input();
    sum1[1]=a[1],sum2[m]=a[m];
    for (int i=2;i<=m;i++)
        sum1[i]=sum1[i-1]^a[i];
    for (int i=m-1;i>=1;i--)
        sum2[i]=sum2[i+1]^a[i];
    S=(1<<n)-1,half=(1<<(n-1))-1;
	for (int i=0;i<=S;i++)
    {
		res=-1;
		for (int j=0;j<=m;j++)
        {
			tmp1=i^sum1[j];
            if (tmp1<=half)
                tmp1<<=1;
            else
                // tmp1=(S-tmp1)<<1;
                tmp1=(tmp1<<1)+1;
			tmp1^=sum2[j+1];
			if (res<0)
                res=tmp1;
			else
                res=min(res,tmp1);
		}
		if (res>ans)
            ans=res,cnt=1;
		else if(res==ans)
            cnt++;
	}
    print(ans,' '),print(cnt,'\n');
    return 0;
}