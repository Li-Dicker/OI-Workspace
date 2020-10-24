#include<bits/stdc++.h>
#define int long long
#define N 5555
using namespace std;
int n,len,tmp1,flag;
int a[N];
char s[N];
void dfs(int sum,int st)
{
	if (st==n)
	{
		printf("YES\n");
		flag=1;
		return ;
	}
	int tmp2=0;
	for (int i=st+1;i<=n;i++)
	{
		tmp2+=a[i];
		if (tmp2==sum)
			dfs(sum,i);
		if (tmp2>sum)
			return ;
		if (flag==1)
			return ;
	}
}
signed main()
{
	loop:
	while (scanf("%lld",&n)!=EOF)
	{
		flag=0,tmp1=0;
		cin>>s;
		for (int i=0;i<n;i++)
			a[i+1]=s[i]-'0';
		for (int i=1;i<=n-1;i++)
		{
			if (flag)
				goto loop;
			tmp1+=a[i],dfs(tmp1,i);
		}
		printf("NO\n");
	}
	return 0;
}
