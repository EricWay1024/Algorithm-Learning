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
typedef int ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
#define N 100005
int n;
ll x[N];
ll cnt(ll d) {
    ll res = 0;
    rep(i,1,n) {
        ll l=i, r=n; ll ans;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if (x[mid] - x[i] <= d) ans = mid, l = mid+1;
            else r = mid - 1;
        }
        res += ans - i;
    }
    return res;
}

int main() {
#ifdef D
    freopen("POJ-3579.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    while(~scanf("%d", &n)) {
        rep(i,1,n) x[i] = read();
        sort(x+1, x+1+n);
        ll mth = ((1ll*n*(n-1) / 2) + 1) / 2;
        ll l=0, r=1e9;
        while(l < r) {
            ll mid = (l + r) >> 1;
            if (cnt(mid) >= mth) r = mid;
            else l = mid + 1;
        }
        printf("%lld\n", l);
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}