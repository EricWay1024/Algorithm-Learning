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
#include<unordered_map>
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
const int N = 1e6;
struct MyMap {
    ll a[N];
    unordered_map<int, ll> um;
    ll& operator[] (int i) {
        return i < N ? a[i] : um[i];
    }
};

MyMap mu, phi;
short flg[N]; int p[N], tot;
void seive(int n) {
    mu[1] = 1;
    phi[1] = 1;
    rep(i,2,n) {
        if (!flg[i]) mu[i] = -1, phi[i] = i-1, p[++tot]=i;
        for(int j=1; j<=tot && i*p[j]<=n; ++j) {
            flg[i * p[j]] = 1;
            if (i % p[j]) {
                mu[i * p[j]] = -mu[i];
                phi[i * p[j]] = phi[i] * phi[p[j]];
            } else {
                mu[i * p[j]] = 0;
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
        }
    }

    rep(i,1,n) {
        mu[i] += mu[i-1];
        phi[i] += phi[i-1];
    }
}

ll sumMu(ll n) {
    if (n < N || mu[n]) return mu[n];
    ll s=0;
    for(ll l=2, r; l<=n; l=r+1) {
        r = min(n, n/(n/l));
        s += (r-l+1) * sumMu(n/l);
    }
    return mu[n]=1-s;
}

ll sumPhi(ll n) {
    if (n < N || phi[n]) return phi[n];
    ll s=0;
    for(ll l=2, r; l<=n; l=r+1) {
        r = min(n, n/(n/l));
        s += (r-l+1) * sumPhi(n/l);
    }
    return phi[n]=(n*(n+1)/2)-s;
}


int main() {
#ifdef D
    freopen("P4213.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    seive(N-1);
    int T=read();
    while(T--){
        ll n=read();
        printf("%lld %lld\n", sumPhi(n), sumMu(n));
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}