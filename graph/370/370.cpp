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

const int N = 1e5 + 199;
ll n, m;
vector<pii> grh[N];

ll scctot;
int belong[N];
int sccsz[N];

struct Tarjan {
    int dfn[N], low[N], timer, vis[N];
    stack<int> stk;

    void dfs(int u) {
        dfn[u] = low[u] = ++timer;
        stk.push(u);
        vis[u] = 1;
        for (auto p : grh[u]) {
            auto v = p.first;
            if (vis[v] == 0) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (vis[v] == 1) {
                low[u] = min(low[u], dfn[v]);
            }
        } 
        if (dfn[u] == low[u]) {
            scctot++;
            while (1) {
                int v = stk.top();
                stk.pop();
                belong[v] = scctot;
                sccsz[scctot]++;
                vis[v] = 2;
                if (v == u) break;
            }
        }
    }
}tarjan;

vector<pii> ng[N];
ll indeg[N];
queue<int> q;
vector<int> topo;
ll d[N];

ll solve() {
    tarjan.dfs(n);
    rep(u,1,n) {
        for(auto p: grh[u]) {
            int v = p.first;
            int w = p.second;
            if (belong[v] == belong[u]) {
                if (w == 1) return -1;
            } else {
                ng[belong[u]].emplace_back(belong[v], w);
                indeg[belong[v]]++;
            }
        }
    }

    rep(u,1,scctot) if (!indeg[u]) q.push(u);
    while(q.size()) {
        int u = q.front(); q.pop();
        topo << u;
        for(auto p: ng[u]) {
            int v = p.first;
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    d[n] = 0;
    for(auto u: topo) {
        for(auto p: ng[u]) {
            int v = p.first;
            int w = p.second;
            d[v] = max(d[v], d[u] + w);
        }
    }

    ll ans = 0;
    rep(u,1,scctot) ans += d[u] * sccsz[u];
    return ans;
}

int main() {
#ifdef D
    freopen("370.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> n >> m;
    rep(i,1,m) {
        ll t, a, b;
        rin >> t >> a >> b;
        if (t == 4 || t == 5) t -= 2, swap(a, b); 
        if (t == 1) {
            grh[a].emplace_back(b, 0);
            grh[b].emplace_back(a, 0);
        } else if (t == 2) {
            grh[a].emplace_back(b, 1);
        } else if (t == 3) {
            grh[b].emplace_back(a, 0);
        }
    }

    rep(i,1,n) {
        grh[n + 1].emplace_back(i, 1);
    }
    n++;

    cout << solve() << endl;

#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}