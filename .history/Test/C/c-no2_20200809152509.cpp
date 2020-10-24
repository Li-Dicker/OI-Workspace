#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,cnt[105],ct,qd,t,ld[205];
bool b[205],lu[105][205],qdf=0;
struct N{
　　int hd;int to;int next;
}edge[205];
void add(int x,int y)
{
　　ct++;
　　edge[ct].to=y;
　　edge[ct].hd=x;
　　edge[ct].next=cnt[x];
　　cnt[x]=ct;
}
void pd()
{
　　t++;
　　memcpy(lu[t],b,sizeof lu[t]);
　　for(int i=1;i<t;i++)
{
　　　　bool fl=0;
　　　　for(int j=1;j<=m*2;j++)
　　　　if(lu[i][j]!=lu[t][j])fl=1;
　　　　if(!fl)//若完全相同,撤销该路 
　　　　{
　　　　　　memset(lu[t],0,sizeof lu[t]);
　　　　　　t--;
　　　　　　break;
　　　　} 
}
}
void dfs(int k)
{
　　if(k==qd&&!qdf)
{
　　　　pd();return;
}
　　qdf=0;
　　for(int i=cnt[k];i>0;i=edge[i].next)
{
　　　　if(b[i])continue;//边 
　　　　b[i]=1;b[ld[i]]=1;
　　　　dfs(edge[i].to);
　　　　b[i]=0;b[ld[i]]=0;
}
}
int main()
{
　　scanf("%d%d",&n,&m);
　　for(int i=1;i<=m;i++)
{
　　　　int a,b;
　　　　scanf("%d%d",&a,&b);
　　　　add(a,b);
　　　　ld[ct]=ct+1;
　　　　add(b,a);
　　　　ld[ct]=ct-1;
}
　　for(int i=1;i<=n;i++)
{
　　　　memset(b,0,sizeof b);
　　　　qd=i;qdf=1;
　　　　dfs(i);
}
　　printf("%d",t);
　　return 0;
}