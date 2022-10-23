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
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}

#define N 112344
vector< pair<int, int> > son[N];
ll sz[N], fa[N], f[N], c[N], n, cst[N];

void dfsone(int u) {
    sz[u] = c[u];
    cst[u] = 0;
    for(auto p : son[u]) {
        int v, w; tie (v, w) = p;
        if (v == fa[u]) continue;
        fa[v] = u;
        dfsone(v);
        sz[u] += sz[v];
        cst[u] += sz[v] * (ll)w + cst[v];
    }
}

void dfstwo(int u) {
    for(auto p : son[u]) {
        int v, w; tie (v, w) = p;
        if (v == fa[u]) continue;
        f[v] = f[u] + (ll)w * (sz[1] - 2 * sz[v]);
        dfstwo(v);
    }
}
int main() {
#ifdef D
    freopen("2986.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    rep(i, 1, n) {
        c[i] = read();
    }
    For(_, n-1) {
        int a = read(), b = read(), l = read();
        son[a].push_back(make_pair(b, l));
        son[b].push_back(make_pair(a, l));
    }
    dfsone(1);
    f[1] = cst[1];
    dfstwo(1);
    ll minn = INT64_MAX;
    rep(i, 1, n) {
        minn = min(minn, f[i]);
        // printf("f[%d]=%d\n", i, f[i]);
    }
    cout << minn << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}