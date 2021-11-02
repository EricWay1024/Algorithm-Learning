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
// #include<unordered_map>
#include<utility>
#include<vector>
#include<numeric>
#include<functional>
#include<climits>
#include<iomanip>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
const int N = 4e4 + 100;
const int M = 1e5 + 100;
struct Dis {
    int b[N]; int n; 
    void add(int x) { b[n++] = x; }
    void init() { sort(b, b + n); n = unique(b, b + n) - b; }
    int get(int x) {
        return lower_bound(b, b + n, x) - b + 1;
    }
} dis;

int a[N];

vector<int> son[N]; int fa[N][18], dpth[N];
int tot, st[N], ed[N], eu[N << 1];
int F;
void dfs1(int u) {
    eu[++tot] = u; st[u] = tot;
    for (int v : son[u]) if (v != fa[u][0]) {
        fa[v][0] = u;
        dpth[v] = dpth[u] + 1;
        rep(j, 1, F) fa[v][j] = fa[fa[v][j - 1]][j - 1];
        dfs1(v);
    }
    eu[++tot] = u; ed[u] = tot;
}

int get_lca(int u, int v) {
    if (dpth[u] < dpth[v]) swap(u, v);
    rev(i, F, 0) if (dpth[fa[u][i]] >= dpth[v]) u = fa[u][i];
    if (u == v) return u;
    rev(i, F, 0) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}


struct Query {
    int x, y, l, r, lca, id;
    short type;

    void debug() {
        logs(x, y, l, r, lca, id, type);
        rep(j, l, r) {
            cout << eu[j] << ' ';
        }
        cout << endl;
    }
} q[M];

int B;
bool cmp(const Query &a, const Query &b) {
    return (a.l/B == b.l/B) ? ((a.l/B & 1) ? a.r > b.r : a.r < b.r) : a.l < b.l;
}

int cnt[N];
int col[N];
int ans;
void add(int x) {
    // cout << "add: "; 

    cnt[x]++;
    if (cnt[x] == 2) {
        col[a[x]]--;
        if (col[a[x]] == 0) ans--;
    }
    else if (cnt[x] == 1) {
        if (col[a[x]] == 0) ans++;
        col[a[x]]++;    
    }

    // logs(x, cnt[x], a[x], col[a[x]], ans)
}

void del(int x) {
    // cout << "del: ";

    cnt[x]--;
    if (cnt[x] == 1) {
        if (col[a[x]] == 0) ans++;
        col[a[x]]++;
    } else if (cnt[x] == 0) {
        col[a[x]]--;
        if (col[a[x]] == 0) ans--;
    }

    // logs(x, cnt[x], a[x], col[a[x]], ans)

}

int res[N];

int main() {
#ifdef D
    freopen("SP10707.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n, m;
    n = read(); m = read();
    rep(i, 1, n) a[i] = read(), dis.add(a[i]);
    dis.init();
    rep(i, 1, n) a[i] = dis.get(a[i]);

    rep(i, 1, n - 1) {
        int u = read(), v = read();
        son[u].push_back(v);
        son[v].push_back(u);
    }
    F = log2(n) + 1;
    dpth[1] = 1;
    dfs1(1);

    // rep(i, 1, 2 * n) {
    //     cout << eu[i] << ' ';
    // }
    // cout << endl;

    rep(i, 1, m) {
        int x = read(), y = read();
        if (st[x] > st[y]) swap(x, y);
        int lca = get_lca(x, y);
        q[i].x = x; 
        q[i].y = y;
        q[i].id = i;
        q[i].lca = lca;
        if (lca == x) q[i].l = st[x], q[i].r = st[y], q[i].type = 0;
        else q[i].l = ed[x], q[i].r = st[y], q[i].type = 1;
    }

    B = max(1.0, (db)n / sqrt(m));
    sort(q + 1, q + 1 + m, cmp);

    int l = 1, r = 0;
    rep(i, 1, m) {
        // q[i].debug();

        int &cur = res[q[i].id];
        if (q[i].l == q[i].r) { cur = 1; continue; }
        while (l > q[i].l) add(eu[--l]);
        while (r < q[i].r) add(eu[++r]);
        while (l < q[i].l) del(eu[l++]);
        while (r > q[i].r) del(eu[r--]);
        if (q[i].type) {
            add(q[i].lca);
            cur = ans;
            del(q[i].lca);
        } else cur = ans;
    }

    rep(i, 1, m) {
        printf("%d\n", res[i]);
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}