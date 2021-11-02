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

const ll M=998244353ll;
ll quick_pow(ll a, ll b) {
    ll ans=1;
    for(; b; b>>=1, a=(a*a)%M){
        if(b&1) ans=(ans*a)%M;
    }
    return ans;
}

const int N = 1e7+10; ll k;
int h[N]; int p[664979], tot; short flag[N];
int f[N]; int S[N]; int G[N/2];
void seive(int n){
    h[1]=1; f[1]=1;
    rep(i,2,n){
        if (!flag[i]) p[++tot]=i, h[i]=i-1, f[i]=quick_pow(i, k);
        for(int j=1; j<=tot && p[j]<=n/i; ++j){
            int m=i*p[j];
            flag[m]=1;

            f[m]=1ll*f[i]*f[p[j]]%M;

            if (i%p[j]){
                h[m]=h[p[j]]*h[i];
            } else {
                if ((i/p[j])%p[j]) h[m]=(-p[j])*h[i/p[j]];
                else h[m]=0;

                break;
            }
        }
    }

    rep(i,1,n){
        S[i] = (0ll+S[i-1]+f[i])%M;
    }

    rep(i,1,n/2){
        G[i] = (0ll+G[i-1]+((((S[2*i]+S[2*i-1])%M)-2ll*S[i])%M))%M;
    }

    rep(i,1,n/2){
        h[i]%=M;
        S[i] = (0ll+S[i-1]+(1ll*h[i]*f[i]%M))%M;
    }
}


int main() {
#ifdef D
    freopen("P6156.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    ll n=read(); k=read();
    seive(n<<1);
    ll ans=0;
    for(ll l=1, r; l<=n; l=r+1){
        r=min(n, n/(n/l));
        ans += G[n/l]*((S[r]-S[l-1])%M)%M;
        ans %= M;
    }
    ans += M; ans %= M;
    cout << ans << endl;

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}