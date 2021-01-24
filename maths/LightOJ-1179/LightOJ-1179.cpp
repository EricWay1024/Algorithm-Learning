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
// #define N 112345
// bool dead[N];
// int getNextAlive(int cur, int n) {
//     cur = (cur < n ? cur+1 : 1);
//     while(dead[cur]) cur = (cur < n ? cur+1 : 1);
//     return cur;
// }
// int simulate(int n, int k) {
//     int cur = 0;
//     For(_, n-1) {
//         For(__, k) cur = getNextAlive(cur, n);
//         dead[cur] = 1;
//     }
//     rep(i, 1, n) {
//         if (!dead[i]) return i;
//     }
//     return -1;
// }

int solve(int n, int k) {
    if (n == 1) return 1;
    else return (solve(n-1, k)+k-1)%n+1;
}


int main() {
#ifdef D
    freopen("LightOJ-1179.in", "r", stdin);
    double TIMEA = clock();
#endif
    // rep(n, 3, 10) {
    //     rep(k, 1, 100) {
    //         mmst(dead, 0);
    //         printf("n=%d, k=%d: %d\n", n, k, simulate(n, k));
    //     }
    //     putchar(10);
    // }
    int T=read();
    rep(i, 1, T) {
        int n=read(), k=read();
        printf("Case %d: %lld\n", i, solve(n, k));
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}