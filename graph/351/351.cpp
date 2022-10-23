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
#ifdef D
    void dbg() {cout << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
    #define logs(x...) {cout << #x << " -> "; dbg(x);}
#else
    template<typename T, typename... Args> void logs(T t, Args... args) {};
#endif
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

const ll M = (1ll<<31)-1;
const ll N = 1023;
ll G[N][N];
ll n, m;
ll d[N], v[N];
vector< pair<ll, ll> > ps;

void dijkstra() {
    mmst(d, 0x3f);
    mmst(v, 0);
    d[1] = 0;
    rep(i,1,n-1) {
        int x = 0;
        rep(j,1,n) {
            if (!v[j] && (x == 0 || d[j] < d[x])) x = j;
        }
        v[x] = 1;
        rep(y,1,n) d[y] = min(d[y], d[x] + G[x][y]);
    }
}


int main() {
#ifdef D
    freopen("351.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    cin >> n >> m;
    mmst(G, 0x3f);
    rep(i,1,m) {
        ll u = read(), v = read(), w = read();
        G[u][v] = G[v][u] = w;
    }
    dijkstra();
    rep(i,1,n) ps.emplace_back(make_pair(d[i], i));
    sort(ps.begin(), ps.end());

    ll ans = 1;
    For(i, ps.size()) {
        ll du = ps[i].first;
        ll u = ps[i].second;
        if (u == 1) continue;

        ll cnt = 0;
        For(j, i) {
            ll dx = ps[j].first;
            ll x = ps[j].second;
            if (du == dx + G[x][u]) cnt++;
        }

        ans = ans * cnt % M;
    }

    cout << ans << endl;


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}