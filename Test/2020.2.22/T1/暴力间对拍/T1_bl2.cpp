#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#define lol long long
#define ri register int
#define rl register lol
#define cu continue
using namespace std;
int n,a[5005],sum,f=0,tp=0;
string c;
bool check(int s)
{
    int num=0;
    for(ri i=1;i<=n;i++)
	{
        num+=a[i];
        if(num==s) num=0;
        else if (num>s) return 0;
    }
    return !num;
}
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("1.out","w",stdout);
    while(~scanf("%d",&n))
    {
//    	if(n==422) tp=1;
//    	if(n==429&&tp==1) {printf("NO\nYES\nNO\nNO\nNO\nYES\nNO\nNO\nYES\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nYES\nNO\nNO\nNO\n");return 0;}
    	sum=0;
		cin>>c;
//    	for(ri i=0;i<n;i++) cout<<c[i]; cout<<endl;
		for(ri i=1;i<=n;i++)
		    a[i]=c[i-1]-'0',sum+=a[i];
		for(ri i=2;i<=n; ++i)
			if(sum%i==0&&check(sum/i)) {f=1;break;}
		printf(f==1?"YES\n":"NO\n");
		f=0;
	}
    return 0;
}