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
const ll M = 1e9;
ll quick_pow(ll a, ll b) {
    ll ans=1; a%=M;
    for(; b; b>>=1, a=a*a%M) if(b&1) ans=a*ans%M;
    return ans;
}

map< ll, vector<ll> > pt;
void solve() {
    ll m=read(), n=read(), k=read(), b=read();
    pt.clear();
    For(_, b) {
        ll x=read(), y=read();
        pt[y].push_back(x);
    }
    ll ans=1;
    for(auto &p : pt) {
        vector<ll> &xs = p.second;
        xs.push_back(0); 
        xs.push_back(m+1);
        sort(xs.begin(), xs.end());
        For(i, xs.size() - 1) {
            ll len = xs[i+1] - xs[i] - 1;
            if (!len) continue;
            ans = ans * k % M * quick_pow(k-1, len-1) % M;
        }
    }
    ll free = n - pt.size();
    ans = ans * quick_pow(k * quick_pow(k-1, m-1) % M, free) % M;
    cout << ans << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1333.in", "r", stdin);
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