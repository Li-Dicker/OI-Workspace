#include<bits/stdc++.h>
using namespace std;

int t,n,a[100005],vis[100005],ans;

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

int dfs(int x){
	vis[x]=1;
	if(!vis[a[x]])return dfs(a[x])+1;
	else return 1;
}

signed main(){
	t=input();
	while(t--){
		n=input();memset(vis,0,sizeof(vis));ans=0;
		for(register int i=1;i<=n;i++)a[i]=input();
		for(register int i=1;i<=n;i++)
			if(!vis[i])ans+=dfs(i)-1;
		printf("%d\n",ans);
	}
	return 0;
}