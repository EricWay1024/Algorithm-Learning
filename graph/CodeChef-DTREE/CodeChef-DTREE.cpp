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
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 100200
void update_mxs2(int t, int& mx1, int& mx2) {
    if (t >= mx1) mx2 = mx1, mx1 = t;
    else mx2 = max(mx2, t);
}

void update_mxs3(int t, int& mx1, int& mx2, int& mx3) {
    if (t >= mx1) mx3 = mx2, mx2 = mx1, mx1 = t;
    else if (t >= mx2) mx3 = mx2, mx2 = t;
    else mx3 = max(mx3, t);
}

struct Solve{
    int n;
    vector<int> son[N]; int fa[N];
    int down[N], up[N], dmtr[N];
    int ans[N];

    void dfs1(int u) {
        int dnmx1 = -1, dnmx2 = -1;
        for(int v : son[u]) if (v != fa[u]) {
            fa[v] = u;
            dfs1(v);
            update_mxs2(down[v], dnmx1, dnmx2); 
            dmtr[u] = max(dmtr[u], dmtr[v]);
        }
        down[u] = dnmx1 + 1;
        dmtr[u] = max(dmtr[u], dnmx1 + dnmx2 + 2);
    }

    void dfs2(int u) {
        int dnmx1 = -1, dnmx2 = -1, dnmx3 = -1;
        int drmx1 = 0, drmx2 = 0;
        int p = ans[u]; // obtained from fa[u]
        for(int v : son[u]) if (v != fa[u]) {
            ans[u] = max(ans[u], dmtr[v]);
            update_mxs3(down[v], dnmx1, dnmx2, dnmx3);
            update_mxs2(dmtr[v], drmx1, drmx2);
        }
        for(int v : son[u]) if (v != fa[u]) {
            up[v] = max(up[u] + 1, down[v] == dnmx1 ? dnmx2 + 2 : dnmx1 + 2);
            int &mx = ans[v];
            mx = p;
            mx = max(mx, dmtr[v] == drmx1 ? drmx2 : drmx1);
            mx = max(mx, down[v] == dnmx1 ? up[u] + dnmx2 + 1 : up[u] + dnmx1 + 1);
            if (down[v] == dnmx1) mx = max(mx, dnmx2 + dnmx3 + 2);
            else if (down[v] == dnmx2) mx = max(mx, dnmx1 + dnmx3 + 2);
            else mx = max(mx, dnmx1 + dnmx2 + 2);
            dfs2(v);
        }
    }

    void solve() {
        n = read();
        rep(i, 1, n) son[i].clear();
        mmst(fa, 0);
        mmst(down, 0);
        mmst(up, 0);
        mmst(dmtr, 0);
        mmst(ans, 0);
        rep(i, 1, n-1){
            int u=read(), v=read();
            son[u].push_back(v);
            son[v].push_back(u);
        }
        dfs1(1);
        dfs2(1);
        rep(i, 1, n) {
            // logs(i, down[i], up[i], dmtr[i], ans[i]);
            printf("%d%c", ans[i], i < n ? 32 : 10);
        }
    }
}S;

int main() {
#ifdef D
    freopen("CodeChef-DTREE.in", "r", stdin);
    double TIMEA = clock();
#endif
    int T=read();
    while(T--) {
        S.solve();
    }

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}