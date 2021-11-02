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
ll fac[100];
ll quick_pow(ll a, ll b) {
    ll ans=1; a%=M;
    for(; b; b>>=1, a=a*a%M) if(b&1) ans=a*ans%M;
    return ans;
}
ll inv(ll a){
    return quick_pow(a, M-2);
}
ll binomial(ll n, ll k){
    if (k > n || k < 0) return 0;
    if (k == n || k == 0) return 1;
    return fac[n] * inv(fac[k] * fac[n-k] % M) % M;
}
void init() {
    fac[0]=1;
    rep(i,1,50){
        fac[i]=fac[i-1]*i%M;
    }
}

void solve() {
    ll a=read(), b=read(), n=read();
    if (a == 0 && b == 0) {
        cout << n << endl;
        return;
    }
    ll c1=(a+1)*(b+1)/2; ll c2=(a+1)*(b+1)-c1;
    ll ans=0;
    rep(k,1,n-1) {
        ans += binomial(n, k) * quick_pow(k, c1) % M * quick_pow(n-k, c2) % M;
        ans %= M;
    }
    cout << ans << endl;
    

}

int main() {
#ifdef D
    freopen("LightOJ-1246.in", "r", stdin);
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