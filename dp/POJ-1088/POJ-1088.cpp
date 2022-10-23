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

ll mem[N2][N2];
ll game[N2][N2];
ll r, c;

const int d[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

ll solve(ll x, ll y) {
    if (~mem[x][y]) return mem[x][y];

    ll res = 1;
    For(i, 4) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
        if (game[nx][ny] >= game[x][y]) continue;
        res = max(res, solve(nx, ny) + 1);
    }

    return mem[x][y] = res;
}


int main() {
#ifdef D
    freopen("POJ-1088.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rin >> r >> c;
    mmst(mem, -1);
    rep(i,1,r) rep(j,1,c) {
        rin >> game[i][j];
    }

    ll res = 0;
    rep(x,1,r) rep(y,1,c) {
        res = max(solve(x, y), res);
    }

    cout << res << endl;




#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}