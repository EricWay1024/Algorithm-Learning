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

int mem[10010];
// bitset<10010> vis;
short vis[10010];
int sg(int n) {
    if (n <= 2) return 0;
    if (mem[n]>-1) return mem[n];
    // vis.reset();
    mmst(vis, 0);
    rep(i,1,n/2) {
        int j = n-i;
        if(j==i) continue;
        vis[sg(i) ^ sg(j)] = 1;
    }
    for(int i=0; ; ++i) {
        if(!vis[i]) return mem[n]=i;
    }
}

void init() {
    mmst(mem, -1);
    rep(n,3,10000) sg(n);
}

void solve() {
    int m=read();
    int ans=0;
    For(_, m) {
        int n=read();
        ans ^= sg(n);
    }
    puts(ans ? "Alice" : "Bob");

}

// int main() {
//     freopen("tmp", "w", stdout);
//     mmst(mem, -1);
//     rep(n, 0, 100) {
//         printf("n=%d, sg=%d\n", n, sg(n));
//     }
// }

int main() {
#ifdef D
    freopen("LightOJ-1199.in", "r", stdin);
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