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
// #include<unordered_map>
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
const int M = 201000;

// array index starts from zero
namespace a {
    int f[M];
    int m;
    char P[M];
    void getFail()
    {
        f[0] = f[1] = 0;
        rep(i, 1, m - 1)
        {
            int j = f[i];
            while (j && P[i] != P[j])
                j = f[j];
            f[i + 1] = P[i] == P[j] ? j + 1 : 0;
        }
    }
}
using namespace a;

int main() {
#ifdef D
    freopen("HDU-3336.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read();
    while(T--) {
        m = read();
        scanf("%s", P);
        getFail();
        // rep(i, 0, m){
        //     logs(i, f[i])
        // }
        int ans = 0;
        rep(i, 0, m) {
            for(int j=i; j; j=f[j]) ans = (ans+1)%10007;
        }
        cout << ans << endl;
    }



#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}