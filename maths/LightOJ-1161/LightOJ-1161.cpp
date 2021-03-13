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
void init() {

}

int n;
const int N = 1e4+10;
ll dc[N];
void factor(int k) {
    rep(i,1,sqrt(k)){
        if (k % i == 0) {
            dc[i]++;  
            if (k != i * i) dc[k/i]++;
        }
    }
}

ll choose_4(ll k) {
    return k*(k-1)*(k-2)*(k-3)/24;
}

ll ans[N];
void solve() {
    mmst(dc, 0); mmst(ans, 0);
    n=read();
    ll maxk = 0;
    rep(i,1,n){
        ll k=read();
        factor(k);
        maxk = max(maxk, k);
    }
    rev(i, maxk, 1) {
        ans[i] = choose_4(dc[i]);
        rep(j, 2, maxk/i){
            ans[i] -= ans[i * j];
        }
    }
    cout << ans[1] << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1161.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init();
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}