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

int n;
const int N = 1512;
vector<int> son[N];
ll f[N][2];
int fa[N];

ll dp(int u, int op) {
    // op=0: father has no solider; op=1: father has one
    ll &mem = f[u][op]; if (mem > -1) return mem;

    ll t = 1; // what if i place one
    for(int v : son[u]) if (v != fa[u]) {
        t += dp(v, 1);
    }

    if (!op) return mem = t;

    ll s = 0; // what if i don't place a soldier
    for(int v : son[u]) if (v != fa[u]) {
        s += dp(v, 0);
    }
    return mem = min(s, t);

}

void build_tree(int u) {
    for(int v : son[u]) if (v != fa[u]) {
        fa[v] = u;
        build_tree(v);
    }
}

int main() {
#ifdef D
    freopen("2016.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    For(i, n) {
        int u = read();
        int c = read();
        For(j, c) {
            int v = read();
            son[u].push_back(v);
            son[v].push_back(u);
        }
    }

    int root = 0;
    fa[root] = -1;
    build_tree(root);

    memset(f, -1, sizeof(f));
    cout << dp(root, 1) << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}