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
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
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
const ll N = 1e6+10;
const ll A = 1e10;
vector<ll> pp;
const ll M = 100000007;
ll fac[N];
ll quick_pow(ll a, ll b, ll M) {
    ll ans=1;
    for(; b; b>>=1, a=a*a%M) if (b&1) ans=ans*a%M;
    return ans;
}
ll inv(ll a, ll M) {
    return quick_pow(a, M-2, M);
}

void init() {
    rep(x,2,N) {
        ll t = x;
        rep(y,2,N) {
            t *= x;
            if (t > A) break;
            pp.push_back(t);
        }
    }
    sort(pp.begin(), pp.end());
    pp.resize(distance(pp.begin(), unique(pp.begin(), pp.end())));

    fac[0]=1;
    rep(i,1,1e6){
        fac[i]=fac[i-1]*i%M;
    }
}

ll catlan(ll n) {
    if (!n) return 0;
    return fac[2*n] * inv(fac[n+1] * fac[n] % M, M) % M;
}

void solve() {
    ll a=read(), b=read();
    ll x2 = distance(pp.begin(), upper_bound(pp.begin(), pp.end(), b));
    ll x1 = distance(pp.begin(), lower_bound(pp.begin(), pp.end(), a));
    cout << catlan(x2-x1) << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1170.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init();
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}