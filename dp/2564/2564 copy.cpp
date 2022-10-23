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
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 1001000
int n, k;
int pearl_cnt;
pair< int, int > pearl[N]; 
int f[70];

int main() {
#ifdef D
    freopen("2564.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    k = read();
    rep(i, 1, k) {
        int t = read();
        For(_, t) {
            pearl[++pearl_cnt] = make_pair(read(), i);
        }
    }
    sort(pearl + 1, pearl + n + 1);
    memset(f, -1, sizeof(f));

    int ans = INT32_MAX;

    rep(i, 1, n) {
        auto &prl = pearl[i];
        int x, v; tie(x, v) = prl;

        f[v] = x;

        int minx = *min_element(f + 1, f + 1 + k);
        if (minx != -1) {
            ans = min(ans, x - minx);
        }
    }

    cout << ans << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}