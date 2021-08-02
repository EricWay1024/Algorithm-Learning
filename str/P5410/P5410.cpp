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

const int N = 2e7+10;
int n, m, z[N<<1];
char a[N], b[N<<1];

inline void Z(char *s, int *z, int n) {
    rep(i, 1, n) z[i] = 0;
    int l=0, r=0;
    rep(i, 2, n) {
        if (i <= r) z[i] = min(z[i-l+1], r-i+1);
        while(i+z[i] <= n && s[z[i]+i] == s[z[i]+1]) ++z[i];
        if (i+z[i]-1 > r) l = i, r = i+z[i]-1;
    }
}

ll w(int *z, int a, int b) {
    ll ans = 0;
    rep(i, a, b) {
        ans ^= (ll)(i-a+1) * ((ll)z[i] + 1ll);
    }
    return ans;
}

int main() {
#ifdef D
    freopen("P5410.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    scanf("%s%s", a+1, b+1);
    int n = strlen(a+1), m = strlen(b+1);
    b[m+1] = '$';
    strcpy(b + m + 2, a + 1);
    Z(b, z, m + n + 1);
    z[1] = m;
    cout << w(z, 1, m) << endl;
    cout << w(z, m + 2, m + n + 1) << endl;

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}