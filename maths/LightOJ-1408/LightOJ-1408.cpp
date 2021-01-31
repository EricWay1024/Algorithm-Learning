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
#define N 60
// ld f[N][N];
int n,m; ld p, q;
// ld dp(int i, int j) {
//     if (i == m || j == n) return 0;
//     if (f[i][j] > 0) return f[i][j];
//     logs(i, j)
//     return f[i][j] = 1 + p * dp(i + 1, 0) + q * dp(0, j + 1);
// }

#define eps 1e-10
void solve(){
    cin>>p; q=1-p;
    n=read(), m=read();
    if(p<eps){ coutP(10) << (ld)n << endl; return;}
    if(q<eps){ coutP(10) << ld(m) << endl; return;}
    ld a1=1-pow(p,m-1), b1=a1/q;
    ld a2=1-pow(q,n-1), b2=a2/p;
    ld f1=(a1*b2+b1)/(1-a1*a2);
    ld g1=a2*f1+b2;
    ld ans=1+p*f1+q*g1;
    coutP(10)<<ans<<endl;
}


int main() {
#ifdef D
    freopen("LightOJ-1408.in", "r", stdin);
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