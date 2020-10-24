#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,b[5010],c[5010],d=0;
char a[5001];
int binarySearch(int left,int target)
{ 
    int right =n;
    while(left <= right) {
        int mid = (right + left) / 2;
        if(c[mid] == target)return mid; 
        else if (c[mid] < target)left = mid + 1;
        else if (c[mid] > target)right = mid - 1;
    }
    return -1;
}
bool chaz(int l,int target,int y)
{
  int x=binarySearch(l,target);
  if(x==-1)return 0;
  if(x==n)return 1;
  return chaz(x,target+y,y);
}
int main()
{
  while(~scanf("%d",&n))
  {
    d=0;
    memset(c,0,sizeof(c));
    scanf("%s",a);
    for(int i=0;i<n;i++)
    {
      b[i+1]=a[i]-'0';
      c[i+1]=b[i+1]+c[i];
    }
    for(int i=1;i<n;i++)if(c[i]!=0)if(c[n]%c[i]==0)
    {
      if(chaz(i,2*c[i],c[i])==1)
      {
        printf("YES\n");
        d=1;
        break;
      }
      else continue;
    }
    if(d==0)printf("NO\n");
  }
  return 0;
}