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
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 212345
vector< pair<int, int> > son[N];
int fa[N], f[N], g[N];
int n;

void link(int u, int v, int d) {
    f[u] += f[v];
    f[u] += 1 - d;
}


void cut(int u, int v, int d) {
    f[u] -= f[v];
    f[u] -= 1 - d;
}

void cr(int u, int v, int d) {
    cut(u, v, d);
    link(v, u, 1 - d);
}

void dfsone(int u) {
    for(auto e : son[u]) {
        int v, d; tie(v, d) = e;
        if (v == fa[u]) continue;
        fa[v] = u;
        dfsone(v);
        link(u, v, d);
    }
}

void dfstwo(int u) {
    g[u] = f[u];
    for(auto e : son[u]) {
        int v, d; tie(v, d) = e;
        if (v == fa[u]) continue;
        cr(u, v, d);
        dfstwo(v);
        cr(v, u, 1-d);
    }
}
int main() {
#ifdef D
    freopen("CF219D.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    For(_, n-1) {
        int u = read(), v = read();
        son[u].push_back(make_pair(v, 1));
        son[v].push_back(make_pair(u, 0));
    }
    dfsone(1);
    dfstwo(1);

    // rep(i, 1, n) {
    //     printf("g[%d]=%d\n", i, g[i]);
    // }

    int minx = *min_element(g + 1, g + 1 + n);
    printf("%d\n", minx);
    bool first = true;
    rep(i, 1, n) {
        if (g[i] == minx) {
            if (!first) printf(" ");
            if (first) first = false;
            printf("%d", i);
        }
    }



#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}