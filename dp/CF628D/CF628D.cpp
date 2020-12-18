#include <bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(register int i=from;i<=to;++i)
#define For(i,to) for(register int i=0;i<to;++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}

const long long M = 1000000007ll;
ll m, d;
vector<int> l, r;
ll f[2020][2020][2];
ll ten[2020]; // 10^i % m

void init() {
    ten[0] = 1;
    rep(i, 1, 2004) {
        ten[i] = ten[i - 1] * 10ll;
        ten[i] %= m;
    }
}

inline void read_vec(vector<int> &dim) {
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') {
        dim.push_back(c - '0');
        c = getchar();
    }
}

ll dp(int x, int st, int op, vector<int> &dim) {
    int s = dim.size();
    if (x == s) return (st == 0);

    ll &ret = f[x][st][op];
    if(ret > -1) return ret;
    ret = 0;
    int p = s - x - 1;
    if (!(x & 1)) {
        int maxx = op ? dim[x] : 9;

        rep(i, 0, maxx) {
            if (i == d) continue;
            int nst = (st + ((ten[p] * i) % m)) % m;
            ret += dp(x + 1, nst, op & (i == dim[x]), dim);
            ret %= M;
        }
    } else {
        if (op && dim[x] < d) return 0;
        else {
            int i = d;
            int nst = (st + ((ten[p] * i) % m)) % m;
            ret = dp(x + 1, nst, op & (i == dim[x]), dim);
        }
    }
    ret %= M;
    return ret;

}

ll solve(vector<int> &dim) {
    memset(f, -1, sizeof(f));
    return dp(0, 0, 1, dim);
}

int judge(vector<int> &dim) {
    ll sm = 0;
    int s = dim.size();
    For(i, s) {
        if(!(i & 1) && (dim[i] == d)) {
            return 0;
        }
        if((i & 1) && (dim[i] != d)) {
            return 0;
        }
        int p = s - i - 1;
        sm += ten[p] * dim[i];
        sm %= m;
    }
    if (sm != 0) return 0;
    else return 1;
}

int main() {
#ifdef D
    freopen("CF628D.in", "r", stdin);
#endif
    m = read(); d = read();
    read_vec(l); read_vec(r);

    init();

    ll res = solve(r) - solve(l) + judge(l);
    res %= M; res += M; res %= M;
    cout << res << "\n";

    return 0;
}