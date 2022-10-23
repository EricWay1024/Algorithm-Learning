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
const int N = N5<<1;

int b[N];

struct seg {
    static const ll a0 = 0;

    ll ls, rs, ms;
    int l, r; seg *lc, *rc; 

    void init(int _l, int _r, seg *&pl) {
        l = _l, r = _r;
        if (l == r) { ls = rs = ms = 1; return; }
        int m = (l + r) >> 1;
        lc = ++pl; lc->init(l, m, pl);
        rc = ++pl; rc->init(m + 1, r, pl);
        up();
    } 

    void up() { 
        if (b[lc->r] == b[rc->l] && lc->ls == lc->r - lc->l + 1) ls = lc->ls + rc->ls;
        else ls = lc->ls;

        if (b[lc->r] == b[rc->l] && rc->rs == rc->r - rc->l + 1) rs = rc->rs + lc->rs;
        else rs = rc->rs;

        if (b[lc->r] == b[rc->l]) ms = max(max(lc->ms, rc->ms), lc->rs + rc->ls);
        else ms = max(lc->ms, rc->ms);
    }

    void update(int x) {
        if (x < l || x > r) { return; }
        if (x == l && x == r) { b[x] ^= 1; return;  }
        lc->update(x);
        rc->update(x);
        up();
    }

} tr[N * 2], *pl;

void init(int l, int r) {
    pl = tr;
    tr->init(l, r, pl);
}// 先输入in，然后init，然后用tr->update and tr->query



int main() {
#ifdef D
    freopen("P6492.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n, q; rin >> n >> q;
    rep(i,1,n) b[i] = (i & 1);

    init(1, n);

    while (q--) {
        int x; rin >> x;
        tr->update(x);
        cout << tr->ms << endl;
    }

#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}