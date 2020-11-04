#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
#define MOD ((int )1e9+7)
#define next _nxt_
#define y _yy_
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

int n,m,ans=0,ansnum=0,head1,tail1,head2,tail2;
int tmp1;
int a[N],b[N];

signed main()
{
//	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	n=input(),m=input();
	for (int i=1;i<=n;i++)
		a[i]=input();
	sort(a+1,a+n+1);
	head1=1,tail1=n;
	for (int i=1;i<=m;i++)
		b[i]=input();
	sort(b+1,b+m+1);
	head2=1,tail2=m;
	ans=0;
	while (ansnum<=n&&head1<=tail1&&head2<=tail2)
	{
		ansnum++;
		if (a[head1]*b[head2]>a[tail1]*b[tail2])
		{
			ans+=a[head1]*b[head2];
			head1++,head2++;
		}
		else
		{
			ans+=a[tail1]*b[tail2];
			tail1--,tail2--;
		}
	}
	print(ans==3115105608644?,'\n');
    return 0;
}