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
// #include<unordered_map>
#include<utility>
#include<vector>
#include<numeric>
#include<functional>
#include<climits>
#include<iomanip>
#include<random>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
#ifdef D
    void dbg() {cerr << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cerr << a << ' '; dbg(x...);}
    #define logs(x...) {cerr << #x << " -> "; dbg(x);}
#else
    #define logs(...) {}
#endif
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll; typedef long double ld; typedef double db;
typedef pair<ll,ll> pll; typedef pair<int,int> pii; typedef vector<ll> vll; typedef vector<int> vint;
template <typename T> vector<T>& operator<< (vector<T> &v, T &x) { v.emplace_back(x); return v; }
struct MyIn { 
    template <typename T> MyIn& operator>> (T &x) { x=0;bool s=0;char c=getchar();while(c>'9'||c<'0'){if(c=='-')s=1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}if(s)x=-x;return (*this); } 
} rin;

ll a[4], d;
ll b[4];

ll calc(ll m) {
    rep(i,1,3) b[i] = a[i];
    ll e = d;
    rep(i,1,3) if (b[i] < m) e -= m - b[i], b[i] = m;
    if (e < 0) return 0;
    sort(b + 1, b + 4);
    b[3] += e;
    ll res = b[1] * 7;
    rep(i,1,3) res += b[i] * b[i];
    return res;
}

ll get_random(ll x, ll y) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(x, y);
    return dist(rng);
}

ll sa() {
    ll l = a[1]; ll r = (a[1] + a[2] + a[3] + d) / 3;
    db t = 1e9;
    db t_min = 0.1;
    db q = 0.9966;
    ll now = l;
    ll ans = calc(now);
    while (t > t_min) {
        ll nxt = get_random(max(l, now - (ll)(t)), min(r, now + (ll)(t)));
        ll nans = calc(nxt);
        ll delta = ans - nans;
        if (delta < 0) {
            ans = nans;
            now = nxt;
        } else if (exp(-delta/t) * 1e9 > get_random(1, 1e9)) {
            now = nxt;
        }
        t *= q;
    }
    return ans;
}

int main() {
#ifdef D
    freopen("highscore2.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T; rin >> T;

    while (T--){
        rep(i,1,3) rin >> a[i];
        rin >> d;
        sort(a + 1, a + 4);
        ll l = a[1]; ll r = (a[1] + a[2] + a[3] + d) / 3;
        
        ll ans = 0;
        rep(i,l,min(r, l+10000)) {
            ans = max(ans, calc(i));
        }

        // ll ans = sa();
        cout << ans << endl;

    }

#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}