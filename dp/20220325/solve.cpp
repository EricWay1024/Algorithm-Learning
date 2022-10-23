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

const int N = 3e4 + 999;
ll a[N], w[N], s[N];

ll q[N];
ll f[N];


db yy(int j) {
    return f[j];
}

db xx(int j) {
    return s[j];
}

db slope(int j1, int j2) {
    db ans = (yy(j1) - yy(j2)) / (xx(j1) - xx(j2));
    return ans;
}


int main() {
#ifdef D
    freopen("in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    ll n; rin >> n;
    rep(i,1,n) {
        rin >> a[i] >> w[i];
        s[i] = a[i] + s[i - 1];
    }

    // mmst(f, 0x7f);

    f[0] = 0;

    ll l = 1, r = 1;
    q[1] = 0;
    rep(i,1,n) {
        while(l<r && slope(q[l], q[l+1]) < (double)w[i]) l++;

        logs(slope(q[l], q[l+1]), w[i])

        f[i] = f[q[l]] - (-s[i] * w[i] - s[n] + s[i]);
        logs(i, q[l])
        while(l<r && slope(q[r-1], i) < slope(q[r-1], q[r])) r--;
        q[++r] = i;
    }

    // rep(i,1,n) {
    //     int ans = i - 1;
    //     rep(j,0,i-1) {
    //         if (f[j] + (s[i] - s[j]) * w[i] + s[n] - s[i] <  f[ans] + (s[i] - s[ans]) * w[i] + s[n] - s[i]) {
    //             ans = j;
    //         }
    //     }
    //     f[i] = f[ans] + (s[i] - s[ans]) * w[i] + s[n] - s[i];
    //     logs(i, ans)
    // }

    cout << f[n] << endl;



#ifdef D
    float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
    if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
#endif
    return 0;
}