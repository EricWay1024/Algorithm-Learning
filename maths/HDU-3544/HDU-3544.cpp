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

set<int> st;
int mem[100][100];
int sg(int x, int y) {
    if (x == 1) return 0;
    int &m = mem[x][y]; if(m) return m;

    st.clear();
    rep(i,1,x-1) {
        st.insert(sg(y, i) ^ sg(y, x - i));
    }

    for(int i=0; ; i++) {
        if(!st.count(i)) return m=i;
    }
}


int sg2(int x, int y) {
    if (x==1) return 0;
    return 1;
}

int main() {
#ifdef D
    freopen("HDU-3544.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rep(x,1,30) {
        rep(y,1,30) {
            printf("%d, %d -> %d\n", x, y, sg(x, y));
        }

    }
    // int T=read();
    // rep(cas, 1, T) {
    //     printCase(cas);
    //     int ans = 0;
    //     int n=read();
    //     rep(i,1,n) {
    //         ll x=read();
    //         ll y=read();
    //         ans ^= sg(x, y);
    //     }
    //     puts(ans ? "Alice" : "Bob");
    // }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}