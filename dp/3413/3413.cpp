#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define rep(i,from,to) for(int i=from;i<=to;++i)
#define For(i,to) for(int i=0;i<(int)to;++i)
typedef long long ll;

const long long M = 1000000007;

vector<int> l, r;
ll f[1024][11][11][2];

inline void read(vector<int> &res){
    res.clear();
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') {
        res.push_back(c - '0');
        c = getchar();
    }
}

ll dp(int x, int st1, int st2, int op, vector<int> &dim) {
    // printf("%d %d %d op=%d\n", x, st1, st2, op);
    if(x == (int)dim.size()) return 1;
    ll &ret = f[x][st1][st2][op];
    if (ret != -1) return ret;

    int m = op ? dim[x] : 9;

    ret = 0;

    for(int i = 0; i <= m; i++) if (st1 != i && st2 != i){
        // cout << i << " " << m << endl;
        if (st2 == 10 && i == 0) {
            ret += dp(x + 1, 10, 10, op & (i == m), dim);
        } else {
            ret += dp(x + 1, st2, i, op & (i == m), dim);
        }
        ret %= M;
    }
    // printf("%d %d %d %d %lld\n", x, st1, st2, op, ret);

    return ret;
}

ll solve(vector<int> &dim) {
    memset(f, -1, sizeof(f));
    ll res = dp(0, 10, 10, 1, dim); // all the un-meng numbers k s.t. 0 <= k <= n, n represented by dim
    ll s = 0;
    For(i, dim.size()) {
        int u = dim[i];
        s = (s * 10) % M;
        s = (s + u) % M;
    }
    s = s - res + 1;
    s %= M; s += M; s %= M;
    return s;
}

bool judge(vector<int> &dim) {
    for(int i = 0, s = dim.size(); i < s - 2; ++i) {
        if (dim[i] == dim[i + 2] || dim[i] == dim[i + 1] || dim[i + 1] == dim[i + 2]) return true;
    }
    return false;
}

int main() {
#ifdef D
    freopen("3413.in", "r", stdin);
#endif
    read(l); read(r);
    ll ans = solve(r) - solve(l) + judge(l);
    ans %= M; ans += M; ans %= M;
    cout << ans << "\n";
    return 0;
}