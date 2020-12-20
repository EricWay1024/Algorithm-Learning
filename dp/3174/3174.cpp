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

int n, m;
#define N 301000
vector<int> son[N]; int fa[N];
int g[N], f[N];

int sonsize(int u) {
    return son[u].size() - !!fa[u];
}

void dfs(int u) {
    int mx1 = 1, mx2 = 1;
    for(int v : son[u]) if (v != fa[u]) {
        fa[v] = u;
        dfs(v);

        if (f[v] >= mx1) {
            mx2 = mx1, mx1 = f[v];
        } else if (f[v] >= mx2) {
            mx2 = f[v];
        }
    }
    f[u] = mx1 + sonsize(u);
    g[u] = mx1 + mx2 + sonsize(u) - 1;
}


int main() {
#ifdef D
    freopen("3174.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(), m = read();
    For(_, m) {
        int a = read(), b = read();
        son[a].push_back(b);
        son[b].push_back(a);
    }

    dfs(1);
    // rep(i, 1, n) {
    //     printf("f[%d]=%d, g[%d]=%d\n", i, f[i], i, g[i]);
    // }

    int ans = 1;
    rep(i, 1, n) {
        ans = max(ans, g[i] + !!fa[i]);
    }

    cout << ans << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}