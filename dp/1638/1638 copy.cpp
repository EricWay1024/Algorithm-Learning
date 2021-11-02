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
#define N 1001000
int m, n, a[N];

int q[N];
int vis[N]; 


int main() {
#ifdef D
    freopen("1638.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(); m = read();
    rep(i, 1, n) {
        a[i] = read();
    }
    int ans = INT32_MAX;
    int l = 1; int r = 1; vis[a[1]] = 1; int kc = 1;
    int al, ar;
    while(l <= r && r <= n) {
        if (kc == m) {
            if (r - l < ans) ans = r - l, al = l, ar = r;
            vis[a[l]]--;
            if (!vis[a[l]]) kc--;
            l++;
        } else {
            r++;
            if (!vis[a[r]]) kc++;
            vis[a[r]]++;
        }
    }

    cout << al << " " << ar << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}