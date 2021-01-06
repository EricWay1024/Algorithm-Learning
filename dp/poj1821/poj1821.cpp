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
int n, m;
#define M 17123
int f[110][M]; int q[M];


struct worker {
    int l, p, s;

    void input() {
        l = read(); p = read(); s = read();
    }
} a[110];

bool operator< (worker a, worker b) {
    return a.s < b.s;
}

int calc(int i, int k) {
    return f[i - 1][k] - a[i].p * k;
}

int main() {
#ifdef D
    freopen("poj1821.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    m = read();
    rep(i, 1, m) {
        a[i].input();
    }

    sort(a + 1, a + m + 1);

    rep(i, 1, m) {
        int l = 1; int r = 0;

        rep(k, max(0, a[i].s - a[i].l), a[i].s - 1) {
            while (l <= r && calc(i, q[r] <= calc(i, k))) r--;
            q[++r] = k;
        }

        rep(j, 1, n) {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if (j >= a[i].s) {
                while (l <= r && q[l] < j - a[i].l) l++;
                if (l <= r) f[i][j] = max(f[i][j], calc(i, q[l]) + a[i].p * j);
            }
        }
    }

    cout << f[m][n] << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}