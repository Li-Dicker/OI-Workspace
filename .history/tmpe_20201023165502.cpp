#include<bits/stdc++.h>
using namespace std;
struct rec
{
    int nxt;
    int to;
}e[200001];
struct node
{
    int x;
    int c;
}q[100001];
int N,M,Q;
int head[100001],cnt;
int root[100001],trsum[10000001],ls[10000001],rs[10000001],tot;
int k[100001];
int dfsv[100001];
bool vis[100001];
int sum;
int ans[100001];
bool cmp(node a,node b){return a.c<b.c;}
void add(int x,int y)
{
    e[++cnt].nxt=head[x];
    e[cnt].to=y;
    head[x]=cnt;
}
void insert(int &x,int k,int l,int r)
{
    if(!x)x=++tot;
    if(l==r)
    {
        trsum[x]=1;
        return;
    }
    int mid=(l+r)>>1;
    if(k<=mid)insert(ls[x],k,l,mid);
    else insert(rs[x],k,mid+1,r);
    trsum[x]=trsum[ls[x]]+trsum[rs[x]];
}
int merge(int x,int fl,int l,int r)//合并
{
    if(!x||!fl)return x+fl;
    if(l==r)
    {
        trsum[x]=trsum[x]||trsum[fl];
        return x;
    }
    int mid=(l+r)>>1;
    ls[x]=merge(ls[x],ls[fl],l,mid);
    rs[x]=merge(rs[x],rs[fl],mid+1,r);
    trsum[x]=trsum[ls[x]]+trsum[rs[x]];
    return x;
}
void dfs(int x)
{
    vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt)
        if(!vis[e[i].to])
        {
            dfs(e[i].to);
            root[x]=merge(root[x],root[e[i].to],1,M);
        }
    ans[x]=trsum[root[x]];
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<N;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=N;i++)
        scanf("%d",&k[i]);
    scanf("%d",&M);
    for(int i=1;i<=M;i++)
        scanf("%d%d",&q[i].x,&q[i].c);
    sort(q+1,q+M+1,cmp);
    for(int i=1;i<=M;i++)
    {
        if(q[i].c!=q[i-1].c)sum++;//算是一个预处理吧，思路有些清奇
        insert(root[q[i].x],sum,1,M);
    }
    dfs(1);
    scanf("%d",&Q);
    while(Q--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}