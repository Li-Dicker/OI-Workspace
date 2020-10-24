#include<bits/stdc++.h>
using namespace std;

int n,cnt,ps=1;

int main(){
	scanf("%d",&n);
	while(1){
		if(ps==1&&cnt){printf("%d\n",cnt);break;}
		while(ps<=n)ps<<=1,cnt++;
		ps=2*(ps-n)-1;cnt++;
	}
	std::cout << "The run time is: " <<(double)clock() / CLOCKS_PER_SEC << "s" << std::endl;
	return 0;
}
