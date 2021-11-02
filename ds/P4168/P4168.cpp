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
#define reps(i,a,b,c,d) for(int i=(a); i<=(d); i=(i==(b)?(c):i+1))
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

const int N = 40100;
const int SQN = 210;
struct Block {
    ll n, a[N], d[N], rnk[N], m;
    ll f[SQN][SQN];
    ll s[SQN][N];
    ll pos[N], l[SQN], r[SQN], t;
    ll cnt[N];

    void add(ll x) { a[++n] = x; }

    void init() {
        rep(i, 1, n) d[i] = a[i];
        sort(d + 1, d + 1 + n);
        m = unique(d + 1, d + 1 + n) - d - 1;
        rep(i, 1, n) {
            rnk[i] = lower_bound(d + 1, d + 1 + m, a[i]) - d;
        }

        t = sqrt(n);
        rep(i, 1, t) {
            l[i] = (i - 1) * t + 1;
            r[i] = i * t;
        }
        if (r[t] < n) t++, l[t] = r[t - 1] + 1, r[t] = n;
        rep(i, 1, t) {
            rep(j, l[i], r[i]) {
                pos[j] = i;
            }
        }

        rep(i, 1, t) {
            rep(j, 1, m) {
                s[i][j] = s[i - 1][j];
            }
            rep(j, l[i], r[i]) {
                s[i][rnk[j]]++;
            }
        }

        rep(i, 1, t) {
            rep(j, i, t) {
                ll mx = f[i][j-1];
                rep(k, l[j], r[j]) {
                    ll cv = s[j][rnk[k]] - s[i-1][rnk[k]];
                    ll mv = s[j][mx] - s[i-1][mx];
                    if (cv > mv || (cv == mv && rnk[k] < mx)) {
                        mx = rnk[k];
                    }
                }
                f[i][j] = mx;
            }
        }
    }

    ll query(ll x, ll y) {
        ll p = pos[x], q = pos[y];
        ll mx;
        if (q - p <= 1) {
            mx = 0;
            rep(i, x, y) {
                cnt[rnk[i]]++;
                if (cnt[rnk[i]] > cnt[mx] || (cnt[rnk[i]] == cnt[mx] && rnk[i] < mx)) 
                    mx = rnk[i];
            }
            rep(i, x, y) cnt[rnk[i]] = 0;
        } else {
            mx = f[p + 1][q - 1];
            reps(i, x, r[p], l[q], y) {
                cnt[rnk[i]]++;
            }
            reps(i, x, r[p], l[q], y) {
                ll cv = cnt[rnk[i]] + s[q - 1][rnk[i]] - s[p][rnk[i]];
                ll mv = cnt[mx] + s[q - 1][mx] - s[p][mx];
                if (cv > mv || (cv == mv && rnk[i] < mx)) {
                    mx = rnk[i];
                }
            }
            reps(i, x, r[p], l[q], y) cnt[rnk[i]] = 0;
        }
        return d[mx];
    }
};


int main() {
#ifdef D
    freopen("P4168.in", "r", stdin);
    clock_t TIMEA = clock();
#endif

    auto blk = new Block();
    ll n = read(), m = read();
    rep(i,1,n) blk->add(read());
    blk->init();
    ll x = 0;
    while (m--) {
        ll l = read(), r = read();
        l = ((l + x - 1) % n) + 1;
        r = ((r + x - 1) % n) + 1;
        if (l > r) swap(l, r);
        x = blk->query(l, r);
        printf("%lld\n", x);
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}