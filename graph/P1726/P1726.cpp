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
    #define logs(x...) {}
#endif
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll; typedef long double ld; typedef double db;
typedef pair<ll,ll> pll; typedef pair<int,int> pii; typedef vector<ll> vll; typedef vector<int> vint;
template <typename T> vector<T>& operator<< (vector<T> &v, T &x) { v.emplace_back(x); return v; }
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}


const int N = 5e3 + 617;

vint grh[N];
ll n, m;
ll scctot;
set<int> sccpts[N];

struct Tarjan {
    int dfn[N], low[N], timer, vis[N];
    stack<int> stk;

    void dfs(int u) {
        dfn[u] = low[u] = ++timer;
        stk.push(u);
        vis[u] = 1;
        for (auto v : grh[u]) {
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
                sccpts[scctot].insert(v);
                vis[v] = 2;
                if (v == u) break;
            }
        }
    }
}tarjan;


int main() {
#ifdef D
    freopen("P1726.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    cin >> n >> m;
    rep(_,1,m) {
        int u, v, o; cin >> u >> v >> o;
        grh[u] << v;
        if (o == 2) grh[v] << u;
    }

    rep(i,1,n) if(tarjan.dfn[i] == 0) tarjan.dfs(i);
    logs(scctot);

    int mx = 1;
    rep(i,2,scctot) {
        if ((sccpts[i].size() > sccpts[mx].size())
            || (sccpts[i].size() == sccpts[mx].size() && *sccpts[i].begin() < *sccpts[mx].begin())
        ) {
            mx = i;
        }
    }

    cout << sccpts[mx].size() << endl;
    for(auto u: sccpts[mx]) {
        cout << u << ' ';
    }
    cout << endl;

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}