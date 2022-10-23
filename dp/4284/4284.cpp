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
#include<cstdint>
#include<climits>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 501000
vector< pair<int, int> > son[N];
int fa[N]; int q[N], n;
double g[N], f[N];
int one[N];
#define dv(i) ((double)i/100.0)
#define eps (1e-8)
#define gg(u) (one[u] ? 1.0 : g[u])

void link(int u, int v, double p) {
    if (1.0 - p * gg(v) < eps) one[u]++;
    else g[u] = g[u] + (1.0 - g[u]) * p * gg(v);
}

void cut(int u, int v, double p) {
    if (1.0 - p * gg(v) < eps) one[u]--;
    else g[u] = (g[u] - p * gg(v)) / (1.0 - p * gg(v));
}

void cr(int u, int v, double p) {
    cut(u,v,p);
    link(v,u,p);
}

void dfsone(int u) {
    g[u] = dv(q[u]);
    for(auto e : son[u]) {
        int v, w; tie(v, w) = e;
        if (v == fa[u]) continue;
        fa[v] = u;
        dfsone(v);
        link(u,v,dv(w));
    }
}

void dfstwo(int u) {
    f[u] = gg(u);
    for(auto e : son[u]) {
        int v, w; tie(v, w) = e;
        if (v == fa[u]) continue;
        cr(u,v,dv(w));
        dfstwo(v);
        cr(v,u,dv(w));
    }
}


int main() {
#ifdef D
    freopen("4284.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    rep(i,1,n-1){
        int a=read(),b=read(),p=read();
        son[a].push_back(make_pair(b,p));
        son[b].push_back(make_pair(a,p));
    }
    rep(i,1,n){
        q[i]=read();
    }

    dfsone(1);
    dfstwo(1);

    double ans = accumulate(f + 1, f + 1 + n, 0.0);
    printf("%.6lf\n", ans);

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}