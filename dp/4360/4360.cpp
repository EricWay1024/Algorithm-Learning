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
#include<cstdint>
#include<climits>
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(register int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 21234
ll f[N], dis[N], s[N], q[N], l, r, n, d[N], w[N], tot;

#define xx(j) (s[j])
#define yy(j) (dis[j]*s[j])
#define slope(j1,j2) ((double)(yy(j1)-yy(j2))/(xx(j1)-xx(j2)))

int main() {
#ifdef D
    freopen("4360.in", "r", stdin);
    double TIMEA = clock();
#endif
    n=read();
    rep(i,1,n){
        w[i]=read(),d[i]=read();
        s[i]=s[i-1]+w[i];
        tot+=d[i]*s[i];
    }
    rev(i,n,1){
        dis[i]=dis[i+1]+d[i];
    }
    l=r=1;
    rep(i,1,n){
        while(l<r && slope(q[l], q[l+1])>dis[i]) ++l;
        auto j=q[l]; f[i]=tot-dis[j]*s[j]-dis[i]*(s[i]-s[j]);
        while(l<r && slope(q[r-1], q[r])<slope(q[r-1], i)) --r;
        q[++r]=i;
    }
    auto ans = *min_element(f+1, f+1+n);
    cout << ans << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}