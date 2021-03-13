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


ll MOD = 1000;
int n, d;
void realmod(ll &x) { x %= MOD; }

struct CirMatrix {
    ll s[500];
    ll& operator() (int x, int y) {
        return s[(y-x+n)%n];
    }
    CirMatrix(int _d=d) {
        mmst(s, 0);
        if (_d>-1) 
            rep(j, -_d, _d) {
                s[(j+n) % n] = 1;
            }
    }

    void output() {
        CirMatrix c = (*this);
        For(i,n){
            For(j,n){
                cout << c(i, j) << " ";
            }
            cout << endl;
        }
    }
};

CirMatrix operator* (CirMatrix a, CirMatrix b) {
    CirMatrix c = CirMatrix(-1);
    For(i,n){
        For(j,n){
            c(0, j) += a(0, i) * b(i, j);
            realmod(c(0, j));
        }
    }
    return c;
}


CirMatrix quick_pow(CirMatrix a, int b) {
    CirMatrix c = CirMatrix(-1);
    c(0, 0) = 1;

    for(; b; b>>=1) {
        if (b & 1) c = c * a;
        a = a * a;
    }

    return c;
}

struct Matrix {
    ll s[500];
    ll& operator() (int x, int y) {
        return s[y];
    }
    void input() {
        For(i, n) s[i]=read();
    }
    void output() {
        For(i, n) {
            if (i) putchar(32);
            printf("%lld", s[i]);
        }
        putchar(10);
    }
};

Matrix operator* (CirMatrix a, Matrix b) {
    Matrix c;
    mmst(c.s, 0);
    For(i, n) {
        For(j, n) {
            c(0, i) += b(0, j) * a(j, i);
            realmod(c(0, i));
        }
    }
    return c;
}

int main() {
#ifdef D
    freopen("UVA-1386.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int m, k;
    while(~scanf("%d%d%d%d", &n, &m, &d, &k)) {
        MOD = m;
        Matrix A;
        A.input();
        CirMatrix M;
        Matrix B = quick_pow(M, k) * A;
        B.output();
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}