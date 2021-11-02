#include<bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define endl '\n'
#define mmst(a,x) memset(a, x, sizeof(a))
inline int read(){
    int x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

const int N=1000000+3;
const int TOT=78498+10;
const int M=104857601;
const int MOD=M-1;
int quick_pow(int a, int b){
    int ans=1;
    for(; b; b>>=1){
        if (b&1) ans = (1ll*ans*a)%M;
        a=(1ll*a*a)%M;
    }
    return ans;
}

int inv(int p) {
    return quick_pow(p, M-2);
}

int fac_pow(int n) {
    int res=1;
    rep(i,2,n) res=(1ll*res*i)%M;
    return quick_pow(res, 2*n);
}

int mu[N]; short flag[N]; int p[TOT], tot;
void getMu(int n) {
    mu[1]=1;
    rep(i,2,n){
        if(!flag[i]) p[++tot]=i, mu[i]=-1;
        for(int j=1; j<=tot && p[j]<=n/i; ++j){
            int m=i*p[j];
            flag[m]=1;
            if(i%p[j] == 0) {
                mu[m] = 0;
                break;
            } else {
                mu[m] = mu[i] * mu[p[j]];
            }
        }
    }
    rep(i,2,n) mu[i] += mu[i-1];
}

int calc_f(int x) {
    int ans=0; int t;
    for(int l=1, r; l<=x; l=r+1){
        r=min(x/(x/l), x);
        t=(x/l)%MOD; t=(1ll*t*t)%MOD;
        ans = ((1ll*ans)+((1ll*t*(mu[r]-mu[l-1]))%MOD))%MOD;
    }
    return ans;
}

int main() {
#ifdef D
    freopen("P5221.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n=read();
    getMu(n+10);
    
    int ans=1; int f;
    for(int l=1, r; l<=n; l=r+1){
        r=min(n/(n/l), n);
        f=1; rep(j,l,r) f=(1ll*f*j)%M; 
        f=quick_pow(f, calc_f(n/l));
        ans=(1ll*ans*f)%M;
    }

    ans = quick_pow(inv(ans), 2);
    ans=(1ll*ans*fac_pow(n))%M;
    printf("%d\n", ans);

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}