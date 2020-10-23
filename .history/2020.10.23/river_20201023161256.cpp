#include<bits/stdc++.h>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lyp int mid=(l+r)>>1;
#define int long long
#define N 1111111
#define INF 0x3f3f3f3f
using namespace std;

int T,n,m,D,L,ans,nw;
int ano[N],sto[N],tree[N<<2];
bool ali[N];

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

int get(int x)
{
	int res=-1,l=x,r=n;
	while(l<=r)
	{
		lyp
		if(sto[mid]<=sto[x]+D)
			res=mid,l=mid+1;
		else
			r=mid-1;
	}
	return res;
}

void pushup(int rt)
{
	tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}

void build(int l,int r,int rt)
{
	tree[rt]=r;
	if (l==r)
		return;
	lyp
	build(lson),build(rson);
}

void updata(int l,int r,int rt,int k,int s)
{
	if (l==r)
	{
		tree[rt]=s;
		return ;
	}
	lyp
	if (k<=mid)
		updata(lson,k,s);
	else
		updata(rson,k,s);
	pushup(rt);
}

int query(int l,int r,int rt,int LL,int RR)
{
	if (l>=LL&&r<=RR)
		return tree[rt];
	lyp
	int res=-INF;
	if (LL<=mid)
		res=max(res,query(lson,LL,RR));
	if (RR>mid)
		res=max(res,query(rson,LL,RR));
	return res;
}

signed main()
{
	T=input();
	while(T--)
	{
		n=input(),m=input(),D=input(),L=input();
		build(1,n,1);
		for (int i=1;i<=n;i++)
			sto[i]=input(),ali[i]=1;
		nw=0,ans=0;
		while(1)
		{
		puts("AAAAAA");
			if(sto[nw]+D>=L)
			{
				ans++,nw=0;
				continue;
			}
			int nxt=get(nw);
			nxt=query(1,n,1,nw+1,nxt);
			if(nxt==-INF)
				break;
			nw=nxt,updata(1,n,1,nw,-1);
		}
		if (ans>=m)
			puts("Excited");
		else
			print(ans,'\n');
	}
	return 0;
}