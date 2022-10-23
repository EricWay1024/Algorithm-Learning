#include <bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(int i=(int)from;i<=(int)to;++i)
#define For(i,to) for(int i=0;i<(int)to;++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}

const int N = 23;
int a[N];

int count_one(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (n == 3) return 2;
    return count_one(n >> 2) + count_one(n & 3);
}

bool f[2248];
// f[j] := can weight j be represented?
int dp(int s, int n) {
    // s is a binary number representing m things to be removed
    memset(f, 0, sizeof(f));
    f[0] = 1;
    For(i, n) {
        if ((s >> i) & 1) continue;
        for(int j = 2000; j >= 0; j--) {
            if (f[j]) f[j+a[i]] = 1;
        }
    }
    int ans = 0;
    rep(j, 1, 2000) ans += f[j];
    return ans;
}
int main() {
#ifdef D
    freopen("1441.in", "r", stdin);
#endif
    int n = read(), m = read();
    For(i, n) {
        a[i] = read();
    }

    int maxs = 0;
    For(s, 1 << n) {
        if (count_one(s) == m) {
            maxs = max(maxs, dp(s, n));
        }
    }

    cout << maxs << endl;

    return 0;
}