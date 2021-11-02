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

bool check(int n) {
    int a=1, b=1;
    while(a > 0) {
        if (a == n) return 1;
        a += b;
        swap(a, b);
    }
    return 0;
}
// int mem[1000][1000];
// int solve(int n, int limit) {
//     if (n == 0) return 0;
//     if (mem[n][limit] > -1) return mem[n][limit];
//     rep(i,1,limit) {
//         if (!solve(n-i, i*2)) return mem[n][limit]=1;
//     }
//     return mem[n][limit]=0;
// }


int main() {
#ifdef D
    freopen("HDU-2516.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    while(1) {
        int n=read(); if (!n) break;
        cout << (check(n) ? "Second win" : "First win") << endl;
    }
    // mmst(mem, -1);
    // rep(i,1,100) {
    //     cout << i << " " << solve(i, i-1) << endl;
    // }




#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}