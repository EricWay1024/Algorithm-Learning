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
#define N 1123456
vector<int> son[N];
ll fa[N], sz[N], dpth[N], f[N];
void dfsone(int u){
    sz[u] = 1;

    if (u == 1) dpth[u] = 0;
    else dpth[u] = dpth[fa[u]] + 1;

    f[1] += dpth[u];

    for(int v : son[u]) if (v != fa[u]) {
        fa[v] = u;
        dfsone(v);
        sz[u] += sz[v];
    }
}

void dfstwo(int u) {
    for(int v : son[u]) if (v != fa[u]) {
        f[v] = f[u] + n - 2 * sz[v];
        dfstwo(v);
    }
}

int main() {
#ifdef D
    freopen("3478.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    For(_, n-1) {
        int u = read(), v = read();
        son[u].push_back(v);
        son[v].push_back(u);
    }

    dfsone(1);
    dfstwo(1);
    ll ans = 0;
    int t = 1;
    rep(i, 1, n) {
        if (f[i] > ans) {
            ans = f[i];
            t = i;
        }
    }
    cout << t << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}