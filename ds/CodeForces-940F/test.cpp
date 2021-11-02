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

#define int long long
const int N = 100010;
const int N2 = N * 2;
struct Query {
    int l, r, t, id;
} q[N]; int qcnt;

struct Change {
    int p, x;
} c[N]; int ccnt;

int a[N];
int res[N];
int cnt[N2], cnx[N];

void add(int x) {
    cnx[cnt[x]]--;
    cnt[x]++;
    cnx[cnt[x]]++;
}

void del(int x) {
    cnx[cnt[x]]--;
    cnt[x]--;
    cnx[cnt[x]]++;
}

void modify(int i, int t) {
    if (c[t].p >= q[i].l && c[t].p <= q[i].r) {
        del(a[c[t].p]);
        add(c[t].x);
    }
    swap(a[c[t].p], c[t].x);
}

// ll B;
const int B = 2100;
bool cmp(const Query &a, const Query &b) {
    return a.l/B == b.l/B ? (a.r/B == b.r/B ? a.t < b.t : a.r < b.r) : a.l < b.l;
}


struct Des {
    int b[N2], n; 
    void add(int x) { b[n++] = x; }
    void init() {
        sort(b, b + n);
        n = unique(b, b + n) - b; 
    } 

    int get(int x) {
        return lower_bound(b, b + n, x) - b + 1;
    }
} de;

void solve() {
    int n = read(), m = read();
    rep(i, 1, n) a[i] = read(), de.add(a[i]);

    rep(i, 1, m) {
        int o = read();
        if (o == 1) {
            qcnt++;
            q[qcnt].l = read();
            q[qcnt].r = read();
            q[qcnt].id = qcnt;
            q[qcnt].t = ccnt;
        } else {
            ccnt++;
            c[ccnt].p = read();
            c[ccnt].x = read();
            de.add(c[ccnt].x);
        }
    }
    de.init();

    rep(i, 1, n) {
        a[i] = de.get(a[i]);
    }
    rep(i, 1, ccnt) {
        c[i].x = de.get(c[i].x);
    }

    // B = max(2.0, pow(n, 2.0 / 3));
    sort(q + 1, q + 1 + qcnt, cmp);

    int l = 1, r = 0, t = 0;
    rep(i, 1, qcnt) {
        int &ans = res[q[i].id];
        if (q[i].l == q[i].r) { ans = 2; continue; }
        while (l > q[i].l) add(a[--l]);
        while (r < q[i].r) add(a[++r]);
        while (l < q[i].l) del(a[l++]);
        while (r > q[i].r) del(a[r--]);
        while (t < q[i].t) modify(i, ++t);
        while (t > q[i].t) modify(i, t--);

        for (ans = 1; cnx[ans] > 0; ++ans);
    }

    rep(i, 1, qcnt) {
        printf("%d\n", res[i]);
    }
}

signed main() {
#ifdef D
    freopen("CodeForces-940F.in", "r", stdin);
    clock_t TIMEA = clock();
#endif

    solve();
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}