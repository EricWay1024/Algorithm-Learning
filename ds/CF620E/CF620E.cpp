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
const int N2 = 112; const int N3 = 1123; const int N4 = 11234; const int N5 = 112345; const int N6 = 1123456; const int N7 = 11234567;


const int N = 4e5 + 100;
vector<int> son[N];
int fa[N];
int n, m;
ll c[N];
int dfn[N];
int rnk[N];
int sz[N];
int ed[N];
int tot;

struct seg {
    ll U(ll x, ll y) { return x | y; }
    static const ll a0 = 0;
    void toz(ll x) { z = x; }
    void toa() { a = z, z = 0; }
    ll a, z;
    int l, r; seg *lc, *rc; 
    void init(int _l, int _r, seg *&pl) {
        l = _l, r = _r; z = 0;
        if (l == r) { a = c[rnk[l]]; return; }
        int m = (l + r) >> 1;
        lc = ++pl; lc->init(l, m, pl);
        rc = ++pl; rc->init(m + 1, r, pl);
        up();
    }
    void up() { a = U(lc->a, rc->a); }
    void down() {
        if (!z) return;
        if (l < r) { lc->toz(z); rc->toz(z); }
        toa();
    }
    void update(int x, int y, ll k) {
        if (x > r || y < l) { down(); return; }
        if (x <= l && y >= r) { toz(k); down(); return; }
        down();
        lc->update(x, y, k);
        rc->update(x, y, k);
        up();
    }
    ll query(int x, int y) {
        if (x > r || y < l) return a0;
        down();
        if (x <= l && y >= r) return a;
        return U(lc->query(x, y), rc->query(x, y));
    }
} tr[N * 2], *pl;
void init(int l, int r) {
    pl = tr;
    tr->init(l, r, pl);
}// 先输入in，然后init，然后用tr->update and tr->query


void dfs(int u) {
    sz[u] = 1;
    dfn[u] = ++tot;
    rnk[dfn[u]] = u;

    for (int v: son[u]) if (v != fa[u]) {
        fa[v] = u;
        dfs(v);
        sz[u] += sz[v];
    }
    // ed[u] = tot;
}



int main() {
#ifdef D
    freopen("CF620E.in", "r", stdin);
    clock_t TIMEA = clock();
#endif  
    rin >> n >> m;
    rep(i,1,n) {
        ll a; rin >> a;
        c[i] = (1ll << a);
    }

    rep(i,1,n-1) {
        ll u, v; rin >> u >> v;
        son[u].push_back(v);
        son[v].push_back(u);
    }

    dfs(1);

    init(1, n);

    rep(i,1,m) {
        int o; rin >> o;
        int u; rin >> u;
        if (o == 1) {
            ll a; rin >> a;
            tr->update(dfn[u], dfn[u] + sz[u] - 1, (1ll << a));
        } else {
            ll res = tr->query(dfn[u], dfn[u] + sz[u] - 1);
            ll cnt = 0;
            while (res) { cnt += (res % 2); res /= 2;}
            cout << cnt << endl;
        }
    }

#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}