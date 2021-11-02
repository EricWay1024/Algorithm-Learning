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
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
#ifdef D
    void dbg() {cout << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
    #define logs(x...) {cout << #x << " -> "; dbg(x);}
#else
    // template<typename T, typename... Args> void logs(T t, Args... args) {};
#endif
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


const int N = 100;
struct DSU {
    int a[N];
    void init(int n) { rep(i,1,n) a[i] = i; }
    int fa(int x) { return a[x] == x ? x : a[x] = fa(a[x]); }
    int &operator[](int x) { return a[fa(x)]; }
} dsu;

ll n; 
vector< pair<ll, pair<ll, ll> > > e;
void solve() {
    e.clear();
    For(_, n-1) {
        char u; cin >> u;
        int k; cin >> k;
        For(i, k) {
            char v; cin >> v;
            ll w; cin >> w;
            // logs(u, k, v, w);
            e.push_back(make_pair(w, make_pair(u - 'A' + 1, v - 'A' + 1)));
        }
    }
    sort(e.begin(), e.end());

    dsu.init(n);
    int cnt = 0;
    ll ans = 0;
    For(i, e.size()) {
        ll w = e[i].first;
        ll u = e[i].second.first;
        ll v = e[i].second.second;
        if (dsu[u] == dsu[v]) continue;
        dsu[u] = dsu[v];
        cnt++;
        ans += w;
        // logs(ans, w);
        if (cnt == n - 1) break;
    }
    cout << ans << endl;
}

int main() {
#ifdef D
    freopen("POJ-1251.in", "r", stdin);
    clock_t TIMEA = clock();
#endif

    while ((n = read())) {
        // logs(n)
        solve();
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}