#include<bits/stdc++.h>
#define int long long
#define N 1111
#define INF 0x3f3f3f3f
using namespace std;

int n,m,tmp1,tmp2,edgenum=0,ans;
int head[N*N*2],vis[N];
int mp[N][N];
struct Edge
{
    int v,next;
}edge[N*N*2];
stack<int >st;

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

void adde(int u,int v)
{
    edge[++edgenum].next=head[u];
    head[u]=edgenum;
    edge[edgenum].v=v;
}

void work(int v)
{
    stack<int >tong;
    int tmpe=st.top(),cnt=1;
    st.pop();
    tong.push(tmpe);
    tmpe=-1;
    while (tmpe!=v&&!st.empty())
    {
        tmpe=st.top();
        st.pop();
        tong.push(tmpe);
        cnt++;
    }
    if (cnt%2&&tmpe==v)
        ans+=cnt;
    while (cnt--)
    {
        tmpe=tong.top();
        tong.pop();
        st.push(tmpe);
        vis[tmpe]=0;
    }
}

void dfs(int fa,int u)
{
    vis[u]=1;
    for (int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (fa==v)
            continue ;
        if (vis[v])
            vis[v]=1,work(v);
        else
        {
            st.push(v);
            dfs(u,v);
        }
    }
    st.pop();
    vis[i]=0;
}

signed main()
{
    n=input(),m=input();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            mp[i][j]=1;
    for (int i=1;i<=m;i++)
    {
        tmp1=input(),tmp2=input();
        mp[tmp1][tmp2]=0;
        mp[tmp2][tmp1]=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (mp[i][j]&&i!=j)
                adde(i,j);
    for (int i=1;i<=n;i++)
        if (!vis[i])
        {
            st.push(i);
            dfs(0,i);
        }
    print(n-ans,'\n');
    return 0;
}
/*

5 5
1 4
1 5
2 5
3 4
4 5

5 4
1 4
1 5
3 4
4 5

*/