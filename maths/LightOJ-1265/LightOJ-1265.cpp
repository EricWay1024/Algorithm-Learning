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
ld choose(int n, int k){
    //for k=0,1,2
    if (k > n) return 0;
    if (k == 0) return 1;
    if (k == 1) return n;
    return (ld)n*(n-1)/2;
}
#define N 1024
// ld f[N][N];
// ld solve(int t, int d){
//     if (t & 1) return 0;
//     if (t == 0) return 1;
//     if (f[t][d] > 0) return f[t][d];
//     if (d == 0) {
//         return solve(t-2, 0) * choose(t, 2) / choose(t + 1, 2);
//     }

//     int n=t+d+1;

//     ld ans = 0;
    
//     ans += solve(t-2, d) * choose(t, 2) / choose(n, 2);
//     ans += solve(t, d-1) * choose(t, 1) * choose(d, 1) / choose(n, 2);
    
//     ld ans1 = ans, ans2 = ans;

//     ans1 += solve(t, d-1) * choose(d, 1) * choose(1, 1) / choose(n, 2);
//     ans1 = ans1 / (1 - choose(d, 2) / choose(n, 2));

//     ans2 = ans2 / (1 - choose(d, 1) / choose(n, 2) - choose(d, 2) / choose(n, 2));

//     return f[t][d] = max(ans1, ans2);
// }

ld f[N];
ld solve(int t) {
    if (t & 1) return 0;
    if (t == 0) return 1;
    if (f[t] > 0) return f[t];
    return f[t] = solve(t-2) * choose(t, 2) / choose(t + 1, 2);
}

int main() {
#ifdef D
    freopen("LightOJ-1265.in", "r", stdin);
    double TIMEA = clock();
#endif
    int T=read();
    rep(i,1,T){
        printCase(i);
        int t=read(), d=read();
        coutP(10)<<solve(t)<<endl;
    }

    // rep(t,1,30){
    //     rep(d,1,10){
    //         cout<<t<<" "<<d<<" "<<solve(t, d)<<endl;
    //     }
    // }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}