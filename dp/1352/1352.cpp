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
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}

#define N 6123
int r[N];
int n;
vector<int> son[N];
int fa[N], root;

ll f[N][2];
ll dp(int u, int op) {
    ll &mem = f[u][op];
    if (mem > -1) return mem;

    ll s = 0; // what if i don't attend
    for(int v : son[u]) {
        s += dp(v, 0);
    }

    ll t = r[u]; // what if i attend
    for(int v : son[u]) {
        t += dp(v, 1);
    }

    if (op == 1) {
        // my boss attend, so i can't attend
        return mem = s;
    } else {
        // my boss don't attend, so i can choose
        return mem = max(s, t);
    }
}

int main() {
#ifdef D
    freopen("1352.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    rep(i, 1, n) {
        r[i] = read();
    }
    rep(i, 1, n-1) {
        int a = read(), b = read();
        son[b].push_back(a);
        fa[a] = b;
    }

    rep(i, 1, n) {
        if (fa[i] == 0) {
            root = i;
            break;
        }
    }
    memset(f, -1, sizeof(f));

    cout << dp(root, 0) << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}