#include<bits/stdc++.h>
#define int long long
#define N 11111
#define INF 0x3f3f3f3f
using namespace std;

int l,r;
int len=0;
int num[11];
int dp[11][11][3][3];
//从高往低的第i位，上一位为k，上一位压位的情况为l,上一位前导0的情况为m

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

int dfs(int pos,int last,int yw,int lead)
//现在搜到了第pos位，上一位是last，上一位是否压位，上一位是否为前导0
{
	if (pos==1)
		return dp[pos][last][yw][lead]=1;
	//搜索边界
	if (yw==1)
	{
		//首先是因为记忆化搜索，所以下一个情况的dp一定为-1，其次如果上一个数是前导0或者满足windy数的要求 
		if ((lead==1||abs(num[pos]-last)>=2)&&dp[pos-1][num[pos]][1][(num[pos]==0)]==-1)
			dp[pos-1][num[pos]][1][(num[pos]==0)]=dfs(pos-1,num[pos],1,(num[pos]==0));
			//搜索下一位压位的情况 
		for (int i=num[pos]-1;i>=0;i--)
		//首先是因为记忆化搜索，所以下一个情况的dp一定为-1，其次如果上一个数是前导0或者满足windy数的要求 
			if ((lead==1||abs(i-last)>=2)&&dp[pos-1][i][0][(i==0)]==-1)
				dp[pos-1][i][0][(i==0)]=dfs(pos-1,i,0,(i==0));
				//搜索下一位不压位的情况 
	}
	else
	{
		for (int i=9;i>=0;i--)
			if ((lead==1||abs(i-last)>=2)&&dp[pos-1][i][0][(i==0)]==-1)
				dp[pos-1][i][0][(i==0)]=dfs(pos-1,i,0,(i==0));
				//搜索下一位不压位的情况 
	}
    return INF;
}

int query(int x)
{
	if (x==-1||x==0)
		return 0;
	memset(dp,-1,sizeof(dp));
	len=0;
	int res=0;
	while (x)
	{
		len++;
		num[len]=x%10;
		x/=10;
	}//把这个数字拆到数组中
	dp[len][0][1][1]=dfs(len,0,1,1);
	return dp[len][0][1][1];
}

signed main()
{
	l=input(),r=input();
	print(query(r)-query(l-1),'\n');
	return 0;
}		