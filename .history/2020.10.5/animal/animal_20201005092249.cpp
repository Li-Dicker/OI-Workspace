// #include<bits/stdc++.h>
// #define int long long
// #define N 222222
// #define M 1111111
// #define INF 0x3f3f3f3f3f3f
// using namespace std;

// int n,ans=-INF;
// int a[N],mp[N];

// namespace IOstream
// {
// 	#define int long long
// 	#define print(a,b) prints(a),putchar(b)
// 	int BUF[22],BUFSIZE,IONUM,SIGN;
// 	char GET;

// 	inline int input()
// 	{
// 		IONUM=0,SIGN=1;
// 		GET=getchar();
// 		while (GET<'0'||GET>'9')
// 		{
// 			if (GET=='-')
// 				SIGN=-1;
// 			GET=getchar();
// 		}
// 		while (GET>='0'&&GET<='9')
// 		{
// 			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
// 			GET=getchar();
// 		}
// 		return SIGN*IONUM;
// 	}

// 	inline void prints(int IONUM)
// 	{
// 		if (IONUM<0)
// 			IONUM=-IONUM,putchar('-');
// 		do
// 			BUF[++BUFSIZE]=IONUM%10,IONUM/=10;
// 		while (IONUM);
// 		while (BUFSIZE)
// 			putchar(BUF[BUFSIZE--]+'0');
// 	}

// }
// using namespace IOstream;

// int max(int a,int b)
// {
// 	return a>b?a:b;
// }

// int min(int a,int b)
// {
// 	return a<b?a:b;
// }

// signed main()
// {
// 	n=input();
// 	for (int i=1;i<=n;i++)
// 		mp[a[i]=input()]=a[i];
// 	for (int i=2;i<=n;i++)
// 		for (int j=a[i-1]+1;j<=a[i];j++)
// 			mp[j]=a[i];
// 	// for (int i=1;i<=n;i++)
// 	// 	for (int j=1;a[i]*j<=a[n];j++)
// 	// 		if (mp[a[i]*j]>=a[i])
// 	// 			ans=max(ans,mp[a[i]*j]%a[i]);
// 	for (int i=1;i<=n;i++)
//     	if (a[i]!=a[i-1])
// 		{
// 			ans=max(ans,a[n]%a[i]);
//       		for (int j=a[i]<<1;j<=a[n];j+=a[i])
//         		ans=max(ans,mp[j-1]%a[i]);
// 		}
// 	print(ans,'\n');
// 	return 0;
// }

#include<cstdio>
#include<algorithm>
#define N 1000005
using namespace std;
int a[N],last[N],i,j,ans,n,s;
int main()
{
//   freopen("animal10.in","r",stdin);
//   freopen("animal10.out","w",stdout); 
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]),last[a[i]]=a[i];
  sort(a+1,a+n+1);s=a[n];
  for (i=1;i<=s;i++)
    last[i]+=(last[i]==0)*last[i-1];
  for (i=1;i<=n;i++)
    if (a[i]!=a[i-1])
      for (ans=max(ans,s%a[i]),j=a[i]<<1;j<=s;j+=a[i])
        ans=max(ans,last[j-1]%a[i]);
  printf("%d",ans);
}
