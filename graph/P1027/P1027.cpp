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

int S, t, A, B;

vector<pair<int, double>> g[N3];

int dist2(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


int x[N3], y[N3];
int rail_cost[N3];

double d[N3][N3];

void find_fourth(int i) {
    int ab2 = dist2(x[4*i-3], y[4*i-3], x[4*i-2], y[4*i-2]);
    int ac2 = dist2(x[4*i-3], y[4*i-3], x[4*i-1], y[4*i-1]);
    int bc2 = dist2(x[4*i-1], y[4*i-1], x[4*i-2], y[4*i-2]);


    if (ab2 + ac2 == bc2) {
        x[4*i] = x[4*i-2] + x[4*i-1] - x[4*i-3];
        y[4*i] = y[4*i-2] + y[4*i-1] - y[4*i-3];
    }

    if (ab2 + bc2 == ac2) {
        x[4*i] = -x[4*i-2] + x[4*i-1] + x[4*i-3];
        y[4*i] = -y[4*i-2] + y[4*i-1] + y[4*i-3];
    }

    if (bc2 + ac2 == ab2) {
        x[4*i] = x[4*i-2] - x[4*i-1] + x[4*i-3];
        y[4*i] = y[4*i-2] - y[4*i-1] + y[4*i-3];
    }
}

void solv() {
    rin >> S >> t >> A >> B; 

    rep(i,1,S){
        rep(j, 4 * i - 3, 4 * i - 1) rin >> x[j] >> y[j];
        rin >> rail_cost[i];
        find_fourth(i);

        // logs(i, x[4*i], y[4*i])
    }

    rep(i,1,S*4) {
        rep(j,1,S*4) {
            if (i == j) continue;
            int ci = (i - 1) / 4 + 1;
            int cj = (j - 1) / 4 + 1;
            if (ci == cj) {
               d[i][j] = rail_cost[ci] * dist(x[i], y[i], x[j], y[j]);
            } else {
                d[i][j] = t * dist(x[i], y[i], x[j], y[j]);
            }
        }
    }

    rep(k,1,S*4) rep(i,1,S*4) rep(j,1,S*4) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    double ans = 1e99;
    rep(i,0,3)rep(j,0,3) {
        ans = min(ans, d[4 * A - i][4 * B - j]);
    }

    cout<<fixed<<setprecision(1)<<ans<< endl;

}
int main() {
#ifdef D
    freopen("P1027.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T; 
    rin >> T; 
    while (T--) {
        solv();
    }


#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}