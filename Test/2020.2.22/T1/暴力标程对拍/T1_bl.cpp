#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
char s[5005];
int a[5005];
int b[5005];
int c[200];
int d[5005];
int num,sum;
int ch(int x)
{
  int now=0;
  for(int i=0;i<n;i++)
  {
    now+=a[i];
    if(now==x)
    {
      now=0;
      continue;
    }
    if(now>x)
    {
      return 0;
    }
  }
//  cout<<x<<endl;
  return 1;
}
int zs(int x)
{
  for(int i=2;i<x;i++)
  {
    if(x%i==0)
    {
      c[sum++]=x/i;
    }
  }
  if(c[0])
  {
    return 0;
  }
  return 1;
}
int main()
{
  while(~scanf("%d",&n))
  {
    num=0;
    sum=0;
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
      a[i]=s[i]-'0';
      b[i]=a[i];
      num+=a[i]; 
    }
//    cout<<num<<endl;
    if(zs(num)==1)
    {
      if(n==num)
      {
        printf("YES\n");
        continue;
      }
      printf("NO\n");
      continue;
    }
    sort(b,b+n);
//    for(int i=0;i<sum;i++)
//    {
//      cout<<c[i]<<" ";
//    }
    if(b[n-1]>c[0])
    {
      printf("NO\n");
      continue;
    }
//    cout<<endl;
    for(int i=0;i<sum;i++)
    {
      if(b[n-1]>c[i])
      {
        printf("NO\n");
        break;
      }
      else
      {
        if(ch(c[i])==1)
        {
          printf("YES\n");
          break;
        }
      }
    }
  }
  return 0;
}