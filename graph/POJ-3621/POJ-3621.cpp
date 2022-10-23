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
const int N = 1022;
ll n, m;
ll fun[N];
vector<pll> grh[N];
const db eps = 1e-3;
vector< pair<ll, db> > ngr[N];

struct SPFA {
    db d[N];
    queue<int> q;
    int v[N];
    int cnt[N];
    bool spfa() {
        rep(i,1,n) d[i] = 1e99, v[i] = 0, cnt[i] = 0;
        while (q.size()) q.pop();

        d[1] = 0; v[1] = 1; cnt[1] = 0; q.push(1);
        while (q.size()) {
            int x = q.front(); q.pop();
            v[x] = 0;
            For(j, ngr[x].size()) {
                ll y = ngr[x][j].first;
                db z = ngr[x][j].second;
                if (d[y] > d[x] + z) {
                    d[y] = d[x] + z;
                    cnt[y] = cnt[x] + 1;
                    if (cnt[y] >= n) return 1;
                    if (!v[y]) q.push(y), v[y] = 1;
                }
            }
        }
        return 0;
    }
}spfa;

int main() {
#ifdef D
    freopen("POJ-3621.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> n >> m;
    rep(i,1,n) rin >> fun[i];
    rep(i,1,m) {
        ll u, v, w;
        rin >> u >> v >> w;
        grh[u].push_back(make_pair(v, w));
    }
    db l = 0, r = 0;
    rep(i,1,n) r += fun[i];
    while (r - l > eps) {
        db mid = (l + r) / 2;
        rep(u,1,n) {
            ngr[u].clear();
            For(j, grh[u].size()) {
                ll v = grh[u][j].first;
                ll w = grh[u][j].second;
                ngr[u].push_back(make_pair(v, w * mid - fun[u]));
            }
        }
        if (spfa.spfa()) l = mid;
        else r = mid;
    }
    coutP(2) << l << endl;

    logs(l);

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}