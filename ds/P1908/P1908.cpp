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

int n;
vector<pii> b;
vector<int> temp;

// vector<vector<int>> c;


const int N = 5 * N5;
struct seg {
    ll U(ll x, ll y) { return x + y; }
    static const ll a0 = 0;
    void toz(ll x) { z += x, state = 1; }
    void toa() { a += z * (r - l + 1), z = 0, state = 0; }
    ll a, z; bool state;
    int l, r; seg *lc, *rc; 
    void init(int _l, int _r, seg *&pl) {
        l = _l, r = _r; state = 0; z = 0;
        if (l == r) { a = a0; return; }
        int m = (l + r) >> 1;
        lc = ++pl; lc->init(l, m, pl);
        rc = ++pl; rc->init(m + 1, r, pl);
        up();
    }
    void build(ll in[]) {
        if (l == r) { a = in[l]; return; }
        lc->build(in); rc->build(in);
        up();
    } 
    void up() { a = U(lc->a, rc->a); }
    void down() {
        if (!state) return;
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
void init(int l, int r, ll in[] = nullptr) {
    pl = tr;
    tr->init(l, r, pl);
    if (in) tr->build(in);
}// 先输入in，然后init，然后用tr->update and tr->query


int main() {
#ifdef D
    freopen("P1908.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> n;
    rep(i,1,n) {
        int t;
        rin >> t;
        b.emplace_back(t, i);
    }

    sort(b.begin(), b.end());

    init(1, n);
    ll ans = 0;

    for (int j = 0; j < b.size(); j++) {
        auto [t, i] = b[j];
        temp.clear();
        temp.push_back(i);
        while (j + 1 < b.size() && b[j + 1].first == t) {
            j++;
            temp.push_back(b[j].second);
        }
        for (auto &i : temp) {
            ans += tr->query(i + 1, n);
        }
        for (auto &i : temp) {
            tr->update(i, i, 1);
        }
    }

    // for (auto &v : c) {
    //     for (auto &i : v) {
    //     }

    //     for (auto &i : v) {
    //     }
    // }

    cout << ans << endl;
    // for (auto &v : c) {
    //     logs(0)
    //     for (auto &u : v) {
    //         logs(u)
    //     }
    // }

    // init(1, n);







    


#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}