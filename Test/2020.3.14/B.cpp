#include<bits/stdc++.h>
#define int long long
#define N 1111111
#define MOD 317847191
using namespace std;
int n,q,tmp1,num,maxn,minn;
int a[N],vis[N];
char c;
map <int,int> mp1;
map <int,int> mp2;
int ksm(int a,int n,int mod)
{
    if (n==0)
    	return 1;
    int x=ksm(a,n/2,mod);
    int ans=x*x%mod;
    if (n%2==1)
    	ans=ans*a%mod;
    return ans;
}
signed main()
{
	scanf("%lld %lld",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		if (!mp1[a[i]])
			mp1[a[i]]=i;
	for (int i=1;i<=n;i++)
		if (!mp2[a[i]])
			mp2[a[i]]=i;
	while (q--)
	{
		cin>>c;
		if (c=='D')
		{
			scanf("%lld",&tmp1);
			num=mp1[tmp1];//找到在排序后数列中第一次出现的时候
			maxn=mp2[tmp1];//找到在排序后的数列中最后一次出现的时候
			while (vis[num]==1&&num<=maxn)//找到第一个没被删除的这个数
				num++;//当前数被删除了就找下一个
			if (a[num]==tmp1&&!vis[num])//最后找到的这个数没被删除过
				a[num]=1,vis[num]=1;
		}
		else if (c=='B')
		{
			tmp1=n;
			while (vis[tmp1])
				tmp1--;
			printf("%lld\n",a[tmp1]);
		}
		else if (c=='S')
		{
			tmp1=1;
			while (vis[tmp1])
				tmp1++;
			printf("%lld\n",a[tmp1]);
		}
		else if (c=='M')
		{
			tmp1=n;
			while (vis[tmp1])
				tmp1--;
			maxn=a[tmp1];
			tmp1=1;
			while (vis[tmp1])
				tmp1++;
			minn=a[tmp1];//找到最小值和最大值
			cout<<ksm(maxn,minn,MOD)<<endl;//快速幂
		}
		else if (c=='T')
		{
			tmp1=1;
			for (int i=1;i<=n;i++)
				tmp1*=a[i],tmp1%=MOD;
			printf("%lld\n",tmp1);
		}
	}
	return 0;
}
/*
3 6
2 6 9
M
D 9
B
S
M
T
*/