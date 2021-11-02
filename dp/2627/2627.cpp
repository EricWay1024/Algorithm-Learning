//#include <bits/stdc++.h>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#include<numeric>
#include<functional>
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
int n, k;
const int N = 101000;
ll a[N], s[N]; int q[N];
ll f[N][2];
ll target(int j) {
    return f[j][0] - s[j];
}

int main() {
#ifdef D
    freopen("2627.in", "r", stdin);
    double TIMEA = clock();
#endif
    n=read(),k=read();
    rep(i,1,n){
        a[i]=read();s[i]=s[i-1]+a[i];
    }
    int l=1; int r=1;
    q[1]=0;
    rep(i,1,n) {
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        while(l<=r && q[l]<i-k) l++;
        f[i][1]=s[i]+target(q[l]);
        while(l<=r && target(q[r])<=target(i))r--;
        q[++r]=i;
    }
    cout<<max(f[n][0], f[n][1])<<endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}