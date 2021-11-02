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
#define rep(i,from,to) for(register int i=(int)from;i<=(int)to;++i)
#define For(i,to) for(register int i=0;i<(int)to;++i)
typedef long long ll;
inline int read(){
    int x=0; int sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
int m, n, land[20];
const ll MOD = 100000000;

bool check1(int s) {
    return !((s << 1) & s);
}

bool check2(int x, int s) {
    return (land[x] & s) == s;
}

bool check3(int s1, int s2) {
    return !(s1 & s2);
}

ll f[20][1<<15];
ll dp(int x, int st) {
    // considering row x, with st being state of last row
    if (x == m) return 1;
    if (f[x][st] > -1) return f[x][st];

    ll ans = 0;
    For(nst, 1 << n) 
        if (check1(nst) && check2(x, nst) && check3(nst, st)){
            ans += dp(x + 1, nst); ans %= MOD;
    }

    return f[x][st] = ans;
}

int main() {
#ifdef D
    freopen("1879.in", "r", stdin);
    double TIMEA = clock();
#endif
    m = read(); n = read();
    For(i, m) {
        For(j, n) {
            int k = read();
            land[i] <<= 1;
            land[i] |= k;
        }
    }
    memset(f, -1, sizeof(f));
    cout << dp(0, 0) << "\n";
    
#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}