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

// int mem[100][100];
// int sg(int w, int y) {
//     if (w == 1) return y + 1;
//     if (y == 0 && (w % 2) == 0) return 0; 
//     if (mem[w][y] > -1) return mem[w][y];

//     set<int> st;
//     st.insert(sg(w-1, y));
//     rep(i, 0, y-1) st.insert(sg(w, i));

//     for(int i=0; ; ++i) {
//         if (!st.count(i)) return mem[w][y]=i;
//     }

// }
int sg(int w, int y) {
    if (w == 1) return y + 1;
    return (w&1) ? y^1 : y;
}

int n;
const int N = 1024;
vector< pair<int, int> > son[N];
int dfs(int u, int fa) {
    int ans = 0;
    for(auto p: son[u]) {
        int v, w; tie(v, w) = p;
        if (v == fa) continue;
        ans ^= sg(w, dfs(v, u));
    }
    return ans;
}
void solve() {
    n=read();
    rep(i,1,n) son[i].clear();
    rep(i,1,n-1){
        int u=read()+1;
        int v=read()+1;
        int w=read();
        son[u].push_back(make_pair(v, w));
        son[v].push_back(make_pair(u, w));
    }
    int ans = dfs(1, 0);
    puts(ans ? "Emily" : "Jolly");
}

int main() {
#ifdef D
    freopen("LightOJ-1355.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }
    // mmst(mem, -1);
    // rep(w, 1, 10) {
    //     rep(y, 0, 10) {
    //         printf("w=%d, y=%d, sg=%d\n", w, y, sg(w, y));
    //     }
    // }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}