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
#define N 212345
int n; int a[N], sum[N], q[N];

void output(int *a, int l, int r) {
    cout << "q: ";
    rep(i, l, r) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
#ifdef D
    freopen("1115.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    rep(i, 1, n) {
        a[i] = read();
        sum[i] = sum[i-1] + a[i];
    }
    int l, r; l = r = 1;
    int ans = a[1];
    q[1] = 0;
    rep(i, 1, n) {
        // cout << i <<  " " << sum[i] << endl;
        // output(q, l, r);
        ans = max(ans, sum[i] - sum[q[l]]);
        while (l <= r && sum[q[r]] >= sum[i]) --r;
        // output(q, l, r);
        q[++r] = i;
        // output(q, l, r);
    }

    cout << ans << endl;
#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}