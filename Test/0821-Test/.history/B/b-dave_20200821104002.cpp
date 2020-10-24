#include<bits/stdc++.h>
using namespace std;

int n,cnt,ps=1;

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	while(1){
		if(ps==1&&cnt){printf("%d\n",cnt);break;}
		while(ps<=n)ps<<=1,cnt++;
		ps=2*(ps-n)-1;cnt++;
	}
	return 0;
}
