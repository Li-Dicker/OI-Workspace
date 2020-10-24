#include<bits/stdc++.h>
using namespace std;

const int maxn=105;
int n,v[maxn],c[maxn][maxn],op,sum,dp[maxn*20];

int main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)scanf("%d",&v[i]),sum+=v[i];
	for(register int i=1;i<=n;i++){
		getchar();
		for(register int j=1;j<=n;j++){
			char C;
			scanf("%c",&C);c[i][j]=C-'0';
			if(c[i][j])op=1;
		}
	}
	if(!op){
		for(register int i=1;i<=n;i++)
			for(register int j=sum/2;j>=v[i];j--)
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
		printf("%d\n",sum-2*dp[sum/2]);
	}
	else{
		int ans=0x3f3f3f3f;
		for(register int i=0;i<=(1<<n)-1;i++){
			int p=0;for(register int j=1;j<=n;j++)
			for(register int k=1;k<=n;k++)
				if(c[j][k]&&(((1<<(j-1))&i)==((1<<(k-1))&i))){p=1;break;}
			if(p)continue;
			int cnt=0;
			for(register int j=1;j<=n;j++)
				if((1<<(j-1))&i)cnt+=v[j];
				else cnt-=v[j];
			ans=min(ans,abs(cnt));
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
4
2 4 1 5
0100
1000
0001
0010
*/
