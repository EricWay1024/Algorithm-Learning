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
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
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

const int P=6e6;
ll fs[P][2]; int tot;
void factor(ll n) {
    rep(i,2,sqrt(n)){
        if(n%i==0){
            int c=0;
            while(n%i==0){
                c++;
                n/=i;
            }
            fs[++tot][0] = i;
            fs[tot][1] = c;
        }
    }

    if (n > 1) {
        fs[++tot][0] = n;
        fs[tot][1] = 1;
    }
}

ll quick_pow(ll a, ll b) {
    ll ans=1;
    for(; b; b>>=1, a*=a) if (b&1) ans*=a;
    return ans;
}




int main() {
#ifdef D
    freopen("POJ-1091.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    // factor(1024);
    // rep(i,1,tot){
    //     cout << fs[i][0] << " " << fs[i][1] << endl;
    // }
    ll n=read(), m=read();
    if (m == 1) {
        cout << 1 << endl;
    } else {
        factor(m);
        ll ans=1;
        rep(i,1,tot){
            ll &p=fs[i][0]; ll &k=fs[i][1];
            ll t1 = quick_pow(p, n)-1;
            ll t2 = quick_pow(p, (k-1)*n);
            ans *= t1 * t2;
        }
        cout << ans << endl;
    }



#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}