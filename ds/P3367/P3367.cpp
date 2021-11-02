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
const int N = 1e5 + 100;
struct DSU {
    int a[N], sz[N];
    void init(int n) {
        iota(a, a + n + 1, 0);
        fill(sz, sz + n + 1, 1);
    }
    int fa(int x) {
        return a[x] == x ? x : a[x] = fa(a[x]);
    } 
    bool query(int x, int y) {
        return fa(x) == fa(y);
    }
    void join(int x, int y) {
        x = fa(x), y = fa(y);
        if (x == y) return; 
        if (sz[x] > sz[y]) swap(x, y);
        a[x] = y; sz[y] += sz[x];
    }
} d;  


int main() {
#ifdef D
    freopen("P3367.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n = read(), m = read();
    d.init(n);
    while (m--) {
        int o = read();
        int x = read(), y = read();
        if (o == 1) {
            d.join(x, y);
        } else {
            puts(d.query(x, y) ? "Y" : "N");
        }
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}