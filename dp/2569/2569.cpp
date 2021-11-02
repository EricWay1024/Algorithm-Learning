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
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define T 2048
int t, maxp, w;
int ap[T], bp[T], as[T], bs[T];
// a buy, b sell
// p price, s limit     
int q[T], l, r;
int f[T][T];

void update(int &ov, int v) {
    ov = max(ov, v);
}

int g1(int i, int k) {
    return f[i-w-1][k] + k * ap[i];
}

int g2(int i, int k) {
    return f[i-w-1][k] + k * bp[i];
}


struct Q {
    int l, r, q[T];

    void init() {
        l = 1, r = 0;
    }

    bool non_empty() {
        return l <= r;
    }

    void pop_front() {
        l++;
    }

    void pop_back() {
        r--;
    }

    int front() {
        return q[l];
    }

    void push_back(int k, function<int(int)> g) {
        while (l <= r && g(q[r]) <= g(k)) r--;
        q[++r] = k;
    }

    void pop_illgeal_front(function<int(int)> g) {
        while (l <= r && !g(q[l])) l++;
    }

}myq;


int main() {
#ifdef D
    freopen("2569.in", "r", stdin);
    double TIMEA = clock();
#endif
    t=read(),maxp=read(),w=read();
    rep(i, 1, t) {
        ap[i]=read(),bp[i]=read(),as[i]=read(),bs[i]=read();
    }

    memset(f, 128, sizeof(f));

    rep(i, 1, t) {
        rep(j, 0, as[i]) {
            update(f[i][j], -j * ap[i]);
        }

        rep(j, 0, maxp) {
            update(f[i][j], f[i-1][j]);
        }

        if (i <= w) continue;

        myq.init();
        rep(j, 0, maxp) {
            myq.pop_illgeal_front([i, j](int k) -> int { 
                return k >= j - as[i];
            });

            myq.push_back(j, [i](int k) -> int {
                return g1(i, k);
            });

            if (myq.non_empty()) update(f[i][j], g1(i, myq.front()) - j * ap[i]);

        }

        myq.init();
        rep(k, 0, bs[i]) {
            myq.push_back(k, [i](int k) -> int {
                return g2(i, k);
            });
        }

        rep(j, 0, maxp) {
            myq.pop_illgeal_front([i, j](int k) -> int {
                return k >= j;
            });

            myq.push_back(j + bs[i], [i](int k) -> int {
                return g2(i, k);
            });

            if (myq.non_empty()) update(f[i][j], g2(i, myq.front()) - j * bp[i]);

        }
    }

    int ans = *max_element(f[t], f[t] + maxp + 1);
    cout << ans << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}