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
// #include<unordered_map>
#include<utility>
#include<vector>
#include<numeric>
#include<functional>
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

const int N = 21;
int n, w, a[N], b[N];
int ans = N;


void dfs(int x, int y) {
    // considering x-th cat, have used `y` cars
    if (x == n + 1) {
        ans = min(ans, y);
        return;
    }

    if (y >= ans) return;

    rep(i, 1, y) {
        if (b[i] + a[x] <= w) {
            b[i] += a[x];
            dfs(x + 1, y);
            b[i] -= a[x];
        }
    }

    b[y + 1] = a[x];
    dfs(x + 1, y + 1);
    b[y + 1] = 0;
}


int main() {
#ifdef D
    freopen("167.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    cin >> n >> w;
    rep(i,1,n) cin>>a[i];
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);

    dfs(1, 0);

    cout << ans << endl;


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}