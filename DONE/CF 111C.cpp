#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
signed main()
{//转化问题为一个蜘蛛可以攻击到上下左右，求最少放多少蜘蛛
    scanf("%d%d",&n,&m);
    if (n>m)
        swap(n,m);
    if (n==1)//只有一行的情况，那么一定可以攻击到左右两边
    {
        ans+=(m/3);//每只蜘蛛占了3个位置
        if (m%3)
        	ans++;//最后一只蜘蛛可能只占1或2只
    }
    else if (n==2)//有两行的情况，无论在哪里放，攻击的都是正着或反着的T形（上3下1或上1下3），边界因为外部不影响，所以一定是上2下1或者上1下2的情况或者只有一个
    	ans=m/2+1;
    else if (n==3)//T形可以横着竖着放，每3x5就只用4个，3x4也要用4个，3x3用3个,3x2用2个，3x1用1个
	    ans=m-(m-1)/4;
    else if (n==4)//仍然是T形
    {
        ans=(m+1);
        if (m==4||m==7||m==8||m==10)
        	ans--;
    }
    else if (n==5)//仍然是T形
    {
    	if (m==5)
    		ans=7;
    	else if (m==6)
    		ans=8;
    	else if (m==7)
    		ans=9;
    	else if (m==8)
    		ans=11;
    }
    else if (n==6)//暴力求解
        ans=10;
    ans=n*m-ans;
    printf("%lld\n",ans);
    return 0;
}