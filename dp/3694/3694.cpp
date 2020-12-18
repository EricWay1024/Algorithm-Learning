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

const int N = 112345;
int n, m;
int a[N], pres[25][N], mc[25];
int f[(1<<22)+100];


int dfs(int s, int pos) {
    // pos can be derived from s, but we pass it for convenience
    if (s == ((1 << (m + 1)) - 2)) { return 0; }

    if (f[s] > -1) return f[s];

    int ret = N;
    rep(i, 1, m) {
        if ((s >> i) & 1) continue;
        // we are going to make all [pos+1, pos+mc[i]] be group i
        int r = pos + mc[i];
        // count how many people need to be changed
        ret = min(ret, dfs(s | (1 << i), r) + (pres[i][r] - pres[i][pos]));
    }

    return f[s] = ret;
}

int main() {
#ifdef D
    freopen("3694.in", "r", stdin);
#endif
    n = read(); m = read();
    memset(f, -1, sizeof(f));

    rep(i, 1, n) a[i] = read(), mc[a[i]]++;
    rep(j, 1, m) {
        rep(i, 1, n) {
            pres[j][i] = pres[j][i-1] + (a[i] != j);
        }       
    }
    cout << dfs(0, 0) << endl;

    return 0;
}