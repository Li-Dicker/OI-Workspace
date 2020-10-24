
#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define fuck printf("fuck")
#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w+",stdout)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
const int MX = 200000 + 5;
const int ME = 400000 + 5;
 
int Head[MX], Next[ME], rear;
struct Edge {
    int u, v;
} E[ME];
void edge_init() {
    rear = 0;
    memset(Head, -1, sizeof(Head));
}
void edge_add(int u, int v) {
    E[rear].u = u;
    E[rear].v = v;
    Next[rear] = Head[u];
    Head[u] = rear++;
}
 
bool vis[MX];
int ga, gb, gans;
int F[MX], dep[MX];
 
struct Data {
    int u, f, d;
    Data(int _u, int _f, int _d) {
        u = _u; f = _f; d = _d;
    }
};
 
void build() {
    queue<PII>Q;
    Q.push(PII(1, 0));
    F[1] = -1; dep[1] = 0;
 
    while(!Q.empty()) {
        PII f = Q.front();
        Q.pop();
 
        int u = f.first, d = f.second;
        for(int i = Head[u]; ~i; i = Next[i]) {
            int v = E[i].v;
            if(v == F[u]) continue;
 
            F[v] = u; dep[v] = d + 1;
            Q.push(PII(v, d + 1));
        }
    }
}
 
int deal(int u, int x) {
    int ret = 0;
    queue<Data>Q;
    Q.push(Data(u, -1, x));
 
    while(!Q.empty()) {
        Data t = Q.front();
        Q.pop();
 
        int u = t.u, f = t.f, d = t.d;
        if(!vis[u]) ret += ++vis[u];
 
        if(d) for(int i = Head[u]; ~i; i = Next[i]) {
                int v = E[i].v;
                if(v == f) continue;
                Q.push(Data(v, u, d - 1));
            }
    }
    return ret;
}
 
bool check(int n, int x) {
    memset(vis, 0, sizeof(vis));
 
    int u = 1, cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(dep[i] > dep[u]) u = i;
    }
 
    for(int i = x; i >= 1 && F[u] != -1; i--, u = F[u]);
    ga = u;
    cnt += deal(u, x);
    if(cnt == n) {
        if(ga == 1) gb = 2;
        else gb = 1;
        return true;
    }
 
    u = -1;
    for(int i = 1; i <= n; i++) {
        if(!vis[i] && (u == -1 || dep[i] > dep[u])) u = i;
    }
 
    for(int i = x; i >= 1 && F[u] != -1; i--, u = F[u]);
    gb = u;
    cnt += deal(u, x);
    return cnt == n;
}
 
int main() {
    int T, n; //FIN;
    scanf("%d", &T);
    while(T--) {
        edge_init();
 
        scanf("%d", &n);
        for(int i = 1; i <= n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge_add(u, v);
            edge_add(v, u);
        }
        build();
 
        int ma, mb, mans;
        int L = 0, R = n, m;
        while(L <= R) {
            m = (L + R) >> 1;
            if(check(n, m)) {
                ma = ga;
                mb = gb;
                mans = m;
                R = m - 1;
            } else L = m + 1;
        }
        printf("%d\n", mans,);
    }
    return 0;
}
