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
int n, root;
#define N 501000
vector< pair<int, ll> > son[N];
int fa[N]; ll f[N], g[N];

void dfsone(int u) {
    for(auto e : son[u]) {
        int v; ll d; tie(v, d) = e;
        if (v == fa[u]) continue;
        fa[v] = u;
        dfsone(v);
        f[u] = max(f[u], f[v] + d);
    }
}

void dfstwo(int u) {
    for(auto e : son[u]) {
        int v; ll d; tie(v, d) = e;
        if (v == fa[u]) continue;
        dfstwo(v);
        g[u] += g[v] + (f[u] - f[v] - d);
    }
}

int main() {
#ifdef D
    freopen("1131.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(), root = read();
    For(_, n-1) {
        int a = read(), b = read();
        ll t = read();
        son[a].push_back(make_pair(b, t));
        son[b].push_back(make_pair(a, t));
    }
    dfsone(root);
    dfstwo(root);

    cout << g[root] << "\n";


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}