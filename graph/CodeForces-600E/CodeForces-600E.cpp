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
typedef long long ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 512345
int n; int c[N];
vector<int> son[N];
int fa[N];
int hson[N]; int sz[N];

ll ans[N];
ll cnt[N], maxc, sumc;

void dfs1(int u) {
    sz[u] = 1;
    for(int v : son[u]) if (v != fa[u]) {
        fa[v] = u;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > sz[hson[u]]) hson[u] = v;
    }
}

void add(int u, ll val, int flag) {
    if (u == flag) return;

    cnt[c[u]] += val;
    if (cnt[c[u]] > maxc) {
        maxc = cnt[c[u]];
        sumc = c[u];
    } else if (cnt[c[u]] == maxc) {
        sumc += c[u];
    }

    for(int v : son[u]) if (v != fa[u]) {
        add(v, val, flag);
    }
}


void dfs2(int u, bool keep) {
    for(int v : son[u]) if (v != fa[u] && v != hson[u]) {
        dfs2(v, 0);
    }
    if(hson[u]) {
        dfs2(hson[u], 1);
    }
    
    add(u, 1, hson[u]);
    ans[u] = sumc;
    
    if (!keep) {
        add(u, -1, 0);
        // memset(cnt, 0, sizeof(cnt)); memset could cause TLE
        sumc = maxc = 0;
    }
}


int main() {
#ifdef D
    freopen("CodeForces-600E.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    rep(i, 1, n) c[i] = read();
    For(_, n-1) {
        int x = read(); int y = read();
        son[x].push_back(y);
        son[y].push_back(x);
    }

    dfs1(1);
    dfs2(1, 1);
    rep(i, 1, n) {
        printf("%lld", ans[i]);
        if (i < n) putchar(32);
    }
    putchar('\n');


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}