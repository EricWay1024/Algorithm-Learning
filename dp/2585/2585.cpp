//#include <bits/stdc++.h>
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
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef long long ll;
inline int read(){
    char c=getchar();
    while(c>'9' || c<'0') {c=getchar();}
    return c-'0';
}
#define N 512345

vector<int> son[N];
int ncnt;
ll f[N][3];

void buildtree(int fa) {
    int u = ++ncnt;
    son[fa].push_back(u);
    int scnt = read();
    For(_, scnt) {
        buildtree(u);
    }
}

ll init_value;
function<ll(ll, ll)> func;

ll dp(int u, int c) {
    ll &mem = f[u][c]; if (mem > -1) return mem;

    int ss = son[u].size();

    if (ss == 0) {
        return mem = (c == 0);
    } else if (ss == 1) {
        ll res = init_value;
        int v = son[u][0];
        rep(i, 0, 2) {
            if (i == c) continue;
            res = func(res, dp(v, i));
        }
        res += (c == 0);
        return mem = res;
    } else {
        //ss == 2
        ll res = init_value;
        int v1 = son[u][0], v2 = son[u][1];
        rep(i, 0, 2) {
            if (i == c) continue;
            rep(j, 0, 2) {
                if (i == j || j == c) continue;
                res = func(res, dp(v1, i) + dp(v2, j));
            }
        }
        res += (c == 0);
        return mem = res;
    }
} 

ll solve(function<ll(ll, ll)> fun, ll iv) {
    memset(f, -1, sizeof(f));
    init_value = iv;
    func = fun;

    ll ans = init_value;
    rep(i, 0, 2) {
        ans = func(ans, dp(1, i));
    }
    return ans;
}

int main() {
#ifdef D
    freopen("2585.in", "r", stdin);
    double TIMEA = clock();
#endif
    buildtree(0);
    auto my_max = [](ll x, ll y) -> ll {
        return x > y ? x : y;
    };
    auto my_min = [](ll x, ll y) -> ll {
        return x < y ? x : y;
    };
    
    cout << solve(my_max, 0) << " " << solve(my_min, INT32_MAX) << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}