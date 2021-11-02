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
typedef double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

int n, f;
const int N = 1e4+100;
const ld pi = acos(-1.0);
const ld eps = 1e-5;
ld v[N];
bool check(ld v0) {
    int cnt=0;
    rep(i,1,n){
        cnt += (int)floor(v[i]/v0);
        if (cnt >= f) return 1;
    }
    // logs(v0, cnt, f)
    return 0;
}
int main() {
#ifdef D
    freopen("POJ-3122.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read();
    while(T--){
        n=read(), f=read()+1;
        ld maxv=0;
        rep(i,1,n){
            ld r=read();
            v[i] = pi * r * r;
            maxv = max(maxv, v[i]);
        }
        ld l=0.0001, r=maxv;
        while(r-l > eps) {
            ld mid=(r+l)/2.0;
            if (check(mid)) l=mid;
            else r=mid;
        }
        coutP(4) << l << endl;
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}