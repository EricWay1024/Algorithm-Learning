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
#ifdef D
    void dbg() {cout << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
    #define logs(x...) {cout << #x << " -> "; dbg(x);}
#else
    template<typename T, typename... Args> void logs(T t, Args... args) {};
#endif
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

int n; 
db a[100];
db f(db x) {
    db ans = a[n];
    rev(i,n-1,0) {
        ans *= x;
        ans += a[i];
    }
    return ans;
}

const db eps = 1e-6;
db bisection(db l, db r) {
    while (r - l > eps) {
        db m = (l + r) / 2;
        if (f(m + eps) >= f(m - eps)) l = m;
        else r = m;
    }
    return l;
}
int main() {
#ifdef D
    freopen("P3382.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    db l, r;
    cin >> n;
    cin >> l >> r;
    rev(i,n,0) cin >> a[i];
    // logs(1, f(1))
    coutP(5) << bisection(l, r) << endl;

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}