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


const ll M = 1000000007ll;
const ll N = 2e6;
ll fact[N+19];
ll quick_pow(ll a, ll b, ll M) {
    ll ans=1;
    for(; b; b>>=1, a=a*a%M) if (b&1) ans=ans*a%M;
    return ans;
}
ll inv(ll a, ll M) {
    return quick_pow(a, M-2, M);
}

void init(int n) {
    fact[1] = fact[0] = 1;
    rep(i,1,n){
        fact[i] = fact[i-1] * i % M;
    }
}

ll binomial(ll n, ll k) {
    if (n < k || k < 0) return 0;
    return fact[n] * inv(fact[n-k]*fact[k]%M, M) % M;
}


void solve() {
    ll n=read();
    ll a1=read(); 
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    ll a2=read();
    ll u=a1+a2-1, d=a1;
    ll ans=binomial(u, d);
    rep(i,1,n-2){
        ll ai=read();
        tie(u, d) = make_tuple(u + ai, u+1);
        ans = ans * binomial(u, d) % M;
    }
    cout << ans << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1226.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init(1e6);
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