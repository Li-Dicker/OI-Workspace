#include<bits/stdc++.h>
#define int long long
#define N 111111
using namespace std;
int T,cnt,maxn,len;
int dp[N],cover[N];
char ch[111];
bool check(int x)
{
    if (x==0)
        return 1;
    int i=0,j=len-1;
    while(i<j)
    {
        while ((x&(1<<i))==0)
            i++;
        while ((x&(1<<j))==0)
            j--;
        if (ch[i]!=ch[j])
            return 0;
        i++,j--;
    }
    return 1;
}
void init()
{
    cnt=0;
    memset(dp,0x3f,sizeof(dp));
    len=strlen(ch);
    maxn=(1<<len)-1;
}
signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        cin>>ch;
        init();
        for (int i=1;i<=maxn;i++)
            if (check(i))
                cnt++,dp[i]=1,cover[cnt]=i;
        for (int i=1;i<=maxn;i++)
            for (int j=1;j<=cnt;j++)
                if ((i&cover[j])==0)
                dp[i|cover[j]]=min(dp[i|cover[j]],dp[i]+1);
        printf("%lld\n",dp[maxn]);
    }
    return 0;
}