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

const int N = 54;
const int M = 21234;
int n, m; db t1, t2, v;
int ax[N], ay[N];
int bx[N], by[N];

db dist(db x1, db y1, db x2, db y2) {
    return hypot(x1 - x2, y1 - y2);
}

const db eps = 1e-7;

vector<int> grh[M];
int s = 0;
int visit[M];
int match[M];
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
bool max_match() {
    ll ans = 0;
    mmst(match, 0);
    rep(i,1,m) {
        mmst(visit, 0);
        if (!dfs(i)) return 0;
    }
    return 1;
}

int main() {
#ifdef D
    freopen("acwing376.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    cin >> n >> m >> t1 >> t2 >> v;
    t1 /= 60;
    rep(i,1,m) cin >> ax[i] >> ay[i];
    rep(i,1,n) cin >> bx[i] >> by[i];

    db l = 0, r = (t1 + t2) * m;
    rep(i,1,m) {
        r += dist(ax[i], ay[i], bx[1], by[1]) / (db)v;
    }

    while (r - l > eps) {
        db mid = (r + l) / 2;
        int p = floor((mid + t2) / (db)(t1 + t2));
        p = min(p, m); // important

        rep(i,1,s) grh[i].clear();
        s = 0;

        rep(i,1,m) {
            rep(j,1,n) {
                rep(k,1,p) {
                    db hit_time = k * t1 + (k - 1) * t2 + dist(ax[i], ay[i], bx[j], by[j]) / v;
                    if (hit_time <= mid) {
                        grh[i].push_back(m + (j - 1) * p + k);
                        grh[m + (j - 1) * p + k].push_back(i);
                        s = max(s, m + (j - 1) * p + k);
                    }
                }
            }
        }
        logs(s);
        logs(l, r);
        if (max_match()) r = mid;
        else l = mid;
    }

    coutP(6) << l << endl;

#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}