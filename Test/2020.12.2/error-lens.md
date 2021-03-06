# T1 game

-   Statue: **AC**

-   思路：
    容易证明，对于数轴上任意两个点$x,y$，满足$x<y且a_x<a_y$，则对于任意出发点$s$满足$s<x$，从$s$直接跳到$y$是一定优于从$s$跳到$x$再从$x$跳到$y$的。所以根据这个性质，以$s$为起点的最优跳法一定是跳到$s$到$n$这一段区间上点权最大的点；然后以该点为起点继续跳到剩下这段区间上点权最大的点。如此反复，直至终点为止。

    关于当前区间的最大值，可以用一个数组$suf$表示从$i$号点开始到$n$号点这个区间上的最大值。令$suf[n]=a[n]$，那么对于$1-n$这段区间倒序枚举有$suf[i]=max(suf[i+1],a[i])$。然后把起点$s$设为初始值$0$，从$1$开始枚举，如果$a[i]=suf[i]$那么$i$点一定是区间$(s,n]$上的最大值，所以跳到点$i$，更新贡献和起点。

-   Opinions：

    1.  似乎可以考虑$dp$。令$dp[i][j]$表示当前已经处理到$i$号点，最后一次跳到了$j$号点。易得答案为$dp[n][n]$。然后发现第一位是不必要的。所以得到转移方程$dp[i]=min\{dp[j]+a[i]*(i-j)\}$。发现这个复杂度是$O(n^2)$的，这个式子看上去很像斜率优化的模板，于是考虑斜优。将$min$拆去，把括号拆开得到$dp[i]=dp[j]+a[i]\times i-a[i]\times j$。因为我们要求的是用哪个点来个更新$i$，也就是要求$j$是哪个，所以我们考虑把$j$作为自变量$x$，$dp[j]$作为因变量$y$。那么整理式子成点斜式之后就成为了$dp[j]=a[i]\times j+dp[i]-a[i]\times i$。考虑把$a[i]$作为斜率$k$，$dp[i]-a[i]\times i$作为截距$b$。

# T2 team

-   Statue: 20pts/30pts

-   思路：

    首先会想到并查集，但是因为可能会牵涉到删边，所以考虑反向建边连接并查集。连边之后发现和并查集不沾边，于是考虑图论。那么在正向建边的时候会发现我们要求的其实就是这个图上的两个完全子图使得他们俩的点数差最小（这是考场思路的错误点）。没有什么想法（其实这是个套路）。于是考虑反向建边，建边之后发现要找的就是这个二分图（一定是二分图，否则输出no）黑白染色之后的黑白点数量。最后的答案就是把自由点（与任何点都不能反向连边的点）填补到黑白点不足的地方上。

-   Statue:80pts

    思路：

    考场的错误点在于认为一定只有一个连通块。其实反向建边之后可能会形成多个连通块（自由点也可以看作是一个联通块），现在问题就变成了如何组合这些连通块成两组使得他们的差最小。
    
    所以考虑背包。设