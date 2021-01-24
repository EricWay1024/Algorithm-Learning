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
// #include<cstdint>
#include<climits>
#include<iomanip>
#include<complex>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
typedef complex<ll> formula;

void solve(int i_){
    int n=read();
    formula rhs = 0;
    rep(j, 1, n){
        ll p=read();
        if (p >= 0) {
            rhs += p;
        } else {
            rhs += formula(-p, 1);
        }
    }
    formula lhs = formula(0, n);
    ll nmr = lhs.real() - rhs.real();
    ll dmr = rhs.imag() - lhs.imag();
    if (dmr == 0) {
        printf("Case %d: inf\n", i_);
    } else {
        ll d = gcd(nmr, dmr);
        nmr /= d, dmr /= d;
        printf("Case %d: %lld/%lld\n", i_, nmr, dmr);
    }
}
int main() {
#ifdef D
    freopen("LightOJ-1027.in", "r", stdin);
    double TIMEA = clock();
#endif
    int t=read();
    rep(i,1,t){
        solve(i);
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}