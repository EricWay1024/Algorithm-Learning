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
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 300
int n, p;
vector<int> son[N];
int sz[N]; // size of subtree
int f[N][N];
// i: root of subtree, want to destroy subtree of size j, min cost
// 0 <= j <= n

void calsz(int u) {
    sz[u] = 1;
    for(int v : son[u]) {
        calsz(v);
        sz[u] += sz[v];
    }
}

void dp(int u) {
    f[u][1] = son[u].size();
    // f[u][sz[u]] = 0;
    for(int v : son[u]) {
        dp(v);
        for(int j = sz[u]; j >= 2; j--) {
            for(int l = 1; l <= j - 1; l++) {
                f[u][j] = min(f[u][j], f[v][l] + f[u][j-l] - 1);
            }
        }
    } 
}

int main() {
#ifdef D
    freopen("1272.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(); p = read();
    For(i, n - 1) {
        int ff = read(), j = read();
        son[ff].push_back(j);
    }
    memset(f, 0x3f3f3f3f, sizeof(f));
    calsz(1);
    dp(1);

    int ans = f[1][p];
    for(int i = 2; i <= n; i++) {
        ans = min(ans, f[i][p] + 1);
    }
    // cout << ans1 << endl;

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 0; j <= n; j++){
    //         if (f[i][j] < 10000)
    //         printf("f[%d][%d]=%d\n", i, j, f[i][j]);
    //     }
    // }


    cout << ans << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}