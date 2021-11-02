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
#include<utility>
#include<vector>
#include<numeric>
#include<functional>
// #include<cstdint>
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
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
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

const int N = 512;
const int d[6][2] = {
    {1, -2}, {-1, -3}, {-1, -2}, {-2, -1}, {-3, -1}, {-2, 1}
};

int mem[N][N];
int sg(int x, int y) {
    if (mem[x][y]>-1) return mem[x][y];
    short vis[20] = {0};
    For(i, 6) {
        int dx = d[i][0], dy = d[i][1];
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || ny < 0) continue;
        vis[sg(nx, ny)] = 1;
    }

    for(int i=0; ; ++i) if (!vis[i]) return mem[x][y]=i;

}
void init() {
    mmst(mem, -1);
    // int m=0;
    // rep(x, 0, N-2) {
    //     rep(y, 0, N-2) {
    //         sg(x, y);
    //         // m=max(m, sg(x, y));
    //     }
    // }
    // cout << 'm' << m << endl;
}

void solve() {
    int n=read();
    int ans=0;
    rep(i,1,n) {
        int x=read(), y=read();
        ans ^= sg(x, y);
    }
    puts(ans ? "Alice" : "Bob");

}

int main() {
#ifdef D
    freopen("LightOJ-1315.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init();
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}