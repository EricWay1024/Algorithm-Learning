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
const int N = 124;

void poly_clean(int *a, int n) {
    rep(i,0,n) a[i]=0;
}

void poly_multiply(int *a, int *b, int *c, int n) {
    poly_clean(c, n);
    rep(i,0,n){
        rep(j,0,n) if(i+j<=n) {
            c[i+j] += a[i] * b[j];
        }
    }
}

void poly_init(int *a, int n, int k) {
    poly_clean(a, n);
    for(int t=0; t<=n; t+=k) a[t]=1;
}

int a[N], b[N], c[N];
void solve(int n) {
    poly_init(c, n, 1);
    rep(i,2,n) {
        memcpy(a, c, sizeof(a));
        poly_init(b, n, i);
        poly_multiply(a, b, c, n);
    }
    cout << c[n] << endl;
}

// int const xn=305;
// int n,f[xn],t[xn];
// void printarray(int *a, int n) {
//     rep(i,0,n){
//         cout << a[i] << ' ';
//     }
//     cout << '\n';
// }
// void solve() {
//     while(scanf("%d",&n)==1){
//         for(int i=0;i<=n;i++)f[i]=1,t[i]=0;
//         for(int i=2;i<=n;i++){
//             for(int j=0;j<=n;j++)
//                 for(int k=0;k<=n;k+=i) {
//                     t[j+k]+=f[j];
//                 }
//             logs(i);
//             printarray(f, n);
//             printarray(t, n);
//             for(int j=0;j<=n;j++)f[j]=t[j],t[j]=0;
//         }
//         printf("%d\n",f[n]);
//     }

// }

int main() {
#ifdef D
    freopen("HDU-1028.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n;
    while(~scanf("%d", &n)) {
        solve(n);
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}