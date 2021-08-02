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
// #include<unordered_map>
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
const int N = 1000010;
char s[N];
int n, sa[N], rk[N << 1], oldrk[N << 1], id[N], cnt[N];
int m;
int tmp[N];

void output(int *a, int n) {
    rep(i,1,n) cout << a[i] << ' ';
    cout << endl;
}

void radix_sort(int *a, int *b, int *c) {
    mmst(cnt, 0);
    rep(i,1,n) ++cnt[a[i]];
    rep(i,1,m) cnt[i] += cnt[i-1];
    rev(i,n,1) b[cnt[a[i]]--] = c[i];  
}

int a[] = {0, 1, 2, 5, 5, 4};
int b[100];
bool cmp(int x, int y, int w) {
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}

int main() {
#ifdef D
    freopen("P3809.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    scanf("%s", s+1);
    n = strlen(s+1);
    m = max(n, 300);
    int p, w;
    rep(i,1,n) ++cnt[rk[i] = s[i]];
    rep(i,1,m) cnt[i] += cnt[i-1];
    rev(i,n,1) sa[cnt[rk[i]]--] = i;
    output(sa, n);

    for(w=1;; w<<=1, m=p) {
        p = 0;
        rev(i,n,n-w+1) id[++p] = i;
        rep(i,1,n) if (sa[i] > w) id[++p] = sa[i] - w;
        logs(id); output(id, n);
        mmst(cnt, 0);
        rep(i,1,n) ++cnt[tmp[i] = rk[id[i]]];
        rep(i,1,m) cnt[i] += cnt[i-1];
        rev(i,n,1) sa[cnt[tmp[i]]--] = id[i];
        memcpy(oldrk, rk, sizeof(rk));
        p = 0;
        rep(i,1,n) {
            rk[sa[i]] = cmp(sa[i], sa[i-1], w) ? p : ++p;
        }
        if (p == n) {
            rep(i,1,n) sa[rk[i]] = i;
            break;
        }
    }
    
    rep(i,1,n) printf("%d%c", sa[i], i<n?32:10);


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}