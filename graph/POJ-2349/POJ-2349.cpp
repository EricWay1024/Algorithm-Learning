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
#endif
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vll;
typedef vector<int> vint;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
ll s, p;

ll dst(pii &a, pii &b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

vector<pii> pts;

ll d[512], v[512];
void prim() {
    mmst(d, 0x3f);
    mmst(v, 0);
    d[0] = 0;
    For(i, p) {
        int x = -1;
        For(j, pts.size()) {
            if (!v[j] && (x == -1 || d[j] < d[x])) x = j;
        }
        v[x] = 1;
        For(y, pts.size()) {
            if (!v[y]) d[y] = min(d[y], dst(pts[x], pts[y]));
        }
    }

    sort(d, d + p);
    coutP(2) << sqrt((db)d[p - s]) << endl;

}

int main() {
#ifdef D
    freopen("POJ-2349.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    ll T = read();
    while (T--) {
        s = read(); p = read();
        pts.clear();
        rep(i,1,p) {
            ll x = read(), y = read();
            pts.push_back(make_pair(x, y));
        }
        prim();
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}