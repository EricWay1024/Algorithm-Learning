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

const int N = 20123;
int n, m;
vector< tuple<ll, ll, ll> > e;
vector< ll > grh[N];

int vis[N];
bool dfs(int u, int clr) {
    vis[u] = clr;
    for (auto v : grh[u]) {
        if (vis[v] == 0) {
            if (!dfs(v, 3 - clr)) return 0;
        } else if (vis[v] == clr) return 0;
    }
    return 1;
}

bool solve() {
    mmst(vis, 0);
    rep(u,1,n) if (vis[u] == 0) {
        if (!dfs(u, 1)) return 0;
    }
    return 1;
}


int main() {
#ifdef D
    freopen("LibreOJ-2594.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> n >> m;
    if (n == 2) {
        puts("0");
        return 0;
    }
    rep(i,1,m) {
        ll u, v, w;
        rin >> u >> v >> w;
        e.push_back(make_tuple(w, u, v));
    }
    sort(e.begin(), e.end());

    int l = 0, r = m - 1;
    int ans;
    while (l < r) {
        int mid = (l + r) / 2;
        rep(i,1,n) grh[i].clear();
        rep(i,mid+1,m-1) {
            auto [w, u, v] = e[i];
            grh[u].emplace_back(v);
            grh[v].emplace_back(u);
        }
        if (solve()) ans = get<0>(e[mid]), r = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}