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

ll p[123];
ll s[123];
void solve() {
    int n=read(), k=read();
    rep(i,0,n-1) p[i]=read();
    s[0]=p[0]; 
    rep(i,1,n-1) s[i]=s[i-1]+p[i];
    rep(i,0,n-2) p[i]=p[i+1];

    ll addtotal=0;
    ll add=0;
    rev(i,n-2,0){
        ll t = p[i]*100/k;
        ll r = s[i]-t;
        if (r < 0) {
            addtotal-=r;
            add-=r;
        } else if (r > 0) {
            
        }
    }
    cout << addtotal << endl;

}


int main() {
#ifdef D
    freopen("1476-1.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int t=read();
    while(t--){
        solve();
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}