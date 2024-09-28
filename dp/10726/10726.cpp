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
    void dbg() {cerr << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cerr << a << ' '; dbg(x...);}
    #define logs(x...) {cerr << #x << " -> "; dbg(x);}
#else
    #define logs(...) {}
#endif
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll; typedef long double ld; typedef double db;
typedef pair<ll,ll> pll; typedef pair<int,int> pii; typedef vector<ll> vll; typedef vector<int> vint;
template <typename T> vector<T>& operator<< (vector<T> &v, T &x) { v.emplace_back(x); return v; }
struct MyIn { 
    template <typename T> MyIn& operator>> (T &x) { x=0;bool s=0;char c=getchar();while(c>'9'||c<'0'){if(c=='-')s=1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}if(s)x=-x;return (*this); } 
} rin;
const int N2 = 112; const int N3 = 1123; const int N4 = 11234; const int N5 = 112345; const int N6 = 1123456; const int N7 = 11234567;
int n, s, t;

struct Nd {
    int h, l, r, i;

    bool operator< (const Nd& b) {
        return (h > b.h) || (h == b.h && l < b.l);
    }

    bool contains(int k) {
        return l <= k && k <= r;
    }
} x[N3];

ll mem[N3][2];

int main() {
#ifdef D
    freopen("10726.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    cin >> n >> s >> t;
    rep(i,1,n) {
        cin >> x[i].l >> x[i].r >> x[i].h;
        x[i].i = i;
    }

    sort(x + 1, x + 1 + n);

    mmst(mem, 0x7f);

    int INF = mem[0][0];

    int u, v;
    rep(i,1,n) {
        if (x[i].i == s) u = i;
        if (x[i].i == t) v = i;
    }

    mem[u][0] = 0;
    mem[u][1] = x[u].r - x[u].l;

    ll ans = INF;
    rep(j, u, v - 1) { // we jump from j to i
        rep(i, j + 1, v) { // j is higher than i
            if (x[j].h == x[i].h) continue; // in case they equal

            if (x[i].contains(x[j].l) && mem[j][0] != INF) {
                mem[i][0] = min(mem[i][0], mem[j][0] + x[j].h - x[i].h + abs(x[j].l - x[i].l));
                mem[i][1] = min(mem[i][1], mem[j][0] + x[j].h - x[i].h + abs(x[j].l - x[i].r));

                if (i == v) {
                    ans = min(ans, mem[j][0] + x[j].h - x[i].h);
                }

                break;
            }
        }

        rep(i, j + 1, v) { // j is higher than i
            if (x[j].h == x[i].h) continue; // in case they equal

            if (x[i].contains(x[j].r) && mem[j][1] != INF) {
                mem[i][0] = min(mem[i][0], mem[j][1] + x[j].h - x[i].h + abs(x[j].r - x[i].l));
                mem[i][1] = min(mem[i][1], mem[j][1] + x[j].h - x[i].h + abs(x[j].r - x[i].r));

                if (i == v) {
                    ans = min(ans, mem[j][1] + x[j].h - x[i].h);
                }

                break;
            }
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }


#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}