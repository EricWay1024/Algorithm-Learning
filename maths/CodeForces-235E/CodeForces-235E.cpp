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
#include<unordered_map>
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

const int N=2003;
const int M=(1<<30);
const int msk=M-1;
short mu[N], flag[N]; int p[N], tot;
void getMu(int n) {
    mu[1]=1;
    rep(i,2,n){
        if(!flag[i]) p[++tot]=i, mu[i]=-1;
        for(int j=1; j<=tot && p[j]<=n/i; ++j){
            int m=i*p[j];
            flag[m]=1;
            if(i%p[j] == 0) {
                mu[m] = 0;
                break;
            } else {
                mu[m] = mu[i] * mu[p[j]];
            }
        }
    }
}


ll gcd[N][N];
ll get_gcd(ll a, ll b) {
    if (b > a) swap(a, b);
    if (gcd[a][b]) return gcd[a][b];
    return gcd[a][b] = (b ? get_gcd(a%b, b) : a);
}

ll f(ll n, ll d, ll r) {
    ll ans=0;
    rep(t,1,n) {
        if (get_gcd(t * d, r) == 1) ans += (n / t);
        ans &= msk;
    }
    return ans;
}


int main() {
#ifdef D
    freopen("CodeForces-235E.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    getMu(N-1);
    ll a=read(), b=read(), c=read();
    ll ans=0;
    rep(d,1,min(a,b)){
        if (!mu[d]) continue;
        ll tmp=0;
        rep(r,1,c){
            tmp += ((((c/r) * f(a/d, d, r))&msk) * f(b/d, d, r))&msk;
            tmp &= msk;
        }
        ans += (tmp * mu[d])%M;
        ans %= M;
    }
    ans += M; ans &= msk;
    cout << ans << endl;


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}