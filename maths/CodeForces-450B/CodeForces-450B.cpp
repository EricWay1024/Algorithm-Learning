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
void realmod(ll &x) {
    x %= MOD;
    x += MOD;
    x %= MOD;
}
struct Matrix {
    ll s[3][3];

    Matrix(int i=0) {
        mmst(s, 0);
        For(j,3) s[j][j]=i;
    }

    Matrix operator* (const Matrix &b) const {
        Matrix c;
        For(i,3){
            For(j,3){
                For(k,3){
                    c.s[i][j] += s[i][k] * b.s[k][j];
                    realmod(c.s[i][j]);
                }
            }
        }
        return c;
    }

    Matrix quick_pow(int b) {
        Matrix c = Matrix(1);
        Matrix a = (*this);
        for(; b; b>>=1) {
            if (b & 1) c = c * a;
            a = a * a;
        }
        return c;
    }

    void output() {
        For(i,3){
            For(j,3){
                cout << s[i][j] << " ";
            }
            cout << endl;
        }
    }
};




int main() {
#ifdef D
    freopen("CodeForces-450B.in", "r", stdin);
    clock_t TIMEA = clock();
#endif

    ll x=read(), y=read(), n=read();
    realmod(x); realmod(y);

    if (n >= 3) {
        Matrix p;
        p.s[0][0]=1, p.s[0][1]=-1;
        p.s[1][0]=1, p.s[2][1]=1;

        Matrix f;
        f.s[0][0]=y-x, f.s[1][0]=y, f.s[2][0]=x;

        p = p.quick_pow(n-3);
        f = p * f;
        cout << f.s[0][0] << endl;

    } else if (n == 2) {
        cout << y << endl;
    } else if (n == 1) {
        cout << x << endl;
    }



#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}