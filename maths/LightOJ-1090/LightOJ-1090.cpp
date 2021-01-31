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
#define N 1123456
ll two[N], five[N];
void init() {
    ll p;
    rep(i,2,N-1){
        p=2;
        while(!(i % p)) two[i]++, p<<=1;
        two[i] += two[i-1];

        p=5;
        while(!(i % p)) five[i]++, p+=(p<<2);
        five[i] += five[i-1];
    }
}
void solve(){
    ll n=read(), r=read(), p=read(), q=read();
    ll t1, f1, t2, f2;
    t1 = two[n] - two[r] - two[n-r];
    f1 = five[n] - five[r] - five[n-r];

    t2 = (two[p]-two[p-1]) * q;
    f2 = (five[p]-five[p-1]) * q;

    cout << min(t1+t2, f1+f2) << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1090.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init();
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}