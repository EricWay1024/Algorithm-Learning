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

const int N = 50000+5;
ll mu[N]; bool flg[N]; ll p[N], tot;
void getMu(int n) {
    mu[1] = 1;
    rep(i,2,n) {
        if (!flg[i]) mu[i] = -1, p[++tot]=i;
        for(int j=1; j<=tot && i*p[j]<=n; ++j) {
            flg[i * p[j]] = 1;
            if (i % p[j] == 0) {
                mu[i * p[j]] = 0;
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
}
ll sum_mu[N];
ll f[N];

void init(int n) {
    getMu(n);

    rep(x,1,n){
        ll res=0;
        for(ll l=1, r; l<=x; l=r+1) {
            r=min((ll)x, x/(x/l));
            res+=(r-l+1)*(x/l);
        }
        f[x]=res;

        sum_mu[x] = sum_mu[x-1] + mu[x];
    }
}
int main() {
#ifdef D
    freopen("3327.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init(N-3);
    int T=read();
    while(T--) {
        ll m=read(), n=read();
        if (m>n) swap(m, n);
        ll ans=0;
        for(ll l=1, r; l<=m; l=r+1) {
            ll a=n/l, b=m/l;
            r=min(n/a, m/b); r=min(r, m);
            ans+=f[a] * f[b] * (sum_mu[r] - sum_mu[l-1]);
        }
        cout << ans << endl;
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}