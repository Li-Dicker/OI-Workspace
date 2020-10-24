#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define N 17
using namespace std;
int T,n,cnt,tmp1,tmp2,tmp3,reducetot;
struct Oops
{
    char name[N];
    int uset;//use time
    int needt;//need time
}a[N];
struct DICKER
{
    int fa,id,reduce,ans;
}dp[1<<N];
void init()
{
	memset(dp,0,sizeof(dp));
    cnt=1<<n; 
}
void output()
{
    printf("%lld\n",dp[cnt-1].reduce);
    stack<int>q;  
    tmp3=cnt-1;;
    while (dp[tmp3].ans)
    {
        q.push(dp[tmp3].id);
        tmp3=dp[tmp3].fa;
    }
    while (!q.empty())
    {
        tmp3=q.top();
        cout<<a[tmp3].name<<endl;
        q.pop();
    }
}
signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        init();
        for (int i=0;i<n;i++)
        	scanf("%s %lld %lld",a[i].name,&a[i].needt,&a[i].uset);
        for (int i=1;i<cnt;i++)
        {   
       		dp[i].reduce=INF;
            for (int j=n-1;j>=0;j--)//枚举上一步，并且要按字典序
            {
                tmp1=1<<j;
                if (tmp1&i)//枚举i是从哪一步转移过来的
                {   
                	tmp2=i-tmp1;//回到上一步的状态
                    reducetot=dp[tmp2].ans+a[j].uset-a[j].needt;//扣分
                    if (reducetot<0)//特判多扣了则归0
                    	reducetot=0;
                    if (reducetot+dp[tmp2].reduce<dp[i].reduce)//类似于松弛操作
                    {
                        dp[i].reduce=reducetot+dp[tmp2].reduce;//类似于松弛操作
                        dp[i].fa=tmp2;//记录父亲
                        dp[i].id=j;//记录答案顺序
                        dp[i].ans=dp[tmp2].ans+a[j].uset;//记录答案,用的时间
                    }
                }
            }
        }
        output();
    }
    return 0;
}