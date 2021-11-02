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
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

const int N = 50000 + 100;

struct Query {
    int l, r, id;
} q[N];

struct Ans {
    ll de, nu;
} ans[N];

ll c[N];
ll n, m, B;

bool cmp(const Query &a, const Query &b) {
    return a.l/B == b.l/B ? (((a.l/B) & 1) ? a.r > b.r : a.r < b.r) : a.l/B < b.l/B;
}

ll nu, de, len, cnt[N];
void add(int x) {
    nu += cnt[x]; cnt[x]++;
    de += len; len++;
}
void del(int x) {
    cnt[x]--; nu -= cnt[x];
    len--; de -= len;
}

void solve() {
    n = read(), m = read();
    B = max(1.0, (db)n / sqrt(m));

    rep(i, 1, n) c[i] = read();
    rep(i, 1, m) {
        q[i].l = read(); q[i].r = read();
        q[i].id = i; 
    }
    sort(q + 1, q + 1 + m, cmp);

    ll l = 1, r = 0;
    rep(i, 1, m) {
        ll ql = q[i].l, qr = q[i].r;
        if (ql == qr) {
            ans[q[i].id].de = 1;
            ans[q[i].id].nu = 0;
            continue;
        } 
        while (l > ql) add(c[--l]);
        while (r < qr) add(c[++r]);
        while (l < ql) del(c[l++]);
        while (r > qr) del(c[r--]);
        ll g = gcd(de, nu);
        ans[q[i].id].de = de / g;
        ans[q[i].id].nu = nu / g;
    }

    rep(i, 1, m) {
        printf("%lld/%lld\n", ans[i].nu, ans[i].de);
    }
}


int main() {
#ifdef D
    freopen("P1494.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    solve();

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}