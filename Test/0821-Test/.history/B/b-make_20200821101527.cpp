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
2 6
3 9
4 15
5 25
6 37
7 41
8 49
9 67
10 73
11 84
12 104
13 122
14 150
15 155
16 165
17 177
18 213
19 225
20 245
21 259
22 271
23 294
24 315
25 323
26 375
27 395
28 413
29 471
30 531
31 537
32 549
33 615
34 637
35 672
36 681
37 701
38 731
39 770
40 824
41 906
42 914
43 942
44 953
45 965
46 975
47 1011
48 1059
49 1089
50 1189
51 1240
52 1252
53 1358
54 1394
55 1430
56 1458
57 1502
58 1514
59 1538
60 1648
61 1668
62 1768
63 1775
64 1789
65 1919
66 1937
67 1973
68 2041
69 2179
70 2225
71 2285
72 2313
73 2355
74 2503
75 2518
76 2542
77 2562
78 2614
79 2666
80 2699
81 2861
82 2881
83 2964
84 3120
85 3138
86 3310
87 3370
88 3428
89 3606
90 3786
91 3846
92 3882
93 3922
94 3940
95 4035
96 4131
97 4143
98 4339
99 4438
100 4504
*/