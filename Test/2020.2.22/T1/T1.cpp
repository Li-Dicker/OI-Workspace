#include<bits/stdc++.h>
#define int long long
#define N 111111
using namespace std;
int n,cnt,flag;
int sum[N];
char s[N];
bool work(int x)
{
	int num=0,k=sum[n-1]/x;
	for (int i=0;i<n;i++)
		if (s[i]!='0'&&sum[i]%k==0)
			num++;
	if (num>=x)
		return 1;
	else
		return 0;
}
void init()
{
	memset(sum,0,sizeof(sum));
	cnt=0,flag=0;
	sum[0]=s[0]-'0';
	if (s[0]-'0'!=0)
		cnt++;
}
signed main()
{
	while (scanf("%lld\n",&n)!=EOF)
	{
		cin>>s;
		
		init();
		for (int i=1;i<n;i++)
		{
			if (s[i]-'0'!=0)
				cnt++;
			sum[i]=sum[i-1]+s[i]-'0';
		}
		if (cnt==0)
			flag=1;
		if (!flag)
			for (int i=2;i<=n;i++)
				if (work(i))
				{
					flag=1;
					break;
				}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}