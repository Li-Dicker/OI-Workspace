#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
using namespace std;

namespace IO {
	#define gc getchar()
	template<typename T> void read(T& x) {
		x = 0; bool f = true; char ch = gc;
		for (; ch < '0' || '9' < ch; ch = gc) if (ch == '-') f &= false;
		for (; '0' <= ch && ch <= '9'; ch = gc) x = x * 10 + ch - '0';
		x = f ? x : -x;
	}
}

typedef long long ll;

const int MAXN = 300 + 10;
const int MAXM = 300 + 10;

int n, m, k, e[MAXN][MAXN];

namespace Subtask1 {
	#define in(S, i) ((S >> (i - 1)) & 1)
	ll ans;
	void work(int S) {
		ll res = 0;
		rep(i, 1, n) {
			rep(j, 1, i - 1) {
				if (i == j) continue;
				if (in(S, i) && in(S, j) && e[i][j]) res++;
			}
		}
		ll tmp = res;
		rep(i, 1, k - 1) res = res * tmp;
		ans += res;
	}
	void solve() {
		rep(S, 0, (1 << n) - 1) {
			work(S);
		}
		printf("%lld\n", ans);
	}
}

namespace Subtask2 {
	ll ans;
	void solve() { printf("%lld\n", 1ll * m * (1 << (n - 2))); return ; }
}

int main() {
	IO::read(n), IO::read(m), IO::read(k);
	rep(i, 1, m) {
		int u, v; IO::read(u), IO::read(v);
		e[u][v] = e[v][u] = true;
	}
	if (n <= 15) Subtask1::solve();
	else Subtask2::solve();
	return 0;
}