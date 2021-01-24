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
#define N 123
int w[N];
ld p[N];
ld f[N*N];
int solve(){
    ld P; cin>>P; P=1-P;
    int n=read();
    int s=0;
    rep(i,1,n){
        w[i]=read(); s+=w[i];
        cin>>p[i]; p[i]=1-p[i];
    }
    mmst(f, 0);
    f[0]=1;
    rep(i,1,n){
        rev(j,s,0){
            if (j>=w[i]) f[j]=max(f[j], f[j-w[i]]*p[i]);
        }
    }
    rev(j,s,0){
        if(f[j]>P) return j;
    }
    return 0;
}

int main() {
#ifdef D
    freopen("LightOJ-1079.in", "r", stdin);
    double TIMEA = clock();
#endif
    int t=read(); rep(i,1,t){printf("Case %d: %d\n", i, solve());}
#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}