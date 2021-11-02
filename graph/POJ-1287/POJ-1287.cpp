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
    void dbg() {cout << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
    #define logs(x...) {cout << #x << " -> "; dbg(x);}
#else
    // template<typename T, typename... Args> void logs(T t, Args... args) {};
#endif
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

const int N  = 75;
ll g[N][N];
ll n, m;
ll d[N];
bool v[N];

bool solve() {
    n = read(); if (!n) return 0;
    m = read(); 
    mmst(g, 0x3f);
    rep(i,1,m) {
        int x = read(); int y = read();
        g[y][x] = g[x][y] = min(g[x][y], read());
    }
    mmst(d, 0x3f);
    mmst(v, 0);
    d[1] = 0;
    For(i, n-1) {
        int x = 0;
        rep(j,1,n) if (!v[j] && d[j] < d[x]) x = j;
        v[x] = 1;
        rep(y,1,n) if (!v[y]) d[y] = min(d[y], g[x][y]);
    }
    ll ans = 0;
    rep(i,1,n) ans += d[i];
    cout << ans << endl;
    return 1;
}
int main() {
#ifdef D
    freopen("POJ-1287.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    while (solve());

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}