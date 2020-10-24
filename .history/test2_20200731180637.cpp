#include<bits/stdc++.h>
using namespace std;

int read(){
    int x=0,t=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')t=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*t; 
} 

#define MAXN 100005
struct Node{
    long long X,Y; 
}a[MAXN]; 
int N,x[MAXN],y[MAXN],pos;
long long ans=1ll<<62,s1[MAXN],s2[MAXN];

int main(){
    N=read();
    for(int i=1;i<=N;i++){
        int p=read(),q=read();
        x[i]=a[i].X=p+q;
        y[i]=a[i].Y=p-q;
    }
    sort(x+1,x+N+1);sort(y+1,y+N+1);
    for(int i=1;i<=N;i++)
        s1[i]=s1[i-1]+x[i],
        s2[i]=s2[i-1]+y[i];
    for(int i=1;i<=N;i++){
        long long tmp=0;
        pos=lower_bound(x+1,x+N+1,a[i].X)-x;
        tmp+=s1[N]-s1[pos]-a[i].X*(N-pos)+a[i].X*pos-s1[pos];
        pos=lower_bound(y+1,y+N+1,a[i].Y)-y;
        tmp+=s2[N]-s2[pos]-a[i].Y*(N-pos)+a[i].Y*pos-s2[pos];
        ans=min(ans,tmp);
    }
    printf("%lld\n",ans/2);
    return 0;
}