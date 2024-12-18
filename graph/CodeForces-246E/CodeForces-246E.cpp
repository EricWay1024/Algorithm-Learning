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

#define N 112345
int n, m;
vector<int> son[N];
int name[N];
map<string, int> nmp; int ncnt;
int hson[N], sz[N], dpth[N];
struct Query{
    int q, a;
    void output(){
        printf("%d\n", a);
    }
};
vector<Query> query;
vector<int> q[N];

int get_id(string &s){
    int &id = nmp[s];
    if (id) return id;
    else return id = (++ncnt);
}

void dfs1(int u, int d){
    sz[u]=1;
    dpth[u]=d;
    for(int v:son[u]) {
        dfs1(v, d+1);
        sz[u]+=sz[v];
        if(sz[v]>sz[hson[u]])hson[u]=v;
    }
}

struct TreeSolve {
    map<int, set<int> > mp;

    void add(int u, int skip) {
        if (u == skip) return;

        mp[dpth[u]].insert(name[u]);

        for(int v : son[u]) {
            add(v, skip);
        }
    }

    void get_ans(int u) {
        for(int i : q[u]) {
            int k = query[i].q + dpth[u];
            query[i].a = mp[k].size();
        }
    }

    void del() {
        mp.clear();
    }
}TS;

void dfs2(int u, bool keep) {
    for(int v : son[u]) if (v != hson[u] ) {
        dfs2(v, 0);
    }
    if (hson[u]) dfs2(hson[u], 1);
    TS.add(u, hson[u]);
    TS.get_ans(u);
    if (!keep) TS.del();
}


int main() {
#ifdef D
    freopen("CodeForces-246E.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    rep(i, 1, n) {
        string s; cin >> s;
        name[i + 1] = get_id(s);
        son[read() + 1].push_back(i + 1);
    }

    m = read();
    rep(i, 1, m) {
        int v = read() + 1, k = read();
        query.push_back((Query){k, 0});
        q[v].push_back(query.size() - 1);
    }

    dfs1(1, 1);
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