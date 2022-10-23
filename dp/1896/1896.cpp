#include <bits/stdc++.h>
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

ll f[10][100][1024];

int count_one(int x) {
    int ans = 0;
    while(x) ans += (x & 1), x >>= 1; 
    return ans;
}

bool check_row(int s) {
    // we don't want consecutive ones in s
    return !(s & (s << 1));
}

bool check_rows(int s1, int s2) {
    return !(s1 & s2) && !(s1 & (s2 << 1)) && !((s1 << 1) & s2);
}

ll dp(int x, int r, int st, int n) {
    // we are considering x-th row, we still have r kings need to locate, 
    // and the (x-1)-th row has state st, a binary number representing all the king's locations
    if (x == n) return r == 0;
    if (r == 0) return 1;

    ll &mem = f[x][r][st];
    if (mem > -1) return mem;
    ll ret = 0;

    // we are going to enumerate all states of row x
    for(int s = 0; s < (1 << n); s++) {
        int cnt = count_one(s);
        if (cnt > r) continue;
        if (!check_row(s)) continue;
        if (!check_rows(s, st)) continue;
        ret += dp(x + 1, r - cnt, s, n);
    }

    mem = ret;
    return ret;

}

int main() {
#ifdef D
    freopen("1896.in", "r", stdin);
#endif
    int n, k; n = read(); k = read();
    memset(f, -1, sizeof(f));
    cout << dp(0, k, 0, n) << endl;
    return 0;
}