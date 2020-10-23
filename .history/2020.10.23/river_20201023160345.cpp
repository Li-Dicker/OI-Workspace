#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define INF 0x3f3f3f3f
using namespace std;

int T,m,n,s,D,L,ans,lst;
int a[N],b[N];
set <int> st;

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

int main()
{
	T=input();
	int lastn=0,lastm=0;
	while(T--)
	{
		for (int i=1;i<=lastn;i++)
			a[i]=0;
		for (int i=1;i<=lastm;i++)
			b[i]=0;
		st.clear();
		n=input(),m=input(),D=input(),L=input();
		for(int i=1;i<=n;i++)
			a[i]=input();
		ans=lst=0;
		int l=1,r=m;
		while (l<=r)
		{
			int last=1e9+10,lst2;
			for (int i=l;i<=r;i++)
			{
				if(b[i]+D>=L)
				{
					ans++;
					l++;
					continue;
				}
				int *tmp=upper_bound(a+1,a+n+1,min(last-1,b[i]+D));
				tmp--;
				if((*tmp)<=b[i]||(*tmp)<=lst)
					r=i-1;
				else
					b[i]=*tmp,last=*tmp;
				if(i==l)
					lst2=*tmp;
			}
			lst=lst2;
		}
		lastn=n,lastm=m;
		if (ans==m)
			printf("Excited\n");
		else
			print(ans,'\n');
	}
	return 0;
}
