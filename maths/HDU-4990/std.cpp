#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<vector>

const int MAX=100000*2;
const int INF=1e9;

int main()
{
#ifdef D
    freopen("HDU-4990.in", "r", stdin);
#endif
  int n,m,ans,i;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
    ans=0;
    for(i=1;i<=n;i++)
    {
      if(i&1)ans=(ans*2+1)%m;
      else ans=ans*2%m;
    }
    printf("%d\n",ans);
  }
  return 0;
} 