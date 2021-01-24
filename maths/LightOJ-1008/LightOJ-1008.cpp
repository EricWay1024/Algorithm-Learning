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
pair<ll, ll> solve(ll s){
    ll k=ceil(sqrt(s));
    ll u=k*k, v=(k-1)*(k-1)+1, m=(u+v)/2;
    // logs(k)
    if(k&1){
        if(s==m){
            return make_pair(k, k);
        } else if (s < m) {
            return make_pair(k, s-v+1);
        } else {
            return make_pair(u-s+1, k);
        }
    } else {
        if(s==m){
            return make_pair(k, k);
        } else if (s > m) {
            return make_pair(k, u-s+1);
        } else {
            return make_pair(s-v+1, k);
        }

    }
}

int main() {
#ifdef D
    freopen("LightOJ-1008.in", "r", stdin);
    double TIMEA = clock();
#endif
    int T=read();
    rep(I, 1, T){
        auto p = solve(read());
        ll x, y; tie(x, y) = p;
        cout << "Case " << I << ": " <<  x << " " << y << "\n";
    }
#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}