#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
#define MOD ((int)1e9+7)
#define next _nxt_
#define y1 _yy_
using namespace std;
namespace IOstream {
	#define print(a,b) prints(a),putchar(b)
	int BUF[22],BUFSIZE,IONUM,SIGN;
	char GET;

	inline int input() {
		IONUM=0,SIGN=1;
		GET=getchar();
		while (GET<'0'||GET>'9') {
			if (GET=='-')
				SIGN=-1;
			GET=getchar();
		}
		while (GET>='0'&&GET<='9') {
			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
			GET=getchar();
		}
		return SIGN*IONUM;
	}

	inline void prints(int IONUM) {
		if (IONUM<0)
			IONUM=-IONUM,putchar('-');
		do
			BUF[++BUFSIZE]=IONUM%10,IONUM/=10;
		while (IONUM);
		while (BUFSIZE)
			putchar(BUF[BUFSIZE--]+'0');
	}

}
using namespace IOstream;

int L,R,ans=0;
int days[15][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

struct Date {
	int year,month,day;
}last;

bool check_year(int x) {
	if (x%400==0)
		return true;
	if (x%100==0)
		return false;
	if (x%4==0)
		return true ;
	return false;
}

int change(Date res) {
	int x=0;
	x=res.year*10000+res.month*100+res.day;
	return x;
}

Date change(int x) {
	Date res;
	res.year=x/10000,res.month=(x%10000)/100,res.day=x%100;
//	print(res.year,' '),print(res.month,' '),print(res.day,'\n');
	return res;
}

Date add(Date res) {
	res.day++;
	int flag=0;
	if (check_year(res.year))
		flag=1;
	if (res.day>days[res.month][flag])
		res.month++,res.day=1;
	if (res.month==13)
		res.year++,res.month=1;
	return res;
}

int add(int x) {
	Date res=change(x);
	res=add(res);
	return change(res);
}

signed main() {
	freopen("date.in","r",stdin);freopen("date.out","w",stdout);
	L=input(),R=input();
	last=change(R);
	for (int i=L;i<=R;i=add(i))
		if (i%7==0)
			ans++;
	print(ans,'\n');
	return 0;
}
