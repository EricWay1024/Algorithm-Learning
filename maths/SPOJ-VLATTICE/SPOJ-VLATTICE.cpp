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
const int N=1000100;
ll mu[N]; short flag[N]; int p[N], tot;
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

    rep(i,1,n){
        mu[i] += mu[i-1];
    }
}

ll solve(ll n) {
    ll ans=3;
    for(ll l=1, r; l<=n; l=r+1) {
        ll a=n/l;
        r = min(n, n/a);
        ans += (mu[r]-mu[l-1]) * ((a+3)*(a*a));
    }
    return ans;
}

ll in_data[100];
int main() {
#ifdef D
    freopen("SPOJ-VLATTICE.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read(); 
    ll max_n=0;
    rep(i,1,T) in_data[i]=read(), max_n = max(max_n, in_data[i]);
    getMu(max_n);
    rep(i,1,T){
        cout << solve(in_data[i]) << endl;
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}