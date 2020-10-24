#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int hang[1111][1111],lie[1111][1111];
int mp[1111][1111];
signed main()
{
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%lld",&mp[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			hang[i][j]=hang[i][j-1];
			if (mp[i][j]==1)
				hang[i][j]++;
		}
	for (int j=1;j<=m;j++)
		for (int i=1;i<=n;i++)
		{
			lie[i][j]=lie[i-1][j];
			if (mp[i][j]==1)
				lie[i][j]++;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!mp[i][j])
			{
				if (hang[i][j]>0)
					ans++;
				if (hang[i][j]<hang[i][m])
					ans++;
				if (lie[i][j]>0)
					ans++;
				if (lie[i][j]<lie[n][j])
					ans++;
			}
	printf("%lld\n",ans);
	return 0;
}
