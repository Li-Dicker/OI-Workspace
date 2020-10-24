
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int c[5000002][3],last[5000002],mlen[5000002];
int cnt=1,rt=1;
int n,m;

void Build(int num,string s) {
    int len=s.length(),x=rt;
    for (int i=0;i<len;i++) {
        if (!c[x][s[i]-'a']) x=c[x][s[i]-'a']=++cnt;
        else x=c[x][s[i]-'a'],mlen[x]=max(mlen[x],num-last[x]-1);
        last[x]=num;
    }
}

int Search(string s) {
    int len=s.length(),x=rt;
    for (int i=0;i<len;i++)
    if (!(x=c[x][s[i]-'a'])) return n;
    return mlen[x]=max(mlen[x],n-last[x]);
}

void Solve() {
    ifstream fin("word.in");
    fin>>n>>m;
    string s;
    for (int i=1;i<=n;i++)
    fin>>s,Build(i,s);
    for (int i=1;i<=m;i++)
    fin>>s,printf("%d\n",Search(s));
}

int main() {
    freopen("word.out","w",stdout);
    Solve();
    fclose(stdout);
}