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

#define int long long
const int N = 210;
vector<int> ver;
vector<int> edge;
vector<int> grh[N];
int v[N], incf[N], pre[N];
int n, m, s, t, maxflow;

void add(int x, int y, int z) {
    int tot = ver.size();
    ver.push_back(y);
    edge.push_back(z);
    grh[x].push_back(tot);
    ver.push_back(x);
    edge.push_back(0);
    grh[y].push_back(tot + 1);
}

bool bfs() {
    mmst(v, 0);
    queue<int> q;
    q.push(s);
    v[s] = 1;
    incf[s] = INT32_MAX;
    while (q.size()) {
        int x = q.front(); q.pop();
        for(auto i: grh[x]) {
            if (edge[i]) {
                int y = ver[i];
                if (v[y]) continue;
                incf[y] = min(incf[x], edge[i]);
                pre[y] = i;
                q.push(y); v[y] = 1;
                if (y == t) return 1;
            }
        }
    }
    return 0;
}

void update() {
    int x = t;
    while (x != s) {
        int i = pre[x];
        edge[i] -= incf[t];
        edge[i ^ 1] += incf[t];
        x = ver[i ^ 1];
    }
    maxflow += incf[t];
}


signed main() {
#ifdef D
    freopen("P3376.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> n >> m >> s >> t;
    rep(i,1,m) {
        int u, v, w;
        rin >> u >> v >> w;
        add(u, v, w);
    }
    while (bfs()) update();
    cout << maxflow << endl;

#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}