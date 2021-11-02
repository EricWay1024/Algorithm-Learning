#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<unordered_map>
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
const int N = 1e5+10;
int flag[N], prime[N], tot;
void init(int n) {
    rep(i,2,n) {
        if (!flag[i]) prime[++tot]=i;
        rep(j,1,tot) {
            if (prime[j] > n/i) break;
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

const ll M = 1000000007;
ll quick_pow(ll a, ll b) {
    ll ans=1; a%=M;
    for(; b; b>>=1, a=a*a%M) if (b & 1) ans = ans*a%M;
    return ans;
}
ll inv(ll a) {
    return quick_pow(a, M-2);
}
ll sigma(ll p, ll k) {
    return (quick_pow(p, k+1)-1)*inv(p-1)%M;
}

unordered_map<ll, int> mp;
void factor(ll k) {
    mp.clear();
    rep(i,1,tot) {
        if (prime[i] > sqrt(k)) break;
        if (k % prime[i] == 0) {
            int c = 0;
            while(k % prime[i] == 0) {
                c++;
                k /= prime[i];
            }
            mp[prime[i]] = c;
        }
    }
    if (k > 1) mp[k] = 1;
}
ll n, m;

void solve() {
    n=read(), m=read();
    factor(n);
    ll ans=1;
    for(auto pr: mp) {
        ll p; int k; tie(p, k) = pr;
        ans *= sigma(p, 1ll * k * m);
        ans %= M;
    }
    ans += M; ans %= M;
    cout << ans << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1054.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init(N-2);
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