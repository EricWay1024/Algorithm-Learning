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
ll a[20]; int n, m;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll cnt(ll s) {
    // with set s, return # of k's where 1<=k<=n and k is divisible by all numbers in s
    ll t = 1;
    ll sign = 1;
    For(j, m) {
        int i = (1<<j);
        if (i & s) {
            t = lcm(t, a[j]);
            sign = -sign;
        }
        if (t > n) return 0;
    }
    return (n/t) * sign;
}

int main() {
#ifdef D
    freopen("UVA-10325.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    while(~scanf("%d%d", &n, &m)) {
        For(i,m) a[i]=read();
        ll res = 0;
        For(s, 1<<m) {
            res += cnt(s);
        }
        printf("%lld\n", res);
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}