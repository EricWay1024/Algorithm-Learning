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
const int N = 1024;
int sg[N];
set<int> st;

void init() {
    sg[0] = 0;
    rep(i,1,1000) {
        st.clear();
        for(int j=1; j<=i; j<<=1) {
            st.insert(sg[i-j]);
        }
        for(int k=0; ;k++) {
            if (!st.count(k)) {
                sg[i] = k;
                break;
            }
        }
    }
}


int main() {
#ifdef D
    freopen("HDU-1847.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    // init();
    // rep(i,1,20) {
    //     logs(i, sg[i])
    // }
    int n;
    while(~scanf("%d", &n)) {
        // cout << (sg[n] ? "Kiki" : "Cici") << endl;
        cout << (n%3 ? "Kiki" : "Cici") << endl;

    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}