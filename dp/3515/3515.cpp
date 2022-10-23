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
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef int ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 512345
int n; int a[N]; 
ld sqr[N], f[N];

struct node {
    int j, l, r;
}q[N]; int head, tail;

ld val(int i, int j) {
    return (ld)a[j] + sqr[i - j] - (ld)a[i];
}

inline bool better(int i, int j1, int j2) {
    return val(i, j1) >= val(i, j2);
}

int binary_search(int i) {
    int l = q[tail].l, r = q[tail].r, j = q[tail].j;
    int ans = r + 1;
    while(l <= r) {
        int mid = l + ((r-l) >> 1);
        if (better(mid, i, j)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

void solve() {
    head=1; tail=0;
    rep(i, 1, n) {

        if (head <= tail && q[head].r == i - 1) head++;
        else q[head].l = i;

        while(head <= tail && better(q[tail].l, i, q[tail].j)) --tail;
        if (head <= tail) {
            int pos = binary_search(i);
            if (pos <= n) {
                q[tail].r = pos - 1;
                q[++tail] = (node){i, pos, n};
            }
        }
        else {
            q[++tail] = (node){i, i, n};
        } 

        f[i] = max(f[i], val(i, q[head].j));

    }
}

int main() {
#ifdef D
    freopen("3515.in", "r", stdin);
    double TIMEA = clock();
#endif
    n=read();
    rep(i,1,n){
        sqr[i]=sqrt(i);
        a[i]=read();
    }
    
    solve();
    reverse(a + 1, a + 1 + n);
    reverse(f + 1, f + 1 + n);
    solve();

    rev(i,n,1) {
        printf("%d\n", (int)ceil(f[i]));
    }
#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}