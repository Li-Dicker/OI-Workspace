#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
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

int n,maxn,minn,ans,flag=1;
int a[N];
map<int ,int >vis;

class Sub1
{
	private:
	
	int f1[N][22],f2[N][22];
	
	void pre()
	{
		for (int i=1;i<=n;i++)
			f1[i][0]=f2[i][0]=a[i];
		for (int j=1;j<=20;j++)
			for (int i=1;i+(1<<(j-1))-1<=n;i++)
				f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]),f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
	}
	
	int query_max(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f1[l][k],f1[r-(1<<k)+1][k]);
	}
	
	int query_min(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f2[l][k],f2[r-(1<<k)+1][k]);
	}
	
	public:
		
	void solve()
	{
		pre();
		for (int i=1;i<=n;i++)
		{
			vis.clear();
			maxn=minn=a[i],vis[a[i]]=1;
			int snum=0;
			for (int j=i+1;j<=n;j++)
			{
				if (vis[a[j]])
					snum++;
				vis[a[j]]=1;
				minn=min(a[j],minn),maxn=max(a[j],maxn);
				if ((j-i+1)-(snum+1)>=maxn-minn)
					ans++;
			}
		}
		print(ans,'\n');
	}
}subtask1;

class Sub2
{
	public:
	
	void solve()
	{
		for (int i=1;i<=n;i++)
		{
			vis.clear();
			maxn=minn=a[i],vis[a[i]]=1;
			int snum=0;
			for (int j=i+1;j<=n;j++)
			{
				if (vis[a[j]])
					snum++;
				vis[a[j]]=1;
				minn=min(a[j],minn),maxn=max(a[j],maxn);
				if ((j-i+1)-(snum+1)>=maxn-minn)
					ans++;
			}
		}
		print(ans,'\n');
	}
}subtask2;

signed main()
{
	ans=n=input();
	for (int i=1;i<=n;i++)
	{
		a[i]=input();
		if (vis[a[i]])
			flag=0;
	}
	if (flag==1)
		subtask1.solve();
	else
		subtask2.solve();
    return 0;
}