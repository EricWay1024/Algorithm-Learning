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
const int N = 1e6+10;
int mu[N], flag[N], prime[N/10], tot;
void init(int n) {
    mu[1]=1;
    rep(i,2,n){
        if (!flag[i]) prime[++tot]=i, mu[i]=-1;
        rep(j,1,tot){
            if(prime[j]>n/i) break;
            int m = i * prime[j];
            flag[m] = 1;
            if (i % prime[j] != 0) {
                mu[m] = -mu[i];
            } else {
                mu[m] = 0;
                break;
            }
        }
    }
    rep(i,1,n) mu[i] += mu[i-1];
}

ll solve() {
    ll n=read(), m=read();
    if (m > n) swap(m, n);
    if (m == 0 && n == 0) {
        return 0;
    } else if (m == 0) {
        return 1;
    }

    ll ans=2;
    for(ll l=1, r; l<=m; l=r+1){
        r=min(m/(m/l), n/(n/l)); r=min(r, m);
        ans += (0ll + mu[r] - mu[l-1]) * (m/l) * (n/l);
    }
    return ans;
}

int main() {
#ifdef D
    freopen("LightOJ-1144.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init(N-1);
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        cout << solve() << endl;
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}