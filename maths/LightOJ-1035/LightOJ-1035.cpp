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

#define N 200
ll prime[N];
bool is_prime[N];
int Eratosthenes(int n) {
  int p = 0;
  mmst(is_prime, 1);
  is_prime[0] = is_prime[1] = 0;
  rep(i,2,n) {
    if (is_prime[i]) {
      prime[p++] = i;  
      if ((ll)i * i <= n)
        for (int j = i * i; j <= n; j += i)
          is_prime[j] = 0;  
    }
  }
  return p;
}


void solve(){
    ll n=read();
    vector<ll> v;
    for(int i=0; prime[i]<=n; i++) {
        ll p=prime[i];
        ll a=0;
        ll pp=p;
        while(1){
            a += n/pp;
            pp *= p;
            if (n/pp == 0) break;
        }
        v.push_back(a);
    }
    printf("%lld", n);
    For(i,v.size()){
        printf(" %c ", i ? '*' : '=');
        printf("%lld (%lld)", prime[i], v[i]);
    }
    putchar(10);
}

int main() {
#ifdef D
    freopen("LightOJ-1035.in", "r", stdin);
    double TIMEA = clock();
#endif
    Eratosthenes(N-1);
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }
#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}