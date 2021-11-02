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
ld calc(int i, int x) {
    return (ld)1-(ld)((i-1)*(i-1)+(x-i)*(x-i))/(ld)(x*x);
}

ld quick_pow(ld a, int b) {
    ld ans = 1;
    for(; b; b >>= 1) {
        if (b & 1) ans *= a;
        a *= a;
    }
    return ans;
}

ld f(int i, int j, int k, int x, int y, int z, int n) {
    ld p = calc(i, x) * calc(j, y) * calc(k, z);
    return (1.0-quick_pow(1.0-2.0*p, n))/2.0;
}

int main() {
#ifdef D
    freopen("LightOJ-1284.in", "r", stdin);
    double TIMEA = clock();
#endif
    int t=read();
    rep(I,1,t){
        printCase(I);
        int x=read(), y=read(), z=read(), n=read();
        ld ans=0;
        rep(i,1,x){
            rep(j,1,y){
                rep(k,1,z){
                    ans += f(i,j,k,x,y,z,n);
                }
            }
        }
        coutP(10)<<ans<<endl;
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}