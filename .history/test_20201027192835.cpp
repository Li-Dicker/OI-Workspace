#include <bits/stdc++.h>
using namespace std;

inline int read(int u = 0, char c = getchar(), bool f = false) {
	for (;!isdigit(c); c = getchar()) f |= c == '-';
	for (; isdigit(c); c = getchar()) u = (u << 1) + (u << 3) + c - '0';
	return f ? -u : u;
}

const int maxn = 10;
const int oo = 1e9 + 7;

int a[maxn][maxn], b[maxn][maxn];

int f[1 << (maxn << 1)];

int dfs(int sta, bool who, int n, int m) {
	if (~f[sta]) return f[sta];
	f[sta] = who ? -oo : oo;
	int x = n, y = 0;
	for (int i = 0; i < n + m - 1; i++) {
		if (sta >> i & 1) x--; else y++;
		if ((sta >> i & 3) != 1) continue;
		int nxt = sta ^ (3 << i);
		if (who) 
			f[sta] = max(f[sta], dfs(nxt, who ^ 1, n, m) + a[x][y]);
		else 	
			f[sta] = min(f[sta], dfs(nxt, who ^ 1, n, m) - b[x][y]);
	}	
	return f[sta];	
		
}

int main() {
	int n = read(), m = read(); 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = read();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[i][j] = read();
	memset(f, 0xff, sizeof(f));
	f[((1 << n) - 1) << m] = 0;
	cout << dfs((1 << n) - 1, 1, n, m) << endl;
}