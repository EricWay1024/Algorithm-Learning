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

// map<int, int> mp;
// int sg(int p, int n) {
//     if (p >= n) return 0;
//     if (mp[p]) return mp[p];

//     set<int> st; // don't use global variable!!!
//     rep(i,2,9) {
//         st.insert(sg(i*p, n));
//     }

//     for(int i=0; ; i++) {
//         if (!st.count(i)) return mp[p]=i;
//     }
// }

// int get_sg(int n) {
//     mp.clear();
//     return sg(1, n);
// }

int sg(db n) {
    while(n > 18) n/=18;
    return n >= 1 && n <= 9;
}

// int sg2(ll n) {
//     ll t = ceil((log((ld)n) / log((ld)18.0)));
//     int b = pow(18, t);
//     int a = b/2 + 1;
//     return !(n >= a && n <= b);
// }


int main() {
#ifdef D
    freopen("HDU-1517.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    // cout << sg(1, 34012226) << endl;
    // rep(n,1,10000){
    //     int ans = get_sg(n);
    //     if(ans) continue;
    //     printf("%d => %d\n", n, ans);
    // }
    // // rep(p,1,20) {
    // //     printf("# %d => %d\n", p, sg(p, 17));
    // // }
    int n;
    while(~scanf("%d", &n)) {
        puts(sg(n) ? "Stan wins." : "Ollie wins.");
    }
    // rep(n,2,){
    //     int a=sg(n);
    //     int b=sg2(n);
    //     if (a!=b) cout << n << endl;
    // }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}