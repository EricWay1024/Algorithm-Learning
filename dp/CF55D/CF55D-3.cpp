#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define rep(i,from,to) for(int i=(int)from;i<=(int)to;++i)
#define For(i,to) for(int i=0;i<(int)to;++i)
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
ll f[20][4][3][2][2][2520][2];
int dim[25], dim_size;

int my_pow[8][4];
int order[10][10];

void init() {
    For(i, 8) my_pow[i][0] = 1;
    rep(i, 2, 7) {
        rep(j, 1, 3) {
            my_pow[i][j] = my_pow[i][j - 1] * i;
        }
    }
    order[2][2] = order[3][3] = order[5][5] = order[7][7] = 1;
    order[4][2] = order[9][3] = 2;
    order[6][2] = order[6][3] = 1;
    order[8][2] = 3;
}


ll dp(int x, int two, int three, int five, int seven, int st, int op) {
    if (x == -1) {
        if (st % my_pow[2][two]) return 0;
        if (st % my_pow[3][three]) return 0;
        if (st % my_pow[5][five]) return 0;
        if (st % my_pow[7][seven]) return 0;
        return 1;
    }
    ll &mem = f[x][two][three][five][seven][st][op];
    if (mem > -1) return mem;
    
    ll ret = 0;
    int maxx = op ? dim[x] : 9;
    rep(i, 0, maxx) {
        int nst = ((st * 10 + i) % M);
        int nop = (op & (i == dim[x]));

        ret += dp(x - 1, 
            max(two, order[i][2]), 
            max(three, order[i][3]),
            max(five, order[i][5]),
            max(seven, order[i][7]),
            nst, nop);
    }

    mem = ret;
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
    return dp(dim_size-1, 0, 0, 0, 0, 0, 1);
}

void output(ll n) {
    memset(dim, 0, sizeof(dim));
    dim_size = 0;
    while(n) {
        dim[dim_size++] = n % 10;
        n /= 10;
    }
    for(int i = dim_size - 1; i >= 0; i--){
        putchar(dim[i] + '0');
    }
    putchar('\n');
}

int main() {
#ifdef D
    freopen("CF55D.in", "r", stdin);
    double TIMEA = clock();
#endif
    init();
    int T; T = read();
    while(T--) {
        l = read(); r = read();
        ll ans = solve(r) - solve(l - 1);
        output(ans);
    }

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}