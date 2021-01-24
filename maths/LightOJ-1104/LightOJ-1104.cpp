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

const int N=1e5+1122;
ld lgfac[N];
void init() {
    lgfac[0]=lgfac[1]=0;
    rep(i,2,1e5+7){
        lgfac[i]=lgfac[i-1]+log(i);
    }
}
ld f(int n, int k){
    return lgfac[n] - lgfac[n-k] - k * log(n) + log(2);
}
int solve(int n){
    if (n<=2) return 1;
    int l=2, r=min(n,380); int ans=r;
    while(l<=r){
        int k=(l+r)>>1;
        if (f(n, k) < 0) ans = k, r = k - 1;
        else l = k + 1;
    }
    return ans-1;
}

int main() {
#ifdef D
    freopen("LightOJ-1104.in", "r", stdin);
    double TIMEA = clock();
#endif
    init();
    // cout << solve(1e5) << endl;
    int t=read();
    rep(i,1,t){
        printCase(i);
        printf("%d\n", solve(read()));
    }
#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}