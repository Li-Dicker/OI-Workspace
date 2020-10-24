#include<bits/stdc++.h>
using namespace std;
int t,a1,a2,b1,b2,flag;
int main()
{
    scanf("%d",&t);
    while(t--)
	{
        flag=0;
        scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
        if(a1*b1<=a2*b2)
		{
            for(double i=0;i<=90;i+=0.01)
			{
                double du=i*3.1415926/180;
                if(a1*cos(du)+b1*sin(du)<=a2&&a1*sin(du)+b1*cos(du)<=b2)
				{
                    flag=1;
                    printf("Yes\n");
                    break;
                }
            }    
            if(!flag)
            {
            	printf("No\n");
			}
       	}
        else
		{
            for(double i=0;i<=90;i+=0.01)
			{
                double du=i*3.1415926/180;
                if(a2*cos(du)+b2*sin(du)<=a1&&a2*sin(du)+b2*cos(du)<=b1)
				{
                    flag=1;
                    printf("YES\n");
                    break;
                }
            }
            if(!flag)
            {
            	printf("NO\n");
			}
       	}
	}
    return 0;
}