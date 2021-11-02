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

// set<int> st;
// map<int, int> mp;
// int sg(int x) {
//     if (x == 0) return 0;
//     int &mem = mp[x];
//     if (mem) return mem;
//     st.clear();
//     rep(i,0,x-1) st.insert(sg(i));
//     rep(i,1,x-1) st.insert(sg(i) ^ sg(x-i));
//     for(int i=0; ; i++) {
//         if (!st.count(i)) return mem = i;
//     }
// }

int sg_quick(int x) {
    if (!x) return 0;
    if (!(x % 4)) return x-1;
    if ((x % 4) == 3) return x+1;
    return x;
}

int main() {
#ifdef D
    freopen("HDU-3032.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int t=read();
    while(t--){
        int n=read();
        int ans = 0;
        rep(i,1,n) {
            ans ^= sg_quick(read());
        }
        cout << (ans ? "Alice" : "Bob") << endl;
    }

    // rep(i,0,100) {
    //     cout << i << ' ' << sg(i) << endl;
    // }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}