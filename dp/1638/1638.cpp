#include<cstdio>
#include<climits>
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef int ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 1001000
int m, n, a[N];
int vis[2020]; 
int kc;

int main() {
#ifdef D
    freopen("1638.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read(); m = read();
    rep(i, 1, n) {
        a[i] = read();
    }

    int l = 1;
    int ans = INT_MAX;
    int al, ar;
    rep(r, 1, n){
        kc += !(vis[a[r]]++);
        while (l < r && vis[a[l]] > 1) vis[a[l]]--, l++;
        if (kc == m && r - l < ans) al = l, ar = r, ans = r - l;
    }
    printf("%d %d\n", al, ar);

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}