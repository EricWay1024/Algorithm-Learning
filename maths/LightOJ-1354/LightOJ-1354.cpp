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
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
inline ll read_dec(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

inline ll read_bin(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'1'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='1'){x=(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

bool judge(){
    ll a[4], b[4];
    For(i, 4) a[i] = read_dec();
    For(i, 4) b[i] = read_bin();
    For(i, 4) if (a[i] != b[i]) return false;
    return true;
}

int main() {
#ifdef D
    freopen("LightOJ-1354.in", "r", stdin);
    double TIMEA = clock();
#endif
    int t=read_dec();
    rep(i, 1, t) {
        printf("Case %d: %s\n", i, judge() ? "Yes" : "No");
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}