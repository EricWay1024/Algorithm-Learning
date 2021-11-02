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

const ll MOD = 1000;
void realmod(ll &x) { x %= MOD; x += MOD; x %= MOD; }
struct Matrix {
    ll s[50][50];
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
        For(j,n) s[j][j]=i;
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
            }
        }
        return c;
    }

    Matrix operator- (const Matrix &b) const {
        Matrix c = Matrix(n);
        For(i,n){
            For(j,n){
                c[i][j] = s[i][j] - b.s[i][j];
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
        For(i,n){
            ll x=read();
            For(j,x){
                ll b=read();
                s[i][b] = 1;
            }
        }
    }

    void output() {
        For(i,n){
            For(j,n){
                cout << s[i][j] << " ";
            }
            cout << endl;
        }
    }
};


void solve() {
    ll n=read(), r=read();
    Matrix A = Matrix(n, 0);
    For(i, n) {
        A(i, 0) = read();
    }

    Matrix M = Matrix(n, 0);
    M.init();

    A = M.quick_pow(r) * A;

    For(i, n) {
        if (i) putchar(32);
        printf("%d", (int)A(i, 0));
    }
    putchar(10);

}
int main() {
#ifdef D
    freopen("UVA-11551.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read();
    rep(cas,1,T){
        solve();
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}