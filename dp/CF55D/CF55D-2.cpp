#include <bits/stdc++.h>
#include <vector>
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
// 8*9*5*7 = 2520
const ll M = 8*9*5*7;

ll l, r;
ll f[20][260][2520][2];
int dim[20], dim_size;

ll dp(int x, int ch, int st, int op) {
    if (x == -1) {
        rep(i, 2, 9) {
            if (((1 << (i-2)) & ch) && (st % i)) {
                return 0;
            }
        }
        return 1;
    }
    if (f[x][ch][st][op] > -1) return f[x][ch][st][op];
    
    ll ret = 0;
    int maxx = op ? dim[x] : 9;
    rep(i, 0, maxx) {
        int nch = (i>=2) ? (ch | (1<<(i-2))) : ch;
        int nst = ((st * 10 + i) % M);
        int nop = (op & (i == dim[x]));
        ret += dp(x - 1, nch, nst, nop);
    }

    f[x][ch][st][op] = ret;
    return ret;
}


ll solve(ll n) {
    memset(dim, 0, sizeof(dim));
    dim_size = 0;
    while(n) {
        dim[dim_size++] = n % 10;
        n /= 10;
    }
    memset(f, -1, sizeof(f));
    return dp(dim_size-1, 0, 0, 1);
}

int main() {
#ifdef D
    freopen("CF55D.in", "r", stdin);
    double TIMEA = clock();
#endif
    int T; T = read();
    while(T--) {
        l = read(); r = read();
        cout << solve(r) - solve(l - 1) << endl;
    }

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}