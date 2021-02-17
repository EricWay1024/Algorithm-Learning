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
// int sgo(int x, int k) {
//     if (x == 0) return 0;
//     if (mp[x]) return mp[x];

//     st.clear();
//     rep(i,1,min(x, k)){
//         st.insert(sgo(x-i, k));
//         rep(j, 1, x-i){
//             st.insert(sgo(j, k) ^ sgo(x-i-j, k));
//         }
//     }

//     for(int i=0; ; i++) {
//         if (!st.count(i)) return mp[x]=i;
//     }
// }

int sg(int x, int k) {
    if (x == 0) return 0;
    if (x & 1) return 1;
    if (k == 1) return 0;
    if (!(x % 4)) return 4;
    return 2;
}


int main() {
#ifdef D
    freopen("HDU-3951.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    // rep(x,1,30) {
    //     rep(k, 1, 30) {
    //         printf("%d, %d -> %d\n", x, k, sgo(x, k));
    //     }
    // }
    // cout << sgo(2, 1) << endl;
    int t=read();
    rep(cas, 1, t) {
        printCase(cas);
        int n=read();
        int k=read();
        int ans = 0;
        rep(i,1,min(n,k)) {
            if(!sg(n-i, k)) ans=1;
        }
        // logs(n-k, k, ans)
        puts(!ans ? "second" : "first");
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}