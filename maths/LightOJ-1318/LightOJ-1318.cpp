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
const int N = 1e5+10;
vector<int> p;
short flag[N];
void init(int n) {
    rep(i,2,n){
        if (!flag[i]) p.push_back(i);
        for(int j : p) {
            if (i*j > n) break;
            flag[i*j] = 1;
            if (i%j == 0) break;
        }
    }
}

int cnt[10000];
void factor(ll x, ll sign) {
    For(i, p.size()) {
        ll t = x;
        while(t) {
            cnt[i] += sign * (t/p[i]);
            t /= p[i];
        }
    }
}
ll quick_pow(ll a, ll b, ll M) {
    ll ans=1; a%=M;
    for(; b; b>>=1, a=a*a%M) if(b&1) ans=a*ans%M;
    return ans;
}

ll binomial(ll n, ll k, ll M) {
    mmst(cnt, 0);
    factor(n, 1);
    factor(k, -1);
    factor(n-k, -1);
    ll ans=1;
    For(i, p.size()) {
        ans = ans * quick_pow(p[i], cnt[i], M) % M;
    }
    return ans;
}

void solve() {
    ll n=read(), k=read(), l=read(), m=read();
    ll ans;
    if (m == 0) {
      ans = quick_pow(k, l, n) + 1;  
    } else {
        // ans = quick_pow(k, l, n) * quick_pow(k-1, m, n) % n * binomial(l, m, n) % n * inv(2, n) % n;
        // ans++; 
        if (k & 1) {
            ans = ((k-1)/2) * quick_pow(k, l, n) % n * quick_pow(k-1, m-1, n) % n * binomial(l, m, n) % n;
        } else {
            ans = (k/2) * quick_pow(k, l-1, n) % n * quick_pow(k-1, m, n) % n * binomial(l, m, n) % n;
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1318.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init(1e5);
    // cout << p.size() << endl;
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