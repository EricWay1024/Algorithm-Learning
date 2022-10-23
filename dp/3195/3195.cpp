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
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 51234
int n; ll L; ll c[N];
ll s[N], a[N], b[N];
ll q[N]; int l, r;
ll f[N];

#define square(x) ((x)*(x))
#define yy(j) (f[j]+b[j]*b[j])
#define xx(j) (b[j])
#define slope(j1,j2) (double)(yy(j2)-yy(j1))/(xx(j2)-xx(j1))

int main() {
#ifdef D
    freopen("3195.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(), L = read();
    b[0]=1+L;
    rep(i,1,n) {
        c[i]=read();
        s[i]=s[i-1]+c[i];
        a[i]=s[i]+i;
        b[i]=s[i]+1+L+i;
    }

    l = 1, r = 1;
    q[1] = 0;
    rep(i,1,n) {
        while(l<r && slope(q[l], q[l+1]) < (double)2*a[i]) l++;
        f[i] = f[q[l]]+square(a[i] - b[q[l]]);
        while(l<r && slope(q[r-1], i) < slope(q[r-1], q[r])) r--;
        q[++r] = i;
    }
    cout << f[n] << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}