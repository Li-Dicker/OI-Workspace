#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=114514;
vector<int>v[N];
ll w[N],ans; 
int sz[N],n,m,x[N],y[N],fa[N];

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

void dfs(int x,int f){
	sz[x]=1;
	for(int i=0,to,z;i<v[x].size();i+=2){
		to=v[x][i],z=v[x][i+1];
		if(to==f)continue;
		dfs(to,x),sz[x]+=sz[to];
		ans+=z*sz[to]*(n-sz[to]);fa[to]=x;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%lld",&x[i],&y[i],&w[i]);
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
		v[x[i]].push_back(w[i]);
		v[y[i]].push_back(w[i]);
	}
	dfs(1,0);
	for(int i=1,id,val;i<=m;i++){
		scanf("%d%d",&id,&val);
		int s1=x[id],s2=y[id];
		if(fa[s1]==s2)swap(s1,s2);
		ans+=1ll*(val-w[id])*sz[s2]*(n-sz[s2]);
		w[id]=val;printf("%lld\n",ans);
	}
	return 0;
}