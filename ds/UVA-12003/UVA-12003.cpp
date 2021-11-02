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
const int N = 300100;

struct Block {
    ll a[N], b[N], n, t, pos[N], l[N], r[N];

    void add(ll x) { a[++n] = x; }
    void init() {
        t = sqrt(n);
        rep(i, 1, t) {
            l[i] = (i - 1) * t + 1;
            r[i] = i * t;
        }
        if (r[t] < n) t++, l[t] = r[t - 1] + 1, r[t] = n;

        rep(i, 1, t) {
            rep(j, l[i], r[i]) {
                b[j] = a[j];
                pos[j] = i;
            }
            sort(b + l[i], b + r[i] + 1);
        }
    }
    ll query(ll x, ll y, ll v) {
        ll p = pos[x], q = pos[y];
        ll ans = 0;
        if (p == q) {
            rep(i, x, y) ans += (a[i] < v);
        } else {
            rep(i, x, r[p]) ans += (a[i] < v);
            rep(i, l[q], y) ans += (a[i] < v);
            rep(i, p + 1, q - 1) {
                ll temp = lower_bound(b + l[i], b + r[i] + 1, v) - (b + l[i]);
                ans += temp;
            }
        }
        return ans;
    } 

    void update(ll x, ll d) {
        ll p = pos[x];
        ll temp = lower_bound(b + l[p], b + r[p] + 1, a[x]) - b;
        b[temp] = d;
        if (d > a[x]) {
            rep(i, temp + 1, r[p]) {
                if (b[i - 1] > b[i]) swap(b[i - 1], b[i]);
                else break;
            }
        } else {
            rev(i, temp, l[p] + 1) {
                if (b[i - 1] > b[i]) swap(b[i - 1], b[i]);
                else break;
            }
        }
        a[x] = d;
    }

    void output() {
        rep(i, 1, n) { printf("%lld\n", a[i]); }
    }

    // void debug() {
    //     rep(i, 1, t) {
    //         cout << "Block " << i << ": ";
    //         rep(j, l[i], r[i]) {
    //             cout << b[j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

};


int main() {
#ifdef D
    freopen("UVA-12003.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    ll n = read(), m = read(), u = read();
    auto blk = new Block();
    rep(_, 1, n) blk->add(read());
    blk->init();
    rep(_, 1, m) {
        ll L = read(), R = read(), v = read(), p = read();
        ll k = blk->query(L, R, v);
        blk->update(p, u * k / (R - L + 1));
    }
    blk->output();

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}