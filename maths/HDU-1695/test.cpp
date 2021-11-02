#include<bits/stdc++.h>
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


// const int N = 1e7+5;
// int sigma[N], g[N]; short flg[N]; int p[N], tot;
// void getSigma(int n) {
//     sigma[1] = 1;
//     rep(i,2,n) {
//         if (!flg[i]) sigma[i]=g[i]=i+1, p[++tot]=i;
//         for(int j=1; j<=tot && i*p[j]<=n; ++j) {
//             flg[i * p[j]] = 1;
//             if (i % p[j] == 0) {
//                 g[i * p[j]] = g[i] * p[j] + 1;
//                 sigma[i * p[j]] = sigma[i] / g[i] * g[i * p[j]];
//                 break;
//             } else {
//                 g[i * p[j]] = p[j]+1;
//                 sigma[i * p[j]] = sigma[i] * sigma[p[j]];
//             }
//         }
//     }
// }

int main() {
    // rep(x,1,25){
    //     printf("| $%d$ | $%d$ |\n", x, 25/x);
    // }
    cout << test(1) << endl;
    return 0;
}