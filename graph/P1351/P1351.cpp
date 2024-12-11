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

const int N = N5 << 1; 
int n; 
vector<int> g[N];
ll w[N];
const ll MOD = 10007;
int fa[N];

ll mxans = 0;
ll smans = 0;
void build(int u) {
    ll mxw1 = 0;
    ll mxw2 = 0;
    ll smw = 0;
    ll smw2 = 0;
    for (auto v: g[u]) if (v != fa[u]) {
        fa[v] = u;
        if (w[v] >= mxw1) {
            mxw2 = mxw1;
            mxw1 = w[v];
        } else if (w[v] >= mxw2) {
            mxw2 = w[v];
        }

        smw += w[v];
        smw2 += w[v] * w[v];
        smw %= MOD;
        smw2 %= MOD;

        build(v);
    }

    smans += smw * smw - smw2;
    smans %= MOD;
    smans += w[fa[u]] * smw * 2ll;
    smans %= MOD;

    mxans = max(mxans, mxw1 * mxw2);
    mxans = max(mxans, mxw1 * w[fa[u]]);
}

int main() {
#ifdef D
    freopen("P1351.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> n; 
    rep(i,1,n-1) {
        int a, b; 
        rin >> a >> b; 
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i,1,n) rin >> w[i];

    build(1);
    smans += MOD;
    smans %= MOD;

    cout << mxans << " " << smans << endl;


#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}