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
#define N 512345
ll prime[80500]; int pc;
bool is_prime[N*2+1];
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
    int c=0;
    ll ans=1;
    for(int i = 0; prime[i] * prime[i] <= n; i++){
        ll p = prime[i];
        int cnt = 0;
        while(!(n%p)){
            n/=p;
            cnt++;
        }
        ans *= (cnt + 1);
    }
    if (n-1) ans <<= 1;
    cout << ans-1 << endl;
}

int main() {
#ifdef D
    freopen("LightOJ-1028.in", "r", stdin);
    double TIMEA = clock();
#endif
    pc=Eratosthenes(N<<1);
    // logs(pc)
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