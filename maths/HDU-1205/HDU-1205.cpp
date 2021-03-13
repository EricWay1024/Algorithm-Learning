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

// int a[100];
// int n;
// int dfs(int s) {
//     ll sum=0;
//     rep(i,1,n) sum+=a[i];
//     if (!sum) return 1;

//     rep(i,1,n) if (i!=s && a[i]>0) {
//         a[i]--;
//         int res = dfs(i);
//         a[i]++;
//         if (res) return 1;
//     }
//     return 0;
// }   


int main() {
#ifdef D
    freopen("HDU-1205.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    // n=3;
    // rep(x,1,20){
    //     rep(y,1,x){
    //         rep(z,1,y){
    //             a[1]=x, a[2]=y, a[3]=z;
    //             logs(x, y, z, dfs(-1));
    //         }
    //     }
    // }
    int T=read();
    ll mx, sm, n, a;
    while(T--){
        mx=0, sm=0;
        n=read();
        while(n--){
            a=read();
            mx=max(mx, a);
            sm+=a;
        }
        if (mx > sm-mx+1) puts("No");
        else puts("Yes");
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}