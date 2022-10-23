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
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 312345
ll n, st[N], sc[N], q[N], l, r, s, f[N];

ll xx(ll j) {return sc[j];}
ll yy(ll j) {return f[j]-s*sc[j];}
ll dx(ll j1, ll j2) {return xx(j1)-xx(j2);}
ll dy(ll j1, ll j2) {return yy(j1)-yy(j2);}
double slope(ll j1, ll j2) {
    // very important: dx == 0
    if (dx(j1, j2) == 0) return numeric_limits<double>::infinity();
    else return (double)dy(j1, j2) / dx(j1, j2);
}

ll binary_search(ll k) {
    if (l==r) return q[l];
    ll L = l; ll R = r;
    while (L < R) {
        ll M = (L + R) >> 1;
        if (slope(q[M+1], q[M]) <= (double)k) L = M + 1;
        else R = M;
    }
    return q[L];
}

int main() {
#ifdef D
    freopen("5785.in", "r", stdin);
    double TIMEA = clock();
#endif
    n=read(),s=read();
    rep(i,1,n){
        st[i]=st[i-1]+read();
        sc[i]=sc[i-1]+read();
    }
    l=r=1;
    rep(i,1,n){
        ll j = binary_search(st[i]);
        f[i] = f[j]+st[i]*(sc[i]-sc[j])+s*(sc[n]-sc[j]);
        while(l<r && slope(q[r-1], q[r])>=slope(q[r-1], i)) --r;
        q[++r] = i;
    }
    cout<<f[n]<<"\n";

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}