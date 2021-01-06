// don't wanna try it for now

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
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}

inline char read_par() {
    char c=getchar();
    while(!(c == '(' || c == ')')) {c = getchar(); }
    return c;
}


int n;
#define N 512345
char p[N];
int fa[N]; vector<int> son[N];
ll f[N], g[N], h[N], t[N];



// ()(())
void dfs(int v) {
    int u = fa[v];
    if (p[v] == '(') {
        t[v] = t[u] + 1;
    } else {
        t[v] = t[u] - 1;
        if (t[v] == -1) {
            t[v] = 0;
            h[v] = v;
            g[v] = 0;
        } else if (t[v] == 0) {

        }
    }

}

int main() {
#ifdef D
    freopen("5658.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    rep(i, 1, n) {
        p[i] = read_par();
    }
    rep(i, 1, n) {
        fa[i] = read();
        son[fa[i]].push_back(i);
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}