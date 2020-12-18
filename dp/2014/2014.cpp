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
#define N 321
#define mst(a,b) memset(a,b,sizeof(a))

vector<int> son[N];
int w[N], fa[N], siz[N];
int f[N][N][N]; 
// for a subtree with root u, when choosing k lessons, the maximum score we could get is f[u][k]

void bt(int u) {
    siz[u] = 1;
    for(int v : son[u]) {
        bt(v);
        siz[u] += siz[v];
    }
}

int dp(int u, int k, int sn) {
    // u: current node, k: lesson numbers, sn: we have considered its sn-th son
    // the maxium score we can get
    int &mem = f[u][k][sn];
    if (mem > -1) return mem;
    if (sn == son[u].size()) {
        return 0;
    }
    if (k == 0) return 0;
    if (k == 1) {
        if (u) {
            return w[u];
        } else {
            int ret = 0;
            for(int v : son[u]) {
                ret = max(ret, dp(v, 1, 0));
            }
            return mem = ret;
        }
    }

    int ret = 0;
    for(int j = 0; j <= k - 1; j++){
        int v = son[u][sn];
        ret = max(ret, dp(v, j, 0) + dp(u, k-1-j, ))
    }

}

int main() {
#ifdef D
    freopen("2014.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(); m = read();
    rep(i, 1, n) {
        fa[i] = read();
        w[i] = read();
        son[fa[i]].push_back(i);
    }
    mst(f, -1);
    cout << dp(0, m+1) << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}