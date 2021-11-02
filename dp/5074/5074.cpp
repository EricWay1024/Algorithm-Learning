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
#include<cassert>
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

#define N 14
int n, m;
int game[N];

inline bool gb(int s, int j) {
    // get bit
    return ((s >> j) & 1);
}
int sb(int s, int j, bool b) {
    // set bit
    return b ? (s | (1 << j)) : (s & (~(1 << j)));
}

int sbs(int s, int j1, bool b1, int j2, bool b2) {
    // set two bits
    return sb(sb(s, j1, b1), j2, b2);
}

void output_bin(int s){
    if (s < 0) return;
    if (s == 1 || s == 0) cout << s;
    else {
        output_bin(s >> 1);
        output_bin(s & 1);
    }
}

ll f[N][N][1<<N];
ll dp(int i, int j, int st) {
    // we are considering i-th row, j-th column, and the state is now st.
    // we want to output count of possible solutions
    // i in [0, n-1], j in [0, m-1].

    // printf("i=%d, j=%d, st=", i, j); output_bin(st); cout << endl;
    // assert(j >= 0 && j < m);
    // assert(st >= 0 && (st < (1 << (m+1))));

    ll &mem = f[i][j][st];
    if (mem > -1) return mem;

    int stl = gb(st, j);
    int stu = gb(st, j + 1);

    if (j == m) {
        if (i == n - 1) return st == 0; // end of game
        // end of line
        else {
            if (stl) return 0;
            else return dp(i + 1, 0, st << 1);
        }
    }

    // obstacle
    if (!gb(game[i], j)) {
        if (stl || stu) return mem = 0;
        else return mem = dp(i, j + 1, st);
    }
    // not obstacle
    else {
        if (stl && stu) {
            return mem = dp(i, j + 1, sbs(st, j, 0, j + 1, 0));
        }
        else if (!stl && !stu) {
            return mem = dp(i, j + 1, sbs(st, j, 1, j + 1, 1));
        }
        else {
            mem = 0;
            mem += dp(i, j + 1, sbs(st, j, 0, j + 1, 1));
            mem += dp(i, j + 1, sbs(st, j, 1, j + 1, 0));
            return mem;
        }
    }

}

int main() {
#ifdef D
    freopen("5074.in", "r", stdin);
    double TIMEA = clock();
#endif
    int T = read();
    while (T--) {
        n = read(); m = read();
        memset(f, -1, sizeof(f));
        memset(game, 0, sizeof(game));
        For(i, n) {
            For(j, m) {
                int k = read();
                game[i] <<= 1; game[i] |= k;
            }
        }
        cout << dp(0, 0, 0) << endl;
    }

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}