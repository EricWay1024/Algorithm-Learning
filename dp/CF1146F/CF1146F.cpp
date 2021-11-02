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
#define M 998244353ll
#define N 200100 

vector<int> son[N]; int fa[N]; int n;
ll f[N][3];

int sonsize(int u) {
    return son[u].size() - !!fa[u];
}

void dfsone(int u) {
    if (!sonsize(u)) f[u][2] = 1;
    else f[u][0] = 1;

    for(int v : son[u]) if (v != fa[u]) {
        fa[v] = u;
        dfsone(v);

        f[u][2] = f[u][2] * (f[v][0] + f[v][2]) + (f[u][1] + f[u][2]) * (f[v][1] + f[v][2]); f[u][2] %= M;
        f[u][1] = f[u][1] * (f[v][0] + f[v][2]) + f[u][0] * (f[v][1] + f[v][2]); f[u][1] %= M;
        f[u][0] = f[u][0] * (f[v][0] + f[v][2]); f[u][0] %= M;
    }

}

int main() {
#ifdef D
    freopen("CF1146F.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    rep(i, 2, n) {
        int p = read();
        son[p].push_back(i);
        son[i].push_back(p);
    }

    dfsone(1);

    cout << ((f[1][0]+f[1][2])%M) << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}