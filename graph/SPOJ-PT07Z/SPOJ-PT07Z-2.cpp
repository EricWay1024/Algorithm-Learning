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
// #include<cstdint>
#include<climits>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
typedef long long ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 12000
int n;
vector<int> son[N];

int dpth[N]; int ans;

void dfs(int u, int fa, int d) {
    dpth[u] = d;
    if (dpth[u] > dpth[ans]) ans = u;
    for(int v : son[u]) if (v != fa) {
        dfs(v, u, d + 1);
    }
}


int main() {
#ifdef D
    freopen("SPOJ-PT07Z.in", "r", stdin);
    double TIMEA = clock();
#endif
    n=read();
    rep(i,1,n-1){
        int u=read(),v=read();
        son[u].push_back(v);
        son[v].push_back(u);
    }
    dfs(1, -1, 0);
    dfs(ans, -1, 0);
    cout << dpth[ans] << endl;
#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}