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
const int N = 10005;

void poly_multiply(int *a, int *b, int *c, int n) {
    rep(i,0,n){
        rep(j,0,n) if(i+j<=n) {
            c[i+j] += a[i] * b[j];
        }
    }
}

void poly_init(int *a, int n, int k) {
    for(int t=0; t<=n; t+=k) a[t]=1;
}

int a[N], b[N], c[N];
void solve(int num1, int num2, int num5) {
    int n=1*num1+2*num2+5*num5;

    mmst(a, 0); mmst(b, 0); mmst(c, 0);
    poly_init(a, num1, 1);
    poly_init(b, num2 * 2, 2);
    poly_multiply(a, b, c, n);

    mmst(b, 0); mmst(a, 0);
    poly_init(b, num5 * 5, 5);
    poly_multiply(c, b, a, n);

    int ans = n+1;
    rep(i,0,n){
        if (!a[i]) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
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
    freopen("HDU-1085.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int num1, num2, num5;
    while(1) {
        num1=read(), num2=read(), num5=read();
        if (num1 + num2 + num5 == 0) break;
        solve(num1, num2, num5);
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}