#include <bits/stdc++.h>
using namespace std;
int T,n,a[203],b[203],dp[203][203],Tests;
int sol(int l,int r){
	if(r<l)return 0;
	if(dp[l][r]<1e9)return dp[l][r];
	if(l==r)return dp[l][r]=b[l-1]+b[l+1];
	dp[l][r]=b[r+1]+b[l-1]+min(sol(l+1,r),sol(l,r-1));
	for(int i=l+1;i<r;i++)dp[l][r]=min(sol(l,i-1)+sol(i+1,r)+b[l-1]+b[r+1],dp[l][r]);
	return dp[l][r];
}
void solve(){
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)dp[i][j]=1e9;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans+=a[i];
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	a[n+1]=b[n+1]=0;
	printf("Case #%d: %d\n",++Tests,ans+sol(1,n));
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
}
