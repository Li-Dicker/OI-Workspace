#include<bits/stdc++.h>
#define int long long
#define N 33333
using namespace std;
int n,k,ans=0,tmp1,tmp2;
int sum[N];
int f[N][22];

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

void rmq(int n)
{
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<(j-1))-1<=n;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int query(int x,int y)
{
    int k=log2(y-x+1);
    return max(f[x][k],f[y-(1<<k)+1][k]);
}

signed main()
{
    n=input(),k=input();
    sum[0]=0;
	for (int i=1;i<=n;i++)
        f[i][0]=input(),sum[i]=sum[i-1]+f[i][0];
	rmq(n);
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            cout<<i<<' '<<j<<' '<<sum[j]-sum[i-1]<<' '<<query(i,j)<<endl;
    print(ans,'\n');
	return 0;
}