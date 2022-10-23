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

const int N = 2e3 + 10;
vector<int> grh[N];
int n, m;


ll scctot;
int belong[N];
struct Tarjan {
    int dfn[N], low[N], timer, vis[N];
    stack<int> stk;

    void dfs(int u) {
        dfn[u] = low[u] = ++timer;
        stk.push(u);
        vis[u] = 1;
        For(j, grh[u].size()) {
            int v = grh[u][j];
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
                vis[v] = 2;
                if (v == u) break;
            }
        }
    }
}tarjan;

bool solve() {
    rep(i,1,2*n) if (!tarjan.dfn[i]) tarjan.dfs(i);

    rep(i,1,n) {
        if (belong[i] == belong[i + n]) return 0;
    }
    return 1;
}

int main() {
#ifdef D
    freopen("POJ-3678.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> n >> m;
    rep(i,1,m) {
        int a, b, c;
        rin >> a >> b >> c;
        a++, b++;
        string s;
        cin >> s;
        if (s == "AND") {
            if (c == 0) {
                grh[a + n].push_back(b);
                grh[b + n].push_back(a);
            } else {
                grh[a].push_back(a + n);
                grh[b].push_back(b + n);
            }
        } else if (s == "OR") {
            if (c == 1) {
                grh[a].push_back(b + n);
                grh[b].push_back(a + n);
            } else {
                grh[a + n].push_back(a);
                grh[b + n].push_back(b);
            }
        } else {
            if (c == 0) {
                grh[a].push_back(b);
                grh[b].push_back(a);
                grh[a + n].push_back(b + n);
                grh[b + n].push_back(a + n);
            } else {
                grh[a].push_back(b + n);
                grh[b].push_back(a + n);
                grh[a + n].push_back(b);
                grh[b + n].push_back(a);
            }
        }
    }

    if (solve()) puts("YES");
    else puts("NO");


#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}