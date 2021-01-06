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
const ll M = 1000000007ll;
#define N 212345
int n;
vector<int> son[N];
int fa[N];
ll f[N], g[N];
ll zero[N];

ll powm(ll a, ll b, ll p) {
    ll ans = 1;
    a %= p;
    for(; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

ll inv(ll a) {
    return powm(a, M - 2, M);
}

void link(int u, int v) {
    if (zero[v]) {
        return;
    }
    if (((1ll + f[v]) % M) == 0) {
        zero[u]++;
        return;
    } 
    f[u] *= (1ll + f[v]);
    f[u] %= M;
}

void cut(int u, int v) {
    if (zero[v]) {
        return;
    }
    if (((1ll + f[v]) % M) == 0) {
        zero[u]--;
        return;
    } 
    f[u] *= inv(1ll + f[v]);
    f[u] %= M;
}

void cr(int u, int v) {
    cut(u, v);
    link(v, u);
}

void dfsone(int u) {
    f[u] = 1ll;
    for(int v : son[u]) if (v != fa[u]) {
        fa[v] = u;
        dfsone(v);
        link(u, v);
    }
}

void dfstwo(int u) {
    g[u] = zero[u] ? 0 : f[u];
    for(int v : son[u]) if (v != fa[u]) {
        cr(u, v);
        dfstwo(v);
        cr(v, u);
    }
}

int main() {
#ifdef D
    freopen("CF543D.in", "r", stdin);
    double TIMEA = clock();
#endif

    n = read();
    rep(i, 2, n) {
        int p = read();
        son[i].push_back(p);
        son[p].push_back(i);
    }
    dfsone(1);
    dfstwo(1);
    rep(i, 1, n) {
        cout << (i - 1 ? " " : "") << g[i];
    }
    cout << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}