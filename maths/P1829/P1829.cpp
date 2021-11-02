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

const ll MOD = 20101009ll;
const int N = 1e7+5;
short mu[N]; short flg[N]; int p[N], tot;
void getMu(int n) {
    mu[1] = 1;
    rep(i,2,n) {
        if (!flg[i]) mu[i] = -1, p[++tot]=i;
        for(int j=1; j<=tot && i*p[j]<=n; ++j) {
            flg[i * p[j]] = 1;
            if (i % p[j]) {
                mu[i * p[j]] = -mu[i];
            } else {
                mu[i * p[j]] = 0;
                break;
            }
        }
    }
}
int sum[N];

void init(int n) {
    getMu(n);

    rep(i,1,n) {
        sum[i] = sum[i-1];
        ll tmp = i%MOD; tmp *= tmp; tmp %= MOD; tmp *= mu[i];
        sum[i] += tmp;
        sum[i] %= MOD;
    }
}

ll f(ll x) {
    ll ans=x*(x+1); ans >>= 1; 
    return ans%MOD;
}

ll g(ll m, ll n, ll d) {
    m/=d, n/=d;
    ll ans=0;
    for(ll l=1, r; l<=m; l=r+1) {
        ll a=m/l, b=n/l;
        r = min(m/a, n/b); r = min(r, m);
        ans += (((f(a) * f(b)) % MOD) * (((ll)sum[r] - (ll)sum[l-1]) % MOD)) % MOD;
        ans %= MOD;
    }
    return ans;
}

ll h(ll m, ll n) {
    if (m > n) swap(m, n);
    ll ans=0;
    for(ll l=1, r; l<=m; l=r+1) {
        ll a=m/l, b=n/l;
        r = min(m/a, n/b); r = min(r, m);
        ll tmp = (l + r) * (r - l + 1); tmp >>= 1; tmp %= MOD;
        ans += (g(m, n, l) * tmp) % MOD;
        ans %= MOD;
    }
    ans += MOD; ans %= MOD;
    return ans;
}


int main() {
#ifdef D
    freopen("P1829.in", "r", stdin);
    clock_t TIMEA = clock();
#endif 
    init(N-2);
    ll m=read(), n=read();
    printf("%lld\n", h(m, n));

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}