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
inline int read(){
    int x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

const int N = 5e4+100;
short mu[N];
short flg[N];
int p[N], tot;
ll sum[N];

void getMu(int n) {
    mu[1] = 1;
    rep(i,2,n) {
        if (!flg[i]) mu[i] = -1, p[++tot]=i;
        for(int j=1; j<=tot && i*p[j]<=n; ++j) {
            flg[i * p[j]] = 1;
            if (i % p[j] == 0) {
                mu[i * p[j]] = 0;
                break;
            } else {
                mu[i * p[j]] = -mu[i];
            }
        }
    }
}

void init(int n) {
    getMu(n);
    rep(i,1,n){
        sum[i] = sum[i-1] + mu[i];
    }
}

ll solve(ll m, ll n, ll k) {
    if (m > n) swap(m, n);
    m/=k, n/=k;
    ll ans=0;
    for(ll l=1, r; l<=m; l=r+1) {
        r=min(m/(m/l), n/(n/l)); r=min(r, m);
        ans += (m/l) * (n/l) * (sum[r] - sum[l-1]);
    }
    return ans;
}
int main() {
#ifdef D
    freopen("2522.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init(N-2);
    int T=read();
    while(T--){
        ll a=read(), b=read(), c=read(), d=read(), k=read();
        ll ans=0;
        ans += solve(b, d, k);
        ans -= solve(b, c-1, k);
        ans -= solve(a-1, d, k);
        ans += solve(a-1, c-1, k);
        printf("%lld\n", ans);
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}