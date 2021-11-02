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
    void dbg() {cout << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
    #define logs(x...) {cout << #x << " -> "; dbg(x);}
#else
    template<typename T, typename... Args> void logs(T t, Args... args) {};
#endif
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

struct Hsh {
    map<string, int> mp;
    int cnt;
    void init() { mp.clear(); cnt = 1; mp["Park"] = 1; }
    int get(string &s) {
        int &k = mp[s];
        return k ? k : (k = ++cnt);
    }
} hsh;

const int N = 41;
vector< pair<ll, ll> > grf[N];
vector<int> ccn[N];
int G[N][N];
int comp[N];
int use[N][N];
int didx[N];
int fa[N];
ll ans;

void clear_everything() {
    For(i, N) grf[i].clear(), ccn[i].clear();
    mmst(G, 0);
    mmst(comp, -1);
    mmst(use, 0);
    mmst(didx, -1);
    mmst(fa, 0);
    ans = 0;
    hsh.init();
}


struct DSU {
    int a[N];
    void init() { For(i,N) a[i] = i; }
    int fa(int x) { return a[x] == x ? x : a[x] = fa(a[x]); }
    int &operator[](int x) { return a[fa(x)]; }
} dsu;


struct Kruscal {
    vector< pair<ll, pair<ll, ll> > > e;
    int n;
    void init(int _n) { n = _n; e.clear(); dsu.init(); }
    void addedge(int w, int u, int v) { e.push_back(make_pair(w, make_pair(u, v))); }
    ll calc() {
        sort(e.begin(), e.end());
        int cnt = 0;
        ll ans = 0;
        For(i, e.size()) {
            ll w = e[i].first;
            ll u = e[i].second.first;
            ll v = e[i].second.second;
            if (dsu[u] == dsu[v]) continue;
            dsu[u] = dsu[v];
            use[u][v] = use[v][u] = 1;
            cnt++;
            ans += w;
            if (cnt == n - 1) break;
        }
        return ans;
    }
} kruscal;


void dfs(int u, int c) {
    comp[u] = c;
    for(auto e : grf[u]) {
        ll v = e.first;
        if (comp[v] == -1) dfs(v, c);
    }
}

void build_tree(int u, int n) {
    rep(v,1,n) if (use[u][v] && fa[u] != v) {
        fa[v] = u;
        build_tree(v, n);
    }
}

pair<ll, pair<ll, ll> > dist_on_tree(int x) {
    ll ans = 0;
    ll u, v;
    while (1) {
        if (G[x][fa[x]] > ans) {
            u = x, v = fa[x], ans = G[x][fa[x]];
        }
        if (fa[x]) x = fa[x];
        else break;
    }
    return make_pair(ans, make_pair(u, v));
}

bool try_optimize(int n) {
    mmst(fa, 0);
    build_tree(1, n);
    ll maxd = 0;
    ll u, v;
    ll ox;
    rep(x,2,n) if (!use[1][x] && G[1][x]) {
        auto p = dist_on_tree(x);
        ll w = p.first;
        ll z = G[1][x];
        if (w - z > maxd) {
            maxd = w - z;
            u = p.second.first;
            v = p.second.second;
            ox = x;
        }
    }
    if (maxd > 0) {
        use[1][ox] = use[ox][1] = 1;
        use[u][v] = use[v][u] = 0;
        ans -= maxd;
        return 1;
    }
    return 0;
}

void solve() {
    clear_everything();

    int m = read();
    rep(i,1,m) {
        string s, t;
        cin >> s >> t;
        int u = hsh.get(s);
        int v = hsh.get(t);
        ll w = read();
        grf[u].emplace_back(make_pair(v, w));
        grf[v].emplace_back(make_pair(u, w));
        G[u][v] = G[v][u] = w;
    }
    int S = read();
    int n = hsh.cnt;

    comp[1] = 0;
    int T = 0;
    rep(i,2,n) {
        if (comp[i] == -1) {
            dfs(i, ++T);
        }
    }

    rep(i,2,n) ccn[comp[i]].push_back(i);

    rep(i,1,T) {
        kruscal.init(ccn[i].size());
        for(int u: ccn[i]) {
            for(auto e: grf[u]) {
                ll v = e.first;
                ll w = e.second;
                
                if (comp[v] == comp[u] && v > u) {kruscal.addedge(w, u, v); }
                if (v == 1 && (didx[i] == -1 || w < G[didx[i]][1])) {
                    didx[i] = u;
                }
            }
        }
        ans += kruscal.calc();
    }

    rep(i,1,T) {
        use[1][didx[i]] = use[didx[i]][1] = 1;
        ans += G[1][didx[i]];
    }

    rep(i,1,S-T) if (!try_optimize(n)) break;
    cout << "Total miles driven: " << ans << endl;

}

int main() {
#ifdef D
    freopen("UVA-1537.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T = read();
    while (T--) { solve(); if (T > 0) cout << endl;}

#ifdef D
    clock_t TIMEB=clock();
    // printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}