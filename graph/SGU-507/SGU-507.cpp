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
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
typedef long double ld;
inline int read(){
    int x=0; int sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 512345
int n, m;
vector<int> son[N];
int hson[N], sz[N], w[N];
const int INF = 2147483647;

void dfs1(int u) {
    sz[u] = 1;
    for(int v : son[u]) {
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > sz[hson[u]]) hson[u] = v;
    }
}


struct TreeSolve{
    set<int> s;
    int diff;

    void solve(int u, int skip) {
        if (u == skip) return;

        if (son[u].empty()) {
            if (s.find(w[u]) != s.end()) {
                diff = 0;
            } else {
                s.insert(w[u]);
                if (s.size() == 1) {
                    diff = INF;
                } else {
                    auto it = s.find(w[u]);
                    if (it != s.begin()) {
                        diff = min(diff, abs(*it - *prev(it)));
                    }
                    if (it != prev(s.end())) {
                        diff = min(diff, abs(*it - *next(it)));
                    }
                }
            }
        } 
        
        else {
            for(int v : son[u]) {
                solve(v, skip);
            }
        }
    }

    void init() {
        diff = INF;
        s.clear();
    }

    int ans() {
        return diff;
    }
}TS;

int ans[N];

void dfs2(int u, bool keep) {
    for(int v : son[u]) if (v != hson[u]) {
        dfs2(v, 0);
    }

    if (hson[u]) dfs2(hson[u], 1);

    TS.solve(u, hson[u]);
    ans[u] = TS.ans();

    if (!keep) {
        TS.init();
    }
}

int main() {
#ifdef D
    freopen("SGU-507.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(), m = read();
    rep(i, 2, n) {
        son[read()].push_back(i);
    }
    rep(i, n-m+1, n) w[i] = read();

    dfs1(1);
    TS.init();
    dfs2(1, 1);

    rep(i, 1, n-m) {
        if (i > 1) putchar(32);
        printf("%d", ans[i]);
    }
    putchar(10);

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}