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


int mem[1000][3];
int sg(int n, int k) {
    // if (k == 0 && n <= 2) return 0;
    // if (k == 1 && n <= 1) return 0;
    // if (k == 2 && n == 0) return 0;
    if (n == 1 && k == 2) return 1;
    if (n <= 2) return 0;


    if (mem[n][k]>-1) return mem[n][k];

    set<int> st;
    if (k == 2) {
        rep(i, 0, n-1) {
            st.insert(sg(i, 2) ^ sg(n-1-i, 2));
        }
    } else if (k == 0) {
        rep(i, 0, (n-1)) {
            st.insert(sg(i, 1) ^ sg(n-1-i, 1));
        }
    } else {
        rep(i, 0, n-1) {
            st.insert(sg(i, 1) ^ sg(n-1-i, 2));
        }
    }

    for(int i=0; ; ++i) {
        if (!st.count(i)) return mem[n][k]=i;
    }
}

void init() {
    mmst(mem, -1);
    // rep(n,1,20){
    //     rep(k,0,2){
    //         printf("n=%d, k=%d, sg=%d\n", n, k, sg(n, k));
    //     }
    //     cout << endl;
    // }
}

bool legal(char c) {
    return c == '.' || c == 'X';
}

void solve() {
    char c=getchar();
    int length=0;
    bool first=1;
    vector< pair<int, int> > g;
    while(!legal(c)) c=getchar();
    while(legal(c)) {
        if (c == 'X') {
            if (length) {
                g.push_back(make_pair(length, first ? 1 : 2));
            }
            length = 0;
            first = 0;
        } else {
            length++;
        }
        c=getchar();
    }
    if (length) {
        g.push_back(make_pair(length, first ? 0 : 1));
    }

    int ans=0;
    for (auto p : g) {
        int n, k; tie(n, k) = p;
        ans ^= sg(n, k);
        printf("n=%d, k=%d, sg=%d\n", n, k, sg(n, k));
    }
    cout << ans << endl;


}

int main() {
#ifdef D
    freopen("LightOJ-1229.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init();
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}