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
const int N = 5e4+10;
int d[N];
int n, m;
bool check(int s) {
    int cnt=0;
    int last=0;
    rep(i,1,n+1){
        // check if we should remove stone i
        int dis = d[i] - last;
        if (dis >= s) {
            last = d[i];
        } else {
            cnt++;
            if (cnt > m) return 0;
        }
    }
    // check if we should remove stone n
    // if (d[n] - last < s || d[n+1] - d[n] < s) cnt++;
    return cnt <= m;
}

int main() {
#ifdef D
    freopen("POJ-3258.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int len=read(); n=read(), m=read();
    d[0] = 0;
    rep(i,1,n) d[i] = read();
    d[n+1] = len;
    sort(d, d+n+2);
    // rep(i,0,n+1) logs(i, d[i])
    int l=0, r=len;
    int ans=l;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if (check(mid)) ans = mid, l=mid+1;
        else r=mid-1;
    }
    // rep(i,1,len){
    //     logs(i, check(i))
    // }
    cout << ans << endl;




#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}