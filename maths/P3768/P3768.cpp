#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<string>
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
ll MOD;
struct mll {
    ll s;
    mll (ll s=0):s(s) { r(); };
    operator ll() const { return s; }
    void r() { if(MOD) s %= MOD; }
    void fr() { r(); s += MOD; r(); }
    mll operator+ (const mll &b) const { return s+b.s; }
    mll operator- (const mll &b) const { return s-b.s; }
    mll operator* (const mll &b) const { return s*b.s; }
    void operator+= (const mll &b) { s += b.s; r(); }
    void operator-= (const mll &b) { s -= b.s; r(); }
    void operator*= (const mll &b) { s *= b.s; r(); }
    mll quick_pow(ll b) const {
        mll ans=1; mll a=s;
        for(; b; b>>=1) {
            if (b&1) ans *= a;
            a *= a;
        }
        return ans;
    }
    mll operator/ (const mll &b) const { return (mll)s * b.quick_pow(MOD-2); }
    friend ostream& operator<< (ostream &out, const mll &m) {
        mll b=m; b.fr(); out << b.s; return out;
    }
};
const int N = 2e7;
int initN;

struct MyMap {
    mll a[N];
    unordered_map<ll, mll> um;
    mll& operator[] (ll i) {
        return i < initN ? a[i] : um[i];
    }
};

MyMap f;
short flg[N]; int p[N]; int tot;
mll inv6, inv2;
void init(int n) {
    f[1] = 1;
    rep(i,2,n) {
        if (!flg[i]) f[i] = i-1, p[++tot]=i;
        for(int j=1; j<=tot && i*p[j]<=n; ++j) {
            flg[i * p[j]] = 1;
            if (i % p[j] == 0) {
                f[i * p[j]] = mll(p[j]) * f[i];
                break;
            } else {
                f[i * p[j]] = f[p[j]] * f[i];
            }
        }
    }

    rep(i,2,n) {
        f[i] *= mll(i) * mll(i);
        f[i] += f[i-1];
    }
    
    inv6 = mll(1)/mll(6);
    inv2 = mll(1)/mll(2);
}

mll sum_n2(mll n) {
    return n * (n+mll(1)) * (mll(2)*n+mll(1)) * inv6;
}

mll sum_n3(mll n){
    mll t = n * (n+mll(1)) * inv2;
    return t*t;
}

mll sum_f(ll n) {
    if (n < initN || f[n]) return f[n];
    mll ans=0;
    for(ll l=2, r; l<=n; l=r+1){
        r=min(n,n/(n/l));
        ans += sum_f(n/l) * (sum_n2(r)-sum_n2(l-1));
    }
    return f[n] = sum_n3(n) - ans;
}

mll sum_all(ll n) {
    mll ans=0;
    for(ll l=1, r; l<=n; l=r+1) {
        r=min(n,n/(n/l));
        ans += sum_n3(n/l) * (sum_f(r) - sum_f(l-1));
    }
    return ans;
}

int main() {
#ifdef D
    freopen("P3768.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    MOD=read(); ll n=read();
    initN = min((int)pow(n, 0.75), N-1);
    init(initN);
    cout << sum_all(n) << endl;

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}