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

const int N = 410;
int n, m, t; 
int game[N][N];
vector<int> grh[N];

int visit[N];
int match[N];
bool dfs(int x) {
    for(auto y: grh[x]) {
        if (!visit[y]) {
            visit[y] = 1;
            if (!match[y] || dfs(match[y])) {
                match[y] =  x; return true;
            }
        }
    }
    return false;
}
ll max_match() {
    ll ans = 0;
    rep(i,1,n + m) {
        mmst(visit, 0);
        if (dfs(i)) ans++;
    }
    return ans;
}


int main() {
#ifdef D
    freopen("acwing375.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> n >> m >> t;
    rep(i,1,t) {
        int x, y; rin >> x >> y;
        game[x][y] = 1; 
    }
    // row: 1, 2, .., n; col: n + 1, ... n+m

    rep(x,1,n) {
        rep(y,1,m) {
            if (game[x][y]) continue;
            grh[x].push_back(y + n);
            grh[y + n].push_back(x);
        }
    }

    cout << max_match() / 2 << endl;


#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}