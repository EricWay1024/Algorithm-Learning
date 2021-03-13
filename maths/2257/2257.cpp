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

const int N = 1e7+7;
short mu[N];
short flg[N];
int p[N], tot;
ll sum[N];

void getMu(int n) {
    mu[1] = 1;
    rep(i,2,n) {
        if (!flg[i]) mu[i] = -1, p[++tot]=i, sum[i]=mu[1];
        for(int j=1; j<=tot && i*p[j]<=n; ++j) {
            flg[i * p[j]] = 1;
            if (i % p[j] == 0) {
                mu[i * p[j]] = 0;
                sum[i * p[j]] = mu[i];
                break;
            } else {
                mu[i * p[j]] = -mu[i];
                sum[i * p[j]] = -sum[i] + mu[i];
            }
        }
    }
}

void init(int n) {
    getMu(n);

    // rep(j,1,tot) {
    //     ll k = p[j];
    //     for(ll d=k; d<=n; d+=k) {
    //         sum[d] += mu[d/k];
    //     }
    // }

    rep(i,1,n){
        sum[i] += sum[i-1];
    }
}
int main() {
#ifdef D
    freopen("2257.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init(N-2);
    int T=read();
    while(T--){
        ll n=read(), m=read();
        if (m > n) swap(m, n);
        ll ans=0;
        for(ll l=1, r; l<=m; l=r+1) {
            r=min(m/(m/l), n/(n/l)); r=min(r, m);
            ans += (m/l) * (n/l) * (sum[r] - sum[l-1]);
        }
        printf("%lld\n", ans);
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}