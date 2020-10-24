#include<bits/stdc++.h>
using namespace std;

const double PI=3.1415926535897932384626433832795028841971;
int t,a,b,c,d;

bool check(int a,int b,int x,int y){
	if(a>=x&&b>=y)return 1;
	if(a<x&&b<y)return 0;
	double a1=a/2.0,b1=b/2.0,x1=x/2.0,y1=y/2.0,d1,d2,h1,h2;
	double lab=sqrt(a1*a1+b1*b1),lxy=sqrt(x1*x1+y1*y1);
	if(lab<lxy)return 0;
	if(lxy<=a1)h1=0;
	else{
		d1=sqrt(lxy*lxy-a1*a1);
		h1=atan2(d1,a1);h1=h1*180/PI;
	}
	if(lxy<=b1)h2=0;
	else{
		d1=sqrt(lxy*lxy-b1*b1);
		h2=atan2(d1,b1);h2=h2*180/PI;
	}
	return atan2(x1,y1)*180/PI*2<=(90-h1-h2);
}

int main(){
	scanf("%d",&t);while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>b)swap(a,b);if(c>d)swap(c,d);
		if(check(a,b,c,d)||check(c,d,a,b))puts("YES");
		else puts("NO");
	}
	return 0;
}
