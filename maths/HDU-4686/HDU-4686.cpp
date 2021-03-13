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
const ll MOD = 1000000007ll;
struct mll {
    ll s;
    mll (ll s=0):s(s) { r(); };
    void r() { s %= MOD; }
    void fr() { r(); s += MOD; r(); }
    mll operator+ (const mll &b) const { return s+b.s; }
    mll operator- (const mll &b) const { return s-b.s; }
    mll operator* (const mll &b) const { return s*b.s; }
    void operator+= (const mll &b) { s += b.s; r(); }
    void operator-= (const mll &b) { s -= b.s; r(); }
    void operator*= (const mll &b) { s *= b.s; r(); }
};

ll n; mll A1, A2, B1, B2, a0, b0;
struct Matrix {
    mll s[5][5];
    int n;
    mll& operator() (int x, int y) {
        return s[x][y];
    }
    mll* operator[] (int x) {
        return s[x];
    }
    Matrix(int n, int i=0):n(n) {
        mmst(s, 0);
        if(i) For(j,n) s[j][j]=i;
    }

    Matrix operator* (const Matrix &b) const {
        Matrix c = Matrix(n);
        For(i,n){
            For(k,n){
                mll t=s[i][k];
                For(j,n){
                    c.s[i][j] += t * b.s[k][j];
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

    Matrix quick_pow(ll b) {
        Matrix c = Matrix(n, 1);
        Matrix a = (*this);
        for(; b; b>>=1) {
            if (b & 1) c = c * a;
            a = a * a;
        }
        return c;
    }

    void init() {
        s[0][0]=A1*B1, s[0][1]=A1*B2, 
        s[0][2]=A2*B1, s[0][3]=A2*B2, 

        s[0][4]=s[0][0]*a0*b0;
        s[0][4]+=s[0][1]*a0;
        s[0][4]+=s[0][2]*b0;
        s[0][4]+=s[0][3];

        s[1][1]=A1, s[1][3]=A2, s[1][4]=a0*A1+A2;
        s[2][2]=B1, s[2][3]=B2, s[2][4]=b0*B1+B2;

        s[3][3]=1, s[3][4]=1;
        s[4][4]=1;

    }

    void initB() {
        s[4][0]=1;
    }

    void output() {
        For(i,n){
            For(j,n){
                cout << s[i][j].s << " ";
            }
            cout << endl;
        }
    }
};

int main() {
#ifdef D
    freopen("HDU-4686.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    while(~scanf("%lld", &n)) {
        a0=read(), A1=read(), A2=read();
        b0=read(), B1=read(), B2=read();

        if (n==0) {
            puts("0");
            continue;
        }
        Matrix A = Matrix(5);
        A.init();
        A = A.quick_pow(n-1);
        Matrix B = Matrix(5);
        B.initB();
        B = A * B;
        mll ans = B[0][0] + a0 * b0;
        printf("%lld\n", ans);
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}