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
        rep(i, 1, n) {
            scanf("%s", str[i]);
            sum[i] = sum[i - 1] + strlen(str[i]);
        }
        head = tail = 1;
        q[head]=(node){0, 1, n};
        rep(i, 1, n) {
            if (q[head].r == i - 1) head++;
            else q[head].l = i;

            int j = q[head].j;
            f[i] = cost(i, j); ans[i] = j;
            
            int pos = -1;
            while(head <= tail) {
                int jt = q[tail].j, lt = q[tail].l, rt = q[tail].r;
                if (cost(lt, i) <= cost(lt, jt)) pos = lt, tail--;
                else if (cost(rt, i) >= cost(rt, jt)) break;
                else {
                    int le = lt, re = rt;
                    while(le < re) {
                        int me = ((le + re) >> 1);
                        if (cost(me, i) >= cost(me, jt)) le = me + 1;
                        else re = me;
                    }
                    if (le <= n) pos = le, q[tail].r = le - 1;
                    break;
                }
            }
            if (pos > -1) q[++tail] = (node){i, pos, n};
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