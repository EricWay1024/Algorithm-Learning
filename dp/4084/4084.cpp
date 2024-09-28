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
const int N2 = 112; const int N3 = 1123; const int N4 = 11234; const int N5 = 112345; const int N6 = 1123456; const int N7 = 11234567;

ll n, K; 
const ll MOD = 1e9+7;
vector<int> g[N5];
int fa[N5];
int pre_color[N5];

ll dp[N5][4];

void build(int u) {
    for (auto v : g[u]) if (v != fa[u]) {
        fa[v] = u;
        build(v);
    }
}


ll solve(int u, int k) {
    if (dp[u][k] != -1) return dp[u][k];
    
    if (pre_color[u] != 0 && k != pre_color[u]) {
        dp[u][k] = 0;
    } else {
        dp[u][k] = 1;
        for (auto v : g[u]) if (v != fa[u]) {
            dp[u][k] *= (solve(v, 1) + solve(v, 2) + solve(v, 3) - solve(v, k)) % MOD;
            dp[u][k] %= MOD;
        }
    }

    return dp[u][k];
}


int main() {
#ifdef D
    freopen("4084.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    mmst(dp, -1);
    cin >> n >> K; 
    rep(i,1,n-1) {
        int u, v; 
        cin >> u >> v; 
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,1,K) {
        int b, c;
        cin >> b >> c;
        pre_color[b] = c;
    }


    build(1);

    ll ans = (solve(1, 1) + solve(1, 2) + solve(1, 3)) % MOD;

    cout << ans << endl;



#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}