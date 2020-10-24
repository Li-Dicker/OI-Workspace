#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 50005
#define rgt register

int N, M, cnt[MAXN], mu[MAXN], p[MAXN], tot, v[MAXN];
LL s[MAXN];
LL ans(0);

int main(){
	scanf( "%d", &N ); for ( rgt int i = 1, x; i <= N; ++i ) scanf( "%d", &x ), ++cnt[x], M = max( M, x );
	N = M, mu[1] = 1;
	for ( rgt int i = 2; i <= N; ++i ){//线性筛出mu
		if ( !v[i] ) p[++tot] = i, mu[i] = -1;
		for ( rgt int j = 1; j <= tot && i * p[j] <= N; ++j ){
			v[i * p[j]] = 1;
			if ( i % p[j] == 0 ){ mu[i * p[j]] = 0; break; }
			else mu[i * p[j]] = -mu[i];
		}
	}
	
	for ( rgt int i = 1; i <= N; ++i )
		for ( rgt int j = i; j <= N; j += i )
			s[j] += 1ll * mu[i] * i,cout<<mu[j]<<' ';//预处理提到过的那玩意
	
	for ( rgt int T = 1; T <= N; ++T ){
		rgt LL cur(0);
		for ( rgt int i = 1, I = N / T; i <= I; ++i ) cur += 1ll * cnt[i * T] * i;//暴力求解
		ans += T * cur * cur * s[T];
	} printf( "%lld\n", ans );
	return 0;
}