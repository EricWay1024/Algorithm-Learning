#include <bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(register int i=(int)from;i<=(int)to;++i)
#define For(i,to) for(register int i=0;i<(int)to;++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
const ll M = 2520;

ll l, r;
ll f[20][50][2521];
int fac[2521];
int dim_l[25]; int dim_l_size;
int dim_r[25]; int dim_r_size;

int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a / gcd(a, b) * b;}

ll dp(int x, int scm, int st, int opl, int opr) {
    if (x == -1) { return (st % scm) == 0; }
    ll &mem = f[x][fac[scm]][st];
    if (!opl && !opr && mem > -1) return mem;
    ll ret = 0;
    int maxx = opr ? dim_r[x] : 9;
    int minx = opl ? dim_l[x] : 0;
    rep(i, minx, maxx) {
        ret += dp(x - 1, (i == 0) ? scm : lcm(i, scm), ((st * 10 + i) % M), 
            (opl & (i == minx)), (opr & (i == maxx)));
    }
    if(!opl && !opr) mem = ret;
    return ret;
}

inline void cal_dim(ll n, int* dim, int &dim_size) {
    dim_size = 0;
    while(n) {
        dim[dim_size++] = n % 10; n /= 10;
    }
}

ll solve(ll l, ll r) {
    memset(dim_l, 0, sizeof(dim_l));
    memset(dim_r, 0, sizeof(dim_r));
    cal_dim(l, dim_l, dim_l_size);
    cal_dim(r, dim_r, dim_r_size);
    memset(f, -1, sizeof(f));
    return dp(dim_r_size-1, 1, 0, 1, 1);
}

int main() {
#ifdef D
    freopen("CF55D.in", "r", stdin);
    double TIMEA = clock();
#endif

    int cnt = 0;
    for(int i = 1; i <= M; ++i) {
        if (M % i == 0) fac[i] = ++cnt;
    }

    int T; T = read();
    while(T--) {
        l = read(); r = read();
        ll ans = solve(l, r);
        cout << ans << "\n";
    }

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}