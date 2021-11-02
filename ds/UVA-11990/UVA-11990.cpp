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

const int N = 200100;
struct MS {
    ll t[N], a[N], n;
    void add(ll x) { a[++n] = x; }
    ll merge_sort(ll l, ll r) {
        if (r <= l) return 0;
        ll mid = (l + r) >> 1;
        ll ans = merge_sort(l, mid) + merge_sort(mid + 1, r);
        ll p = l, q = mid + 1, s = l;
        while (s <= r) {
            if (p > mid || (q <= r && a[p] > a[q])) {
                t[s++] = a[q++];
                ans += mid - p + 1;
            } else {
                t[s++] = a[p++];
            }
        }
        rep(i, l, r) a[i] = t[i];
        return ans;
    }
    ll query() { return merge_sort(1, n); }
};


struct Block {
    ll a[N], b[N], pos[N], l[N], r[N], rr[N], t, n;
    ll rnk[N];
    void add(ll x) { a[++n] = x; rnk[x] = n; }
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
                b[j] = a[j];
            }
            sort(b + l[i], b + r[i] + 1);
        }
        rep(i, 1, t) rr[i] = r[i];
        // rep(i,1,n) {
        //     logs(i, pos[i], a[i], b[i]);
        // }
    }

    ll query_less(ll x, ll y, ll v) {
        ll p = pos[x], q = pos[y];
        // logs(x, y, p, q, v)
        ll ans = 0;
        if (p == q) {
            rep(i, x, y) ans += (a[i] != -1 && a[i] < v);
        } else {
            rep(i, x, r[p]) ans += (a[i] != -1 && a[i] < v);
            rep(i, l[q], y) ans += (a[i] != -1 && a[i] < v);
            rep(i, p + 1, q - 1) {
                ll temp = lower_bound(b + l[i], b + rr[i] + 1, v) - (b + l[i]);
                ans += temp;
            }
        }
        return ans;
    }
    
    ll query_greater(ll x, ll y, ll v) {
        ll p = pos[x], q = pos[y];
        // logs(x, y, p, q, v)
        ll ans = 0;
        if (p == q) {
            rep(i, x, y) ans += (a[i] != -1 && a[i] > v);
        } else {
            rep(i, x, r[p]) ans += (a[i] != -1 && a[i] > v);
            rep(i, l[q], y) ans += (a[i] != -1 && a[i] > v);
            rep(i, p + 1, q - 1) {
                ll temp = upper_bound(b + l[i], b + rr[i] + 1, v) - (b + l[i]);
                ans += (rr[i] - l[i] + 1) - temp;
            }
        }
        return ans;
    }

    ll query(ll x) {
        ll ans1 = query_greater(1, rnk[x], x);
        ll ans2 = query_less(rnk[x], n, x);
        // logs(ans1, ans2)
        return ans1 + ans2;
    }

    void remove(ll x) {
        ll p = pos[rnk[x]];
        ll temp = lower_bound(b + l[p], b + rr[p] + 1, x) - b;
        rep(i, temp, rr[p] - 1) { swap(b[i], b[i + 1]); }
        rr[p]--;
        a[rnk[x]] = -1; 
    }

    void debug() {
        rep(i,1,t) {
            printf("Block %d:", i);
            rep(j,l[i],r[i]) {
                cout << b[j] << ' ';
            }
            cout << endl;
        }
    }

};

int main() {
#ifdef D
    freopen("UVA-11990.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    ll n, m;
    while (~scanf("%lld%lld", &n, &m)) {
        auto ms = new MS();
        auto blk = new Block();
        rep(i, 1, n) {
            ll x = read();
            ms->add(x);
            blk->add(x);
        }
        ll ans = ms->query();
        blk->init();
        rep(_, 1, m) {
            printf("%lld\n", ans);
            // puts("---------");
            ll x = read();

            ans -= blk->query(x);
            blk->remove(x);
            // blk->debug();
        }
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}