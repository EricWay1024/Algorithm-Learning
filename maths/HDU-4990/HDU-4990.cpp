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

ll MOD;
void realmod(ll &x) {
    x %= MOD;
    x += MOD;
    x %= MOD;
}
struct Matrix {
    ll s[2][2];
    int n;

    ll& operator() (int x, int y) {
        return s[x][y];
    }

    Matrix(int _n, int i=0) {
        mmst(s, 0);
        n = _n;
        For(j,n) s[j][j]=i;
    }

    Matrix operator* (const Matrix &b) const {
        Matrix c = Matrix(n);
        For(i,n){
            For(j,n){
                For(k,n){
                    c.s[i][j] += s[i][k] * b.s[k][j];
                    realmod(c.s[i][j]);
                }
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
        s[0][0]=4;
        s[0][1]=2;
        s[1][0]=0;
        s[1][1]=1;
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



int main() {
#ifdef D
    freopen("HDU-4990.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF) {
        MOD = m;
        Matrix p = Matrix(2, 0); 
        p.init();

        Matrix a = Matrix(2, 0);
        a(0,0)=0; a(1,0)=1;
        if (n&1) {
            p = p.quick_pow((n-1)/2);
            a = p * a;
            cout << ((a(0, 0) * 2 + 1)%MOD) << endl;

        } else {
            p = p.quick_pow(n/2);
            a = p * a;
            cout << a(0, 0) << endl;
        }
            
    } 


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}