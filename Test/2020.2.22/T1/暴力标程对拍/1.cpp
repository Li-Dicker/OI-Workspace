#include<bits/stdc++.h>
#define int long long
#define MK 5010
using namespace std;
int n;
int a[MK];

signed main()
{
  while(~scanf("%lld",&n))
  {
    int sum = 0;
      for(int i=1;i<=n;i++)
      {
          char t;
          cin>>t;
          a[i] = t-'0';
          sum += a[i];
      }
      int vis = 0;
      for(int k=0;k<=sum;k++)
      {
          int rec = 0;
          int t = 0;
          int flag = 1;
          for(int i=1;i<=n;i++)
          {
              rec += a[i];
              if(rec == k)
              {
                t++;
                rec = 0;
                continue;
               }
              if(rec>k)
            {
              flag = 0; 
              break;
            }
          }
          if(flag && t>1 && !rec) 
          {
            printf("YES\n");
            vis = 1;
            break;
          }
      }
      if(vis)
      {
        continue;
      }
      printf("NO\n");
  }
    return 0;
}