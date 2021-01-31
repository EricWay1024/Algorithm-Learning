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
#include<iomanip>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

const int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
bool vis[1000][1000];

bool valid(int x, int y, int n) {
    return (x >= 1 && x <= n) && (y >= 1 && y <= n) && !vis[x][y];
}

bool dfs(int x, int y, int n) {
    int ret = 0;
    vis[x][y] = 1;
    For(i, 4) {
        int dx=d[i][0], dy=d[i][1];
        if (!valid(x+dx, y+dy, n)) continue;
        int res = dfs(x+dx, y+dy, n);
        if (!res) ret = 1;
    }
    vis[x][y] = 0;
    return ret;   
}


int main() {
#ifdef D
    freopen("HDU-1564.in", "r", stdin);
    clock_t TIMEA = clock();
#endif

    // rep(i,1,100) {
    //     mmst(vis, 0);
    //     cout << i << " " << dfs(1, 1, i) << endl;
    // }

    while(1) {
        int n=read();
        if (!n) break;
        cout << ((n&1) ? "ailyanlu" : "8600") << endl;
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}