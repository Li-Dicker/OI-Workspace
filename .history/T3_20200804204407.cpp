#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int T,n,a[maxn],b[maxn],ans[maxn],lst,l,r;
multiset<int>s;

int main(){
	scanf("%d",&T);while(T--){
		scanf("%d",&n);l=r=1;s.clear();
		for(register int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(register int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			if(!s.count(a[i]))s.insert(a[i]);
			else s.erase(a[i]);
			if(!s.count(b[i]))s.insert(b[i]);
			else s.erase(b[i]);
			if(s.empty()){
				for(register int i=l;i<=r;i++){
					ans[a[i]]=lst;
				}lst=a[l];l=r=r+1;
			}
			else r++;
		}
		if(a[1]!=b[1])printf("No");
		else{
			puts("Yes");
			for(register int i=1;i<=n;i++){
				printf("%d",ans[i]);
				if(i!=n)printf(" ");
			}
		}
		if(T)puts("");
	}
	return 0;
}
