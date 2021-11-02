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
// int mem[100][100];
// int sg(int a, int b) {
//     if (a == 0 && b == 0) return 0;
//     if (mem[a][b]) return mem[a][b];

//     st.clear();
//     rep(i,0,a-1) st.insert(sg(i, b));
//     rep(i,0,b-1) st.insert(sg(a, i));
//     rep(i,1,min(a,b)) st.insert(sg(a-i, b-i));

//     for(int i=0; ; ++i) {
//         if (!st.count(i)) return mem[a][b]=i;
//     }
// }
const db P = (sqrt(5.0)+1.0)/2.0;
int sg_(int a, int b) {
    if (a > b) swap(a, b);
    return floor(P*(b-a)) != a;
}

int main() {
#ifdef D
    freopen("HDU-1527.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    // rep(a,0,99) {
    //     rep(b,0,99) if (sg(a, b) == 0 && a < b) {
    //         printf("%d, %d -> %d, %lf\n", a, b, sg(a, b), floor((db)(b-a)*P));
    //     }
    // }
    int a, b;
    while(~scanf("%d%d", &a, &b)) {
        cout << sg_(a, b) << endl;
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}