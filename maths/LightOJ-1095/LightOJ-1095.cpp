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
const ll M = 1000000007;
ll fac[1024];
void init() {
    fac[0]=1;
    rep(i,1,1000){
        fac[i] = fac[i-1] * i % M;
    }
}
ll quick_pow(ll a, ll b, ll M) {
    ll ans=1;
    for(; b; b>>=1, a=a*a%M) if (b&1) ans=ans*a%M;
    return ans;
}
ll inv(ll a, ll M) {
    return quick_pow(a, M-2, M);
}
// ll binomial(ll n, ll k) {
//     if (k < 0 || n < k) return 0;
//     if (k == 0 || n == k) return 1;
//     return fac[n] * inv(fac[k]*fac[n-k]%M, M) % M;
// }
ll contribution(ll n, ll m, ll k, ll i) {
    return fac[m] * fac[n-i] % M * inv(fac[k] * fac[i-k] % M * fac[m-i] % M, M) % M;

}

void solve() {
    ll n=read(), m=read(), k=read();
    ll ans=0;
    rep(i,k,min(m, n)) {
        ll c = contribution(n, m, k, i);
        // logs(c);
        if ((k-i) & 1) ans -= c;
        else ans += c;
        ans %= M;
    }
    ans += M; ans %= M;
    cout << ans << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1095.in", "r", stdin);
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