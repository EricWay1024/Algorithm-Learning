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

const int N = 1e5 + 100;
struct seg {
    ll U(ll x, ll y) { return x + y; }
    static const ll a0 = 0;
    ll a, z; bool state;
    int l, r; seg *lc, *rc;
    void toz(ll x) { z += x; state = 1; }
    void toa() { a += z * (r - l + 1); z = 0; state = 0;}
    void init(int _l, int _r, seg *&pl) {
        l = _l, r = _r; state = 0; z = 0;
        if (l == r) {a = a0; return ; }
        int m = (l + r) >> 1;
        lc = ++pl; lc->init(l, m, pl);
        rc = ++pl; rc->init(m+1, r, pl);
        up();
    }
    void build(ll in[]) {
        if (l == r) {a = in[l]; return; }
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
}

ll in[N];

int main() {
#ifdef D
    freopen("P3372.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n, m; cin >> n >> m;
    rep(i,1,n) in[i] = read();
    init(1, n, in);
    rep(_,1,m) {
        int o = read();
        int x = read(), y = read();
        if (o == 1) {
            int k = read();
            tr->update(x, y, k);
        } else {
            cout << (tr->query(x, y)) << endl;
        }
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}