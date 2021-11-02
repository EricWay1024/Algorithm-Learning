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
#include<cstdint>
#include<climits>
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(register int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 112345
int n, L, P;
ld sum[N]; ld f[N];
int ans[N]; 
char str[N][40];
const ld LIMIT = 1e18;

struct node{
    int j, l, r;
} q[N];
int head, tail;

ld quick_pow(ld a, ll b) {
    ld ans = 1.0;
    for(; b; b >>= 1) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
    }
    return ans;
}

ld val(ll i, ll j) {
    return quick_pow(abs(sum[i] - sum[j] + i - j - 1 - L), P);
}

ld cost(ll i, ll j) {
    return f[j] + val(i, j);
}

void output_poet(ll i) {
    int j = ans[i];
    if (j) output_poet(j);
    rep(k, j + 1, i){
        printf("%s", str[k]);
        if (k != i) putchar(' ');
    }
    putchar('\n');  
}

int main() {
#ifdef D
    freopen("1912.in", "r", stdin);
    double TIMEA = clock();
#endif
    int T = read();
    while(T--) {
        n = read(), L = read(), P = read();
        memset(f, 0, sizeof(f));
        memset(ans, 0, sizeof(ans));
        rep(i, 1, n) {
            scanf("%s", str[i]);
            sum[i] = sum[i - 1] + strlen(str[i]);
        }
        int j = 0;
        rep(i, 1, n) {
            printf("i=%d, j=%d\n", i, j);
            while (j < i-1 && cost(i, j) >= cost(i, j + 1)) j++;
            printf("after add: j=%d, cost(i,j)=%llf, cost(i,j+1)=%llf\n", j, cost(i, j), cost(i, j+1));
            f[i] = cost(i, j);
            ans[i] = j;
        }
        
        if (f[n] > LIMIT) {
            printf("Too hard to arrange\n");
        } else {
            printf("%lld\n", (ll)(f[n]+0.5));
            output_poet(n);
        }
        For(_, 20) putchar(45); 
        putchar('\n');   
    }

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}