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
typedef unsigned int ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
const ll MOD = 10;
inline void realmod(ll &x) { x %= MOD; }
struct Matrix {
    ll s[40][40];
    int n;
    ll& operator() (int x, int y) {
        return s[x][y];
    }
    ll* operator[] (int x) {
        return s[x];
    }
    Matrix(int _n, int i=0) {
        mmst(s, 0);
        n = _n;
        if(i) For(j,n) s[j][j]=i;
    }

    Matrix operator* (const Matrix &b) const {
        Matrix c = Matrix(n);
        For(i,n){
            For(k,n){
                ll t=s[i][k];
                For(j,n){
                    c.s[i][j] += t * b.s[k][j];
                    realmod(c.s[i][j]);
                }
            }
        }
        return c;
    }

    Matrix operator+ (const Matrix &b) const {
        Matrix c = Matrix(n);
        For(i,n){
            For(j,n){
                c[i][j] = s[i][j] + b.s[i][j];
                realmod(c.s[i][j]);
            }
        }
        return c;
    }

    Matrix operator- (const Matrix &b) const {
        Matrix c = Matrix(n);
        For(i,n){
            For(j,n){
                c[i][j] = s[i][j] - b.s[i][j];
                realmod(c.s[i][j]);
            }
        }
        return c;
    }

    Matrix quick_pow(int b) {
        Matrix c = Matrix(n, 1);
        Matrix a = (*this);
        for(; b; b>>=1) {
            if (b & 1) c = c * a;
            a = a * a;
        }
        return c;
    }

    void init() {
        For(i, n) {
            For(j, n) {
                s[i][j] = read() % MOD;
                // realmod(s[i][j]);

            }
        }
    }

    void output() {
        For(i,n){
            For(j,n){
                if (j) putchar(32);
                printf("%d", s[i][j]);
            }
            putchar(10);
        }
        putchar(10);
    }
};

Matrix solve(Matrix A, int n) {
    if (n == 1) return A;
    Matrix S = solve(A, n>>1);
    Matrix ans = S + S * A.quick_pow(n>>1);
    if (n&1) ans = S + A.quick_pow(n);
    return ans;
}


int main() {
#ifdef D
    freopen("UVA-11149.in", "r", stdin);
    freopen("out", "w", stdout);
    clock_t TIMEA = clock();
#endif
    int n, k;
    while(1){
        n=read(), k=read();
        if (!n && !k) break;
        Matrix A = Matrix(n);
        A.init();
        Matrix B = solve(A, k);
        B.output();
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}