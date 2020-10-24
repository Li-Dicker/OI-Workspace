#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define int long long
#define MK 25
using namespace std;
int n,x[MK],y[MK];
int dp[1<<(MK-1)|1],road[1<<(MK-1)|1];
int BIT[1<<(MK-1)];

inline int lowbit(int x)
{
    return x&(-x);
} 

inline int dis(int u,int v)
{
    return (x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]);
}

inline int bit(int x)
{
    return BIT[x];
} 

inline int bitt(int x)
{
    int sum = 0;
    while(x)
    {
        sum++;
        x>>=1;
    }
    return sum;
} 

signed main()
{
    scanf("%lld%lld",&x[0],&y[0]);//起点坐标
    scanf("%lld",&n);//点数
    for(register int i=0;i<=(1<<n);i++)
    	BIT[i]=bitt(i);
    for(register int i=1;i<=n;i++)
    {
    	scanf("%lld%lld",&x[i],&y[i]);//有物品的点的坐标
    }
    memset(dp,0x3f,sizeof(dp));//初始化
    dp[0] = 0;
    for(register int now=1;now<(1<<n);now++)
    {
        int i = lowbit(now); //
        int u = now;
        while(u)
        {
            int j = lowbit(u);
            int x=bit(i),y=bit(j);
            int step = dp[now^(i|j)]+dis(0,x)+dis(x,y)+dis(y,0);
            if(step < dp[now])
            {
                dp[now] = step;
                road[now]=now^(i|j);
            }
            u -= lowbit(u);
        }
    }
    printf("%lld\n",dp[(1<<n)-1]);
    int cnt = (1<<n)-1;
    while(cnt)
    {
        printf("0 ");
        int t1 = cnt^road[cnt];
        int t2 = lowbit(cnt);
        t1 -= t2;
        printf("%lld ",bit(lowbit(t2)));
        if(t1)
        {
        	printf("%lld ",bit(lowbit(t1)));
        }
        cnt = road[cnt];
    } 
    printf("0\n");
    return 0;
}