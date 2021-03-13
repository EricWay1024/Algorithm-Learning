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
const ll MOD = 1000000007;
int k;
void realmod(ll &x) { x %= MOD; }
ll ll_quick_pow(ll a, ll b) {
    ll ans=1;
    for(; b; b>>=1){
        if(b&1) {
            ans *= a; realmod(ans);
        }
        a *= a; realmod(a);
    }
    return ans;
}
struct Matrix {
    ll s[90][90];
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
        s[0][0] = 1;
        s[0][k+1] = 1;
        rep(i,0,k) {
            s[k+2+i][i+1]=1;
        }
        s[1][1]=1;
        rep(i,2,k+1){
            rep(j,1,i){
                s[i][j] = s[i-1][j] + s[i-1][j-1];
                realmod(s[i][j]);
            }
        }
        rep(i,0,k){
            rep(j,0,i){
                s[i+1][k+2+j] = ll_quick_pow(2, i-j) * s[i+1][j+1];
                realmod(s[i+1][k+2+j]);
            }
        }
    }

    void initA() {
        s[0][0]=1;
        rep(i,0,k){
            s[i+1][0] = ll_quick_pow(2, i+1);
        }
        rep(i,0,k){
            s[k+2+i][0] = 1;
        }
    }

    void output() {
        cout << endl;
        For(i,n){
            For(j,n){
                cout << s[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
};


int main() {
#ifdef D
    freopen("CodeForces-392C.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    ll n=read(); k=read();
    Matrix M = Matrix(k*2+3);
    M.init();
    // M.output();
    M = M.quick_pow(n-1);

    Matrix A = Matrix(k*2+3);
    A.initA();
    // A.output();

    A = M * A;
    cout << A[0][0] << endl;


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}