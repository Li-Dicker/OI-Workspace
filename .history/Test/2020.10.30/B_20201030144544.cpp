#include<bits/stdc++.h>
#define int long long
#define N 100003
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

int T,n,m,board,tree_clock;
int a[N],vis[N];
struct Seg
{
	int l,r,len;
}seg[N];

void init()
{
	for (int i=0;i<=n+3;i++)
		vis[i]=a[i]=0;
}

bool cmp(Seg a,Seg b)
{
	if (a.l==b.l)
		return a.r>b.r;
	return a.l<b.l;
}

signed main()
{
//	freopen("tree.in","r",stdin);freopen("tree.out","w",stdout);
	T=input();
	while (T--)
	{
		n=input(),m=input();
		init();
		for (int i=1;i<=m;i++)
		{
			seg[i].l=input(),seg[i].r=input();
			seg[i].len=seg[i].r-seg[i].l+1;
		}
		sort(seg+1,seg+m+1,cmp);
		board=0;
		for (int i=1;i<=m;i++)
		{
			tree_clock=1;
			if (board>=seg[i].r||seg[i].len==1)
				continue ;
			else if (board<seg[i].l)
			{
				for (int j=seg[i].l;j<=seg[i].r;j++)
					vis[a[j]=tree_clock++]=i;
			}
			else
			{
				for (int j=seg[i].l;j<=board;j++)
					vis[a[j]]=i;
				for (int j=board+1;j<=seg[i].r;j++)
				{
					while (vis[tree_clock]==i)
						tree_clock++;
					vis[a[j]=tree_clock]=i;
				}
			}
			board=max(board,seg[i].r);
		}
		for (int i=1;i<n;i++)
			print((a[i]==0)?1:a[i],' ');
		print((a[n]==0)?(1):a[n],'\n');
	}
    return 0;
}