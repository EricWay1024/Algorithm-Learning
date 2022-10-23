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
#include<numeric>
#include<functional>
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
#define N 112345
int n, k;
vector<int> son[N];
int fa[N], c[N];
int f[N][30], ans[N];
// f[i][j] := in the subtree with root i, sum of nodes with depth j

// y is a son of x, now cut y from x
void cut(int x, int y) {
    rep(i, 1, k) f[x][i] -= f[y][i - 1];
}

// now let y be a son of x
void link(int x, int y) {
    rep(i, 1, k) f[x][i] += f[y][i - 1];
}

// change root operation
void cr(int u, int v){
    cut(u, v);
    link(v, u);
}

void dfsone(int u) {
    f[u][0] = c[u];
    for(int v : son[u]) if (v != fa[u]) {
        fa[v] = u;
        dfsone(v);
        link(u, v);
    }
}

void dfstwo(int u) {
    rep(i, 0, k) ans[u] += f[u][i];
    for(int v : son[u]) if (v != fa[u]) {
        cr(u, v);
        dfstwo(v);
        cr(v, u);
    }
}

int main() {
#ifdef D
    freopen("3047.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(), k = read();

    For(_, n-1) {
        int u = read(), v = read();
        son[u].push_back(v);
        son[v].push_back(u);
    }

    rep(i, 1, n) {
        c[i] = read();
    }

    dfsone(1);
    dfstwo(1);

    rep(i, 1, n) {
        cout << ans[i] << endl;
    }

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}