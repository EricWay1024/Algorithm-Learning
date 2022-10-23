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

#define N 1123456
vector< pair<int, ll> > son[N];
int fa[N]; ll f[N], sz[N]; int n;

void dfsone(int u) {
    sz[u] = 1;
    for(auto e : son[u]) {
        int v; ll d; tie(v, d) = e;
        if (v == fa[u]) continue;
        fa[v] = u;
        dfsone(v);
        sz[u] += sz[v];
        f[u] += f[v] + d * abs(2 * sz[v] - n);
    }
}

int main() {
#ifdef D
    freopen("2052.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    For(_, n-1) {
        int u = read(), v = read();
        ll w = read();
        son[u].push_back(make_pair(v, w));
        son[v].push_back(make_pair(u, w));
    }
    dfsone(1);

    cout << f[1] << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}