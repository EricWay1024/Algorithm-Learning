//#include <bits/stdc++.h>
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
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 400010
int n;
vector<int> son[N]; int fa[N];
int sz[N], msn[N], ans[N];


// v, a son of u, is cut from u
void cut(int u, int v) {
    fa[v] = 0;
    sz[u] -= sz[v];

    if (v == msn[u]) {
        msn[u] = 0;
        for(int w : son[u]) if (w != v && w != fa[u]) {
            if (sz[w] > sz[msn[u]]) msn[u] = w;
        }
    }
}

// let v be a son of u
void link(int u, int v) {
    fa[v] = u;
    sz[u] += sz[v];

    if (sz[v] > sz[msn[u]]) msn[u] = v;
}

void change_root(int u, int v) {
    cut(u, v);
    link(v, u);
}

void dfsone(int u) {
    sz[u] = 1;
    for(int v : son[u]) if (v != fa[u]) {
        fa[v] = u;
        dfsone(v);
        link(u, v);
        if (sz[v] > sz[msn[u]]) msn[u] = v;
    }
}

bool srch(int u, int s) {
    for(int v : son[u]) if (v != fa[u]) {
        if (2 * s - n <= 2 * sz[v] && 2 * sz[v] <= n) return true;
    }
    for(int v : son[u]) if (v != fa[u]) {
        if (srch(v, s)) return true;
    }
    return false;
}

void dfstwo(int u) {
    if(ans[u] > -1) return;
    int mv = msn[u];
    if (mv == 0) ans[u] = 1;
    else if (2 * sz[mv] <= n) ans[u] = 1;
    else ans[u] = srch(mv, sz[mv]);

    // printf("ans[%d]=%d\n", u, ans[u]);

    for(int v : son[u]) {
        change_root(u, v);
        dfstwo(v);
        change_root(v, u);
    }
}


int main() {
#ifdef D
    freopen("CF708C.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    For(_, n-1) {
        int u = read(), v = read();
        son[u].push_back(v);
        son[v].push_back(u);
    }

    dfsone(1);
    // for(int i = 1; i<=n;i++) {
    //     printf("sz[%d]=%d, msn[%d]=%d\n", i, sz[i], i, msn[i]);
    // }
    memset(ans, -1, sizeof(ans));
    dfstwo(1);

    rep(i, 1, n) cout << ans[i] << (i < n ? " " : "");
    cout << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}