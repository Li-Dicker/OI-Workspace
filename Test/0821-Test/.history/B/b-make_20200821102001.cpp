#include<bits/stdc++.h>
#define int long long
#define N 111111
#define INF 0x3f3f3f3f
using namespace std;
int n,ans=0;
int a[N],b[N];
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

bool check()
{
    for (int i=1;i<=n*2;i++)
        if (b[i]!=i)
            return false;
    return true;
}

signed main()
{
    // n=input();
    for (int sss=1;sss<=100;sss++)
    {
        ans=0;
        n=sss;
        for (int i=1;i<=n*2;i++)
            a[i]=i;
        do
        {
            ans++;
            for (int i=1;i<=n;i++)
                b[i*2]=a[i];
            for (int i=1;i<=n;i++)
                b[i*2-1]=a[i+n];
            for (int i=1;i<=n*2;i++)
                // print(a[i]=b[i],' ');
                a[i]=b[i];
            // puts("");
            if (check())
            {
                print(n,' ');
                print(ans,'\n');
                break ;
            }
        }
        while (1==1);
    }
    return 0;
}
/*
1 2 
2 4 

3 3 
4 6 
5 10
6 12
7 4

8 8
9 18
10 6

11 11
12 20
13 18
14 28
15 5
16 10
17 12
18 36
19 12

20 20
21 14
22 12

23 23
24 21
25 8
26 52
27 20
28 18
29 58
30 60
31 6
32 12
33 66
34 22

35 35
36 9
37 20
38 30

39 39
40 54
41 82
42 8
43 28
44 11
45 12
46 10
47 36
48 48
49 30
50 100
51 51
52 12
53 106
54 36
55 36
56 28
57 44
58 12
59 24
60 110
61 20
62 100
63 7
64 14
65 130
66 18
67 36

68 68
69 138
70 46
71 60
72 28
73 42
74 148
75 15
76 24
77 20
78 52
79 52
80 33
81 162
82 20
83 83
84 156
85 18
86 172
87 60
88 58
89 178
90 180
91 60
92 36
93 40
94 18
95 95
96 96
97 12
98 196
99 99
100 66
*/