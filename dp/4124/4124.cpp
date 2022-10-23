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
typedef long long ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
ll L, R;
vector<int> diml, dimr;

ll f[15][11][2][2][2][2][2][2];
ll dfs(int x, int st1, int st2, int s3, int h8, int h4, int op1, int op2) {
    if (x == -1) return s3 && (!h8 || !h4);
    ll &ret = f[x][st1][st2][s3][h8][h4][op1][op2];
    if (ret != -1) return ret;
    int minn = op1 ? diml[x] : 0;
    int maxx = op2 ? dimr[x] : 9;
    ret = 0;
    rep(i, minn, maxx) {
        ret += dfs(x - 1, i, st1 == i, (st2 && st1 == i) || s3, h8 || i == 8, h4 || i == 4, op1 && i == minn, op2 && i == maxx);
    }
    return ret;
}

int main() {
#ifdef D
    freopen("4124.in", "r", stdin);
    double TIMEA = clock();
#endif
    L = read(); R = read();
    while(L){
        diml.push_back(L%10); L/=10;
    }
    while(R){
        dimr.push_back(R%10); R/=10;
    }
    memset(f, -1, sizeof(f));
    cout << dfs(dimr.size()-1, 10, 0, 0, 0, 0, 1, 1) << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}