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
int n;
int a[100], v[100], len, cnt;
bool cmp(int a, int b) { return a > b; }

bool dfs(int x, int y, int z) {
    // considering the xth slot with length y finished, trying sticks with index >= z

    if (x == cnt + 1) return 1;
    if (y == len) return dfs(x + 1, 0, 1);

    int last = -1;
    rep(i,z,n) if (!v[i] && y + a[i] <= len && a[i] != last) {
        v[i] = 1;
        last = a[i];
        if (dfs(x, y + a[i], i + 1)) return 1;
        v[i] = 0;
        if (y == 0) return 0;
    }
    return 0;
}


int main() {
#ifdef D
    freopen("POJ-1011.in", "r", stdin);
    clock_t TIMEA = clock();
#endif

    while ((n = read())) {
        int sum = 0; 
        rep(i,1,n) a[i]=read(), sum+=a[i];
        sort(a + 1, a + 1 + n, cmp);
        int mx = a[1];
        rep(i,mx,sum) if ((sum % i) == 0) {
            len = i;
            cnt = sum/len;

            rep(i, 1, n) v[i] = 0;
            if (dfs(1, 0, 1)) { cout << len << endl; break; }
        }
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}