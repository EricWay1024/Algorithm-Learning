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
#include<unordered_map>
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
const int N = 123;
ld mt[N][N];
int n;

void swap_rows(int i, int j) {
    rep(k,1,n+1) swap(mt[i][k], mt[j][k]);
}
void scalar_prod(int i, ld t) {
    rep(k,1,n+1) mt[i][k] *= t;
}
void mul_and_add(int i, int j, ld t) {
    // row i <= row i + row j * t
    rep(k,1,n+1) mt[i][k] += mt[j][k] * t;
}

ld eps = 1e-7;
int dcmp(ld x) {
    if (abs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}
bool gauss() {
    rep(i,1,n){
        int k=i;
        rep(j,i+1,n) if (abs(mt[j][i]) > abs(mt[k][i])) k = j;
        if (k != i) swap_rows(i, k);
        if (dcmp(mt[i][i]) == 0) return 0;
        scalar_prod(i, 1/mt[i][i]);
        rep(j,1,n) if (j != i && dcmp(mt[j][i]) != 0) {
            mul_and_add(j, i, -mt[j][i]);
        }
    }
    return 1;
}

int main() {
#ifdef D
    freopen("P3389.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    n=read();
    rep(i,1,n){
        rep(j,1,n+1){
            mt[i][j]=read();
        }
    }
    bool ret = gauss();
    if (ret) {
        rep(i,1,n) {
            coutP(2) << mt[i][n+1] << endl;
        }
    } else {
        puts("No Solution");
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}