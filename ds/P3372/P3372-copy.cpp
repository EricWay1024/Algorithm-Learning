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
struct Block {
    ll a[N], n, sum[N];
    ll l[N], r[N], add[N], pos[N], t;

    void insert(ll x) { a[++n] = x; }

    void init() {
        t = sqrt(n);
        rep(i, 1, t) {
            l[i] = (i - 1) * t + 1;
            r[i] = i * t;
        }
        if (r[t] < n) t++, l[t] = r[t - 1] + 1, r[t] = n;
        rep(i, 1, t) {
            rep(j, l[i], r[i]) {
                pos[j] = i;
                sum[i] += a[j];
            }
        }
    }

    void update(ll x, ll y, ll d) {
        ll p = pos[x], q = pos[y];
        if (p == q) {
            rep(i, x, y) a[i] += d, sum[p] += d;
        } else {
            rep(i, p + 1, q - 1) add[i] += d;
            rep(i, x, r[p]) a[i] += d, sum[p] += d;
            rep(i, l[q], y) a[i] += d, sum[q] += d;
        }
    }

    ll query(ll x, ll y) {
        ll p = pos[x], q = pos[y];
        ll ans = 0;
        if (p == q) {
            rep(i, x, y) ans += a[i] + add[p];
        } else {
            rep(i, p + 1, q - 1) ans += sum[i] + add[i] * (r[i] - l[i] + 1);
            rep(i, x, r[p]) ans += a[i] + add[p];
            rep(i, l[q], y) ans += a[i] + add[q];
        }
        return ans;
    }
};

int main() {
#ifdef D
    freopen("P3372.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    ll n = read(), m = read();
    auto blk = new Block();
    rep(_,1,n) { blk->insert(read()); }
    blk->init();
    rep(_,1,m) {
        ll op = read();
        if (op == 1) {
            ll x = read(), y = read(), k = read();
            blk->update(x, y, k);
        } else {
            ll x = read(), y = read();
            printf("%lld\n", blk->query(x, y));
        }
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}