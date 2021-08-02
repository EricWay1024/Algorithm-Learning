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

const db pi = acos(-1.0);
const int N = 2e6+100;
struct cp {
    db x, y;
    cp(db x=0, db y=0):x(x), y(y) {}
    cp operator+ (const cp &b) const { return cp(x+b.x, y+b.y); }
    cp operator- (const cp &b) const { return cp(x-b.x, y-b.y); }
    cp operator* (const cp &b) const { return cp(x*b.x-y*b.y, x*b.y+y*b.x); }
    cp conj() { return cp(x, -y); }
    int to_int() { return (int)(x + .5); }
};
// typedef complex<double> cp;

struct FFT {
    int R[N];
    int n, m, L;
    void init(int deg_a, int deg_b) {
        m = deg_a+deg_b;
        for(n=1, L=0; n<=m; n<<=1, L++);
        For(i, n) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
    }

    void fft(cp* a, int f) {
        For(i, n) if (i < R[i]) swap(a[i], a[R[i]]);
        for(int i=1; i<n; i<<=1) {
            cp wn(cos(pi/i), f*sin(pi/i));
            for(int p=i<<1, j=0; j<n; j+=p) {
                cp w(1, 0);
                For(k, i) {
                    cp x = a[j+k];
                    cp y = w * a[j+k+i];
                    a[j+k] = x + y;
                    a[j+k+i] = x - y;
                    w = w * wn;
                }
            }
        }
        if (f == -1) For(i, n) a[i].x /= n;
    }

    int poly_mul(cp* a, cp* b, cp* c) {
        fft(a, 1);
        fft(b, 1);
        For(i, n) c[i] = a[i] * b[i];
        fft(c, -1);
        return m; // return value is deg_c
    }
};


int main() {
#ifdef D
    // freopen("", "r", stdin);
    clock_t TIMEA = clock();
#endif


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}