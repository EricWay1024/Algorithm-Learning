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
ll n;
ll a[100100];
ll k;

bool check(ll t) {
    ll sum = 0;
    rep(i,1,n){
        if (a[i] <= t) continue;
        sum += (ll)ceil((ld)(a[i]-t) / (ld)(k-1));
        if (sum > t) return 0;
    }
    return 1;
}


int main() {
#ifdef D
    freopen("POJ-3104.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    n=read();
    ll l=1, r=1;
    rep(i,1,n) a[i]=read(), r=max(r, a[i]);
    k=read();
    if (k == 1) {
        cout << r << endl;
        return 0;
    }
    ll ans=r;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}