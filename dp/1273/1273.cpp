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
// #include<cstdint>
#include<climits>
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(register int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 3123
vector<pair<int, int> > son[N];
int money[N];
int f[N][N];
int sz[N];
int n, m;

void dp(int u) {
    for(auto e : son[u]) {
        int v = e.first;
        dp(v);
        sz[u] += sz[v];
    }

    for(auto e : son[u]) {
        int v, w; tie(v, w) = e;
        rev(k, sz[u], 1) {
            rep(l, 1, k) {
                f[u][k] = max(f[u][k], f[v][l] + f[u][k-l] - w);
            }
        }
    }
}

int main() {
#ifdef D
    freopen("1273.in", "r", stdin);
    double TIMEA = clock();
#endif 
    n = read(); m = read();
    memset(f, 0xcf, sizeof(f));
    rep(i, 1, n - m) {
        int k = read();
        For(_, k) {
            int a = read(), c = read(); // v, w
            son[i].push_back(make_pair(a, c));
        }
        f[i][0] = 0;
    }
    rep(i, n - m + 1, n) {
        money[i] = read();
        f[i][1] = money[i];
        sz[i] = 1;
    }
    dp(1);
    rev(i, m, 0) {
        if (f[1][i] >= 0) {
            cout << i << endl;
            break;
        }
    }

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}