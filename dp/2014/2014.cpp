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

int n, m;
#define N 321
#define mst(a,b) memset(a,b,sizeof(a))

vector<int> son[N];
int f[N][N]; 
// for a subtree with root u, when choosing k lessons, the maximum score we could get is f[u][k]

void dp(int u) {
    for(int v : son[u]) {
        dp(v);
        for(int j = m + 1; j >= 1; j--) {
            for(int k = 0; k < j; k++){
                f[u][j] = max(f[u][j], f[v][k]+f[u][j-k]);
            }
        }
    }  
}


int main() {
#ifdef D
    freopen("2014.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(); m = read();
    rep(i, 1, n) {
        int fa = read();
        f[i][1] = read();
        son[fa].push_back(i);
    }
    dp(0);
    cout << f[0][m+1] << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}