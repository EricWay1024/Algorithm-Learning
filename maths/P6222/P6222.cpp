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
typedef unsigned int ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

ll quick_pow(ll a, ll b) {
    ll ans=1;
    for(; b; b>>=1, a=(a*a)){
        if(b&1) ans=(ans*a);
    }
    return ans;
}

const int N = 1e7+10; ll k;
ll h[N]; ll p[N/10], tot; short flag[N];
ll f[N]; ll S[N]; ll G[N/2];
void seive(int n){
    h[1]=1; f[1]=1;
    rep(i,2,n){
        if (!flag[i]) p[++tot]=i, h[i]=i-1, f[i]=quick_pow(i, k);
        for(int j=1; j<=tot && p[j]<=n/i; ++j){
            int m=i*p[j];
            flag[m]=1;

            f[m]=f[i]*f[p[j]];

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
        S[i] = S[i-1]+f[i];
    }

    rep(i,1,n/2){
        G[i] = G[i-1]+((((S[2*i]+S[2*i-1]))-2u*S[i]));
    }

    rep(i,1,n/2){
        S[i] = (S[i-1]+(h[i]*f[i]));
    }
}


int main() {
#ifdef D
    freopen("P6222.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read(), MAXN=read(); k=read();
    seive(MAXN<<1);
    while(T--){
        ll n=read();
        ll ans=0;
        for(ll l=1, r; l<=n; l=r+1){
            r=min(n, n/(n/l));
            ans += G[n/l]*((S[r]-S[l-1]));
        }
        cout << ans << endl;
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}