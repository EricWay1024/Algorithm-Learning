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
#define coutP(i) cout<<fixed<<setprecision(i)
#define endl '\n'
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

ld g0(int K, int n, int n2) {
    if (!n2) {
        return 0;
    }
    ld g = (ld)(n2 - K) / n2 / (n - n2);
    rev(k, K-1, 0) {
        g = (ld)(n2 - k) / (n - k) * (1/(ld)n2 + g);
    }
    return g;
}

void solve() {
    int n=read(), K=read();
    ll st1 = 0; ll st2 = 0;
    int n1 = 0; int n2 = 0;
    rep(i,1,n){
        ll a=read();
        if (a > 0) {
            st1 += a;
            n1++;
        } else {
            st2 -= a;
            n2++;
        }
    }
    if (!n1) {
        puts("-1");
        return;
    }
    ld ans = (ld)st1 / n1 + g0(min(K, n2), n, n2) * (ld) st2;
    coutP(10) << ans << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1395.in", "r", stdin);
    double TIMEA = clock();
#endif
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }



#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}