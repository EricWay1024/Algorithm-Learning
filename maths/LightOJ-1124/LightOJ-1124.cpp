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
const ll M = 100000007ll;
const ll N = 1e6+232;
const int K = 20;
ll quick_pow(ll a, ll b) {
    ll ans=1; a %= M;
    for(; b; b>>=1, a=a*a%M) if (b&1) ans=ans*a%M;
    return ans;
}
ll inv(ll a) {
    return quick_pow(a, M-2ll);
}
ll fac[N];
void init(int n) {
    fac[0]=1;
    rep(i,1,n){
        fac[i] = fac[i-1] * i % M;
    }
}

ll binomial(ll a, ll b) {
    if (b < 0 || b > a) return 0;
    ll d = fac[b] * fac[a-b] % M;
    return fac[a] * inv(d) % M;
}

ll k, n;
int b[K];

ll contribution(ll s) {
    ll sign = 1;
    ll up = n+k-1;
    For(i, k) if (s&(1<<i)) {
        sign = -sign;
        up -= (b[i]+1);
    }
    return sign * binomial(up, k-1);
}

ll solve() {
    k=read(), n=read();
    For(i,k) {
        int l=read(), r=read();
        n-=l; b[i]=r-l;
    }
    if (n < 0) {
        return 0;
    }
    ll ans=0;
    For(s, 1<<k) {
        ans += contribution(s);
        ans %= M;
    }
    ans += M; ans %= M; // good practice to always check
    return ans;
}

int main() {
#ifdef D
    freopen("LightOJ-1124.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init(N-10);
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        cout << solve() << '\n';
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}