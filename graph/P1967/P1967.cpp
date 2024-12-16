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

const int N = N4;

int n, m;
bool v[N];
long long d[N];

vector<pair<int, int>> g[N];

void prim()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int x = -1;
        long long min_dist = LONG_LONG_MAX;
        for (int j = 1; j <= n; j++)
        {
            if (!v[j] && (d[j] < min_dist))
                min_dist = d[j], x = j;
        }
        v[x] = 1;
        for (int y = 1; y <= n; y++)
        {
            if (!v[y])
                d[y] = min(d[y], dist(city[x], city[y]));
        }
    }
}

int main() {
#ifdef D
    freopen("P1967.in", "r", stdin);
    clock_t TIMEA = clock();
#endif  
    cin >> n >> m;
    rep(i,1,m) {
        int x, y, z; 
        cin >> x >> y >> z; 
    }


#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}