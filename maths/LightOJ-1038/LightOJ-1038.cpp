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
#define N 512345
ld f[N];
ld solve(int n){
    if (n==1) return 0;
    if (f[n] > 0) return f[n];
    int cnt = 2;
    ld ans = 0;
    for(int i=2; i*i<=n; i++) {
        if (!(n % i)) {
            if (i*i==n) {
                cnt += 1;
                ans += solve(i);
            } else {
                cnt += 2;
                ans += solve(i) + solve(n / i);
            }
        }
    }
    return f[n] = (ans+cnt)/(cnt-1);
}

int main() {
#ifdef D
    freopen("LightOJ-1038.in", "r", stdin);
    double TIMEA = clock();
#endif
    int T=read();
    rep(i,1,T){
        printCase(i);
        ld ans = solve(read());
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}