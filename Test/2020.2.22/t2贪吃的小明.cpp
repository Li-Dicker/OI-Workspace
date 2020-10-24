#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[20],v[20][20],dp[1<<18][20];
int main()
{
  int n,m,k,x,y;
  cin >> n >> m >> k;
  for(int i = 1 ; i <= n ; i++)
  {
    cin >> a[i];
    dp[1<<(i-1)][i] = a[i];
  }
  ll c;
  for(int i = 1 ; i <= k ; i++)
  {
    cin >> x >> y >> c;
    v[x][y] = c;
  }
  ll ans = 0;
  for(int i = 1 ; i < (1<<n) ; i++)
    for(int j = 1 ; j <= n ; j++)
      if(i & 1<<(j-1))
        for(int k = 1 ; k <= n ; k++)
          if(!(i & 1<<(k-1)))
            dp[i | (1<<k-1)][k] = max(dp[i | (1<<k-1)][k], dp[i][j]+a[k]+v[j][k]);
  for(int i = 1 ; i < (1<<n) ; i++)
    if(__builtin_popcount(i) == m)
      for(int k = 1 ; k <= n ; k++)
        ans = max(ans, dp[i][k]);
  cout << ans << endl;
  return 0;
}
