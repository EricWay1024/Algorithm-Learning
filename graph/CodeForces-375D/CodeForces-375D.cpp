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
#include<unordered_map>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
typedef long long ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
const int N = 212345;
int n, m;
struct Query{
    int q, a;

    void output(){
        printf("%d\n", a);
    }
};

vector<int> son[N]; int fa[N];
int hson[N], sz[N];
int c[N];
vector<Query> query;
vector<int> q[N];

void dfs1(int u){
    sz[u]=1;
    for(int v:son[u]) if(v!=fa[u]){
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[hson[u]])hson[u]=v;
    }
}

struct TreeSolve{
    map<int, int> cnt;
    map<int, int> cntt;

    void add(int u, int skip, int val) {
        if(u == skip) return;
        
        // something beyond your imagination
        if (val == -1) cntt[cnt[c[u]]]--;
        cnt[c[u]] += val;
        if (val == 1) cntt[cnt[c[u]]]++;
        
        for(int v : son[u]) if (v!=fa[u]){
            add(v, skip, val);
        }
    }

    void get_ans(int u) {
        for(int i : q[u]) {
            int k = query[i].q;
            query[i].a = cntt[k];
        }
    }

    void del(int u) {
        // add(u, 0, -1);
        cnt.clear();
        cntt.clear();
        // using clear is faster
    }

}TS;

void dfs2(int u, bool keep) {
    for(int v : son[u]) if (v != hson[u] && v != fa[u]) {
        dfs2(v, 0);
    }

    if (hson[u]) dfs2(hson[u], 1);
    TS.add(u, hson[u], 1);
    TS.get_ans(u);
    if (!keep) TS.del(u);
}

int main() {
#ifdef D
    freopen("CodeForces-375D.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(), m = read();
    rep(i, 1, n) c[i] = read();
    rep(i, 1, n - 1) {
        int x = read(), y = read();
        son[x].push_back(y);
        son[y].push_back(x);
    }
    rep(i, 1, m) {
        int v = read(), k = read();
        query.push_back((Query){k, 0});
        q[v].push_back(query.size() - 1);
    }
    dfs1(1);
    dfs2(1, 1);

    for(auto &q : query) {
        q.output();
    }

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}