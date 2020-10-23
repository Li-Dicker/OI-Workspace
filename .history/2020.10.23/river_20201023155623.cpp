#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define INF 0x3f3f3f3f
using namespace std;

int a[N],b[N];
int T,n,m,D,L;
deque<int>q;

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
bool check(int num){
	if(!num)return 1;
	for (int i=1;i<=n;i++)
		b[i]=a[i];
	int st=1;
	while(!q.empty())q.pop_back();
	for (int i=1;i<=num;i++)
		q.push_back(0);
	while(!q.empty()){
		int loc=q.front();q.pop_front();
		if(L-loc<=D)continue;
		while(st<=n&&b[st]<=loc)st++;
		if(st>n)return 0;
		if(b[st]-loc>D)return 0;
		q.push_back(b[st]);st++;
	}
	return 1;
}

signed main()
{
	T=input();
	while (T--)
	{
		n=input(),m=input(),D=input(),L=input();
		for (int i=1;i<=n;i++)
			a[i]=input();
		sort(a+1,a+n+1);
		int l=0,r=m;
		while(L<r){
			int mid=(l+r+1)>>1;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		if(l==m)printf("Excited\n");
		else
			print(l,'\n');
	}
}