#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,fa[100015];
int zhao(int xx){
  if(fa[xx]==xx) return xx;
  else return zhao(fa[xx]);
}
int main(){
    srand(time(0));
    int n=rand()%2000+2;
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
    fa[i]=i;
  }
    while(cnt<n-1){
        int x=rand()%n+1,y=rand()%n+1;
        int x1=zhao(x),y1=zhao(y);
        if(x1!=y1){
      fa[x1]=y1,cnt++;
      printf("%d %d\n",x,y);
    }
    }
    return 0;
}