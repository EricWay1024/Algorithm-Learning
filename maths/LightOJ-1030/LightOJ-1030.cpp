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
#define printCase(i) printf("Case %d: ", i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
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
const int N = 124;
int w[N];
ld dp[N];
void solve(){
    int n=read();
    rep(i,1,n) w[i]=read();
    mmst(dp, 0);
    dp[n]=w[n];
    rev(i, n-1, 1) {
        int s=i+1, t=min(i+6,n), len=t-s+1;
        ld avg=0;
        rep(j,s,t) avg+=dp[j];
        avg/=len;
        dp[i]=w[i]+avg;
    }
    cout<<fixed<<setprecision(10)<<dp[1]<<endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1030.in", "r", stdin);
    double TIMEA = clock();
#endif
    int t=read();
    rep(i,1,t) {
        printCase(i);
        solve();
    }
#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}