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
#include<random>
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

const int N = 1e5 + 100;
ll p, n, t;
ll x[N], y[N];

bool check(int i, int j) {
    ll cnt = 2;
    if (cnt >= t) return 1;
    rep(k,1,n) {
        if (k == i || k == j) continue;
        if ((y[k] - y[i]) * (x[k] - x[j]) == (y[k] - y[j]) * (x[k] - x[i])) {
            cnt++;
            if (cnt >= t) return 1;
        }
    }
    return cnt >= t;
}

int main() {
#ifdef D
    freopen("findinglines.in", "r", stdin);
#endif
    clock_t TIMEA = clock();
    rin >> n >> p;
    if (n == 1) {
        puts("possible");
        return 0;
    }

    t = (n * p + 99) / 100;
    rep(i,1,n) rin >> x[i] >> y[i];

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, n);

    while (1) {
        int i = dist(rng);
        int j = dist(rng);
        if (i == j) continue;

        if (check(i, j)) { puts("possible"); return 0; }
        float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
        if (TIMEUSED >= 2.95) break;
    }

    puts("impossible");


#ifdef D
    // if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}