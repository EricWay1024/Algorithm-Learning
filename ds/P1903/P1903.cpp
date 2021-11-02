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
void readch(char &o) {
    do o = getchar();
    while (!isalpha(o));
}

const int N = 133333 + 100;
const int X = 1e6 + 100;
struct Query {
    int l, r, t, id;
} q[N]; int qcnt;
ll B;
bool cmp(const Query &a, const Query &b) {
    return a.l/B == b.l/B ? (a.r/B == b.r/B ? a.t < b.t : a.r < b.r) : a.l < b.l;
}
struct Modify {
    ll p, x;
} c[N]; int ccnt;

ll res[N]; ll col[N]; 
ll cnt[X]; ll ans; 
void del(int x) {
    cnt[x]--;
    if (cnt[x] == 0) ans--;
}
void add(int x) {
    if (cnt[x] == 0) ans++;
    cnt[x]++;
}
void modify(int i, int t) {
    if (c[t].p >= q[i].l && c[t].p <= q[i].r) {
        del(col[c[t].p]);
        add(c[t].x);
    }
    swap(col[c[t].p], c[t].x);
}

void solve() {
    ll n = read(), m = read();
    B = max(1.0, pow(n, 0.667));
    rep(i, 1, n) col[i] = read();
    rep(i, 1, m) {
        char o; readch(o);
        if ('Q' == o) {
            q[++qcnt].l = read();
            q[qcnt].r = read();
            q[qcnt].id = qcnt;
            q[qcnt].t = ccnt;
        } else {
            c[++ccnt].p = read();
            c[ccnt].x = read();
        }
    }

    sort(q + 1, q + 1 + qcnt, cmp);

    ll l = 1, r = 0, t = 0;
    ans = 0;
    rep(i, 1, qcnt) {
        if (q[i].l == q[i].r) { res[q[i].id] = 1; continue; }
        while (l > q[i].l) add(col[--l]);
        while (r < q[i].r) add(col[++r]);
        while (l < q[i].l) del(col[l++]);
        while (r > q[i].r) del(col[r--]);
        while (t < q[i].t) modify(i, ++t);
        while (t > q[i].t) modify(i, t--);
        res[q[i].id] = ans;
    }

    rep(i, 1, qcnt) {
        printf("%lld\n", res[i]);
    }
}


int main() {
#ifdef D
    freopen("P1903.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    solve();

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}