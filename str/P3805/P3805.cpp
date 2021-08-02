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
const int N = 2.31e7;
char s[N];
int d[N];
void manacher(char *s, int n) {
    for(int i=0, l=0, r=-1; i<n; ++i) {
        int k = (i > r) ? 1 : min(d[l+r-i], r-i);
        while(0 <= i-k && i+k < n && s[i-k] == s[i+k]) k++;
        d[i] = k--;
        if (i + k > r) l = i-k, r = i+k;
    }
}

int main() {
#ifdef D
    freopen("P3805.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    scanf("%s", s);
    int n = strlen(s);
    rev(i, n-1, 0) {
        s[2*i+1] = s[i];
        s[2*i] = '$';
    }
    s[2*n] = '$';
    n = 2 * n + 1;
    manacher(s, n);
    int ans = 0;
    For(i, n) ans = max(ans, d[i]-1);
    cout << ans << endl;

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}