#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;

int T,n,m,D,L;
int a[N];

namespace IOstream
{
    #define int long long
    #define print(a,b) prints(a),putchar(b)
    int BUF[22],BUFSIZE,IONUM,SIGN;
    char GET;

    inline int input()
    {
        IONUM=0,SIGN=1;
        GET=getchar();
        while (GET<'0'||GET>'9')
        {
            if (GET=='-')
                SIGN=-1;
            GET=getchar();
        }
        while (GET>='0'&&GET<='9')
        {
            IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
            GET=getchar();
        }
        return SIGN*IONUM;
    }

    inline void prints(int IONUM)
    {
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

signed main()
{
cin >> n >> m >> d >> l;
	S.clear();
	rep( i , 1 , n ) scanf("%d",A + i) , S.insert( A[i] );
	rep( i , 1 , m ) {
		int st = 0 , flg = 0;
		while( st + d < l && S.size() ) {
			auto to = S.upper_bound( st + d ); 
			if( to == S.begin() ) { flg = 1; break; }
			-- to;
			if( *to > st ) st = *to , S.erase( to );
			else { flg = 1; break; }
		}
		if( st + d < l || flg ) return void (printf("%d\n",i - 1));
	}
	puts("Excited");
	return 0;
}