#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int T,n,m,r0,c0;
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

signed main()
{
    T=input();
    loop:
    while (T--)
    {
        n=input(),m=input();
        r0=input(),c0=input();
        if (n>m)
            swap(n,m),swap(r0,c0);
        if (n==1)
        {
            puts("Poor Watame");
            goto loop;
        }
        else if (n==2)
        {
            print(2,'\n');
            goto loop;
        }
        else if (n==3)
        {
            if ((r0==1||ro==3)&&c0==1)
            {
                if (m%2)
                    puts("Poor Watame");
                else
					print(4,'\n');
				goto loop;
            }
			else if (ro==2&&c0==1)
			{
				if (m%2)
                    puts("Poor Watame");
                else
					print(4,'\n');
				goto loop;
			}
			else
			{
				// if (m%2)
				print(4,'\n');
				goto loop;
			}
        }
		else if (n==4)
		{
			if (r0==2&&c0==1)
			{
				if (m%2)
			}
		}
    }
    return 0;
}