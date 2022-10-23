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
const int N = 50010 << 1;

// without lazy, point update, interval query
struct segtree {
    struct seg {
        ll U(ll x, ll y) { return max(x, y); }
        static const ll a0 = 0;
        ll a;
        int l, r; seg *lc, *rc; 
        void init(int _l, int _r, seg *&pl, ll in[]) {
            l = _l, r = _r;
            if (l == r) { a = in ? in[l] : a0; return; }
            int m = (l + r) >> 1;
            lc = ++pl; lc->init(l, m, pl, in);
            rc = ++pl; rc->init(m + 1, r, pl, in);
            up();
        }
        void up() { a = U(lc->a, rc->a); }
        void update(int x, ll k) {
            if (x < l || x > r) { return; }
            if (x == l && x == r) { a += k; return;  }
            lc->update(x, k);
            rc->update(x, k);
            up();
        }
        ll query(int x, int y) {
            if (x > r || y < l) return a0;
            if (x <= l && y >= r) return a;
            return U(lc->query(x, y), rc->query(x, y));
        }
    } tr[N * 2], *pl;
    void init(int l, int r, ll in[] = nullptr) {
        pl = tr;
        tr->init(l, r, pl, in);
    }// 先输入in，然后init，然后用tr->update and tr->query
} sgtr;

int n, m, p;
vector<pii> v;
map<int, int> mp;
ll in[N];
int a[N];

int query(int x, int y) { // -1 maybe. 0 no. 1 yes
    if (!mp[x] || !mp[y]) return -1;
    int s = mp[x], t = mp[y];
    if (in[t] > in[s]) return 0;
    ll mx = sgtr.tr->query(s + 1, t - 1);
    // if (mx < )

}

int main() {
#ifdef D
    freopen("LibreOJ-2279.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> n;
    rep(i,1,n) {
        int x, y;
        rin >> x >> y;
        if (v.size() && v.back().first != x - 1) {
            v.emplace_back(x - 1, -1);
        }
        v.emplace_back(x, y);
    }

    p = 0;
    for (auto [x, y]: v) {
        in[++p] = y;
        if (y != -1) mp[x] = p;
        else a[p] = 1;
    }

    rep(i,1,p) {
        a[i] += a[i - 1];
    }

    sgtr.init(1, p, in);

    rin >> m;
    rep(i,1,m) {
        ll x, y; 
        rin >> x >> y;
    }



    // rep(i,1,p) {
    //     logs(i, in[i], a[i])
    // }

    // for (auto [x, y]: mp) {
    //     logs(x, y)
    // }

    // rep(i,1,p) {

    // }




#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}