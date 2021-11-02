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
ll n, m;
ll f(ll i, ll j) {
    return i*i + 100000 * i + j*j - 100000 * j + i * j;
}

ll cnt(ll x) {
    // return # of numbers <= x in the matrix
    ll sum=0;
    rep(j,1,n){
        ll l=1, r=n; ll ans=0;
        while(l <= r) {
            ll mid = (l+r)/2;
            if (f(mid, j) <= x) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        sum += ans;
    }
    return sum;
}
int main() {
#ifdef D
    freopen("POJ-3685.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read();
    while(T--){
        n=read(), m=read();
        ll l=-1e18, r=1e18; ll ans;
        while(l <= r) {
            ll mid = l+(r-l)/2; // important
            if (cnt(mid) >= m) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << endl;
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}