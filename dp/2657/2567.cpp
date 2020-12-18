#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f[15][15][2];

ll dfs(int x, int st, int op, vector<int> &dim) { 
    // op = 0 means <, op = 1 means ==
    // initially st is leading zero. but leading zero is different from zero in other places.
    // so we assgin 10 to st for leading zero
    if (x == -1) return 1; // this means dfs is called when x = 0 and satisfies the conditions
    if (f[x][st][op] != -1) return f[x][st][op];

    int m = op ? dim[x] : 9; 
    ll ret = 0;

    for(int i = 0; i <= m; i++) if (abs(st - i) >= 2 || st == 10){
        ret += dfs(x - 1, (st == 10 && i == 0) ? 10 : i, op & (i == m), dim);
    }

    f[x][st][op] = ret;
    return ret;
}

ll solve(int x) {
    vector<int> dim;
    while(x) {
        dim.push_back(x % 10);
        x /= 10;
    }
    memset(f, -1, sizeof(f));
    return dfs(dim.size() - 1, 10, 1, dim); 
}

int main() {
#ifdef D
    freopen("2567.in", "r", stdin);
#endif
    int l, r; cin >> l >> r;
    ll ret = solve(r) - solve(l - 1);
    cout << ret << endl;
    return 0;
}