#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char x[5002];
int l;
long long t,a=0,b=0;
long long h;

int main()
{
    cin>>x+1;
    l=strlen(x+1);
    scanf("%lld",&t);

    hehe:

    if(t<l) l=t;
    for(register long long i=1;i<=l;i++)
    {
        if(x[i]=='E') a++;
        else if(x[i]=='S') b--;
        else if(x[i]=='W') a--;
        else b++;
    }
    if(l==t) printf("%lld %lld",a,b);
    else
    {
        h=t/l;
        a*=h,b*=h;
        t%=l;
        goto hehe;
    }
    return 0;
}