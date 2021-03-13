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
// #include<cstdll>
#include<climits>
#include<iomanip>
using namespace std;
#define rep(i,from,to) for(ll i=(ll)(from);i<=(ll)(to);++i)
#define rev(i,from,to) for(ll i=(ll)(from);i>=(ll)(to);--i)
#define For(i,to) for(ll i=0;i<(ll)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
void init() {

}

void gcd(ll a, ll b, ll& d, ll &x, ll &y) {
    if (!b) { d=a; x=1; y=0; }
    else { gcd(b, a%b, d, y, x); y-=x*(a/b); }
}

bool linear(ll a, ll b, ll c, ll &x0, ll &dx, ll &y0, ll &dy) {
    ll d, x, y;
    gcd(a, b, d, x, y);
    if (c % d != 0) return 0;
    x0 = c / d * x;
    y0 = c / d * y;
    dx = -b / d;
    dy = a / d;
    return 1;
}

void adjust_inequation(ll &dx, ll &x0, ll &x1, ll &x2) {
    if (dx < 0) {
        dx = -dx, x0 = -x0;
        tie(x1, x2) = make_tuple(-x2, -x1);
    }
}

ll inequation(ll m, ll n, ll l) {
    if (!l) {
        return floor((ld)n/m);
    } else {
        return ceil((ld)n/m);
    }
}

ll solve_univariable(ll a, ll c, ll x1, ll x2) {
    if (c % a) return 0;
    ll x = -c / a;
    return x >= x1 && x <= x2;
} 


ll solve() {
    ll A=read(), B=read(), C=read(), 
    x1=read(), x2=read(),
    y1=read(), y2=read();
    ll xlen = (x2 - x1 + 1); 
    ll ylen = (y2 - y1 + 1);

    if (A == 0 && B == 0) {
        return C ? 0 : xlen * ylen;
    } else if (A == 0) {
        return xlen * solve_univariable(B, C, y1, y2);
    } else if (B == 0) {
        return ylen * solve_univariable(A, C, x1, x2);
    }

    ll x0, dx, y0, dy;
    bool ret = linear(A, B, -C, x0, dx, y0, dy);
    if (!ret) { return 0; } 

    adjust_inequation(dx, x0, x1, x2);
    adjust_inequation(dy, y0, y1, y2);
    ll min1 = inequation(dx, x1-x0, 1);
    ll min2 = inequation(dy, y1-y0, 1);
    ll max1 = inequation(dx, x2-x0, 0);
    ll max2 = inequation(dy, y2-y0, 0);
    ll ans = max(0ll, min(max1, max2) - max(min1, min2) + 1);
    return ans;
}

int main() {
#ifdef D
    freopen("LightOJ-1306.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init();
    ll T=read();
    rep(cas,1,T){
        printCase(cas);
        cout << solve() << endl;
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}