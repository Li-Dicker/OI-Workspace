#include<bits/stdc++.h>
#define int long long
#define N 555555
using namespace std;
int n,flag;
struct lyp
{
    int x,y;
}a[N],b[N];
bool cmp(lyp a,lyp b)
{
    if (a.x==b.x)
    	return a.y<b.y;
    return a.x<b.x;
}
signed main()
{
    while (scanf("%lld",&n)!=EOF)
    {
		if (n==0)
			return 0;
    	flag=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++)
		{
		    scanf("%lld%lld",&a[i].x,&a[i].y);
		    b[i].y=a[i].x,b[i].x=a[i].y;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		for (int i=1;i<=n;i++)
		    if (a[i].x!=b[i].x||a[i].y!= b[i].y)
		    {
				flag=1;
				printf("NO\n");
				break;
		    }
		if (!flag)
			printf("YES\n");
    }
    return 0;
}