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

inline int read_day() {
    char c=getchar();
    while(c>'Z' || c<'A') { c = getchar(); }
    if (c == 'M') {getchar(); getchar(); return 1; }
    if (c == 'W') {getchar(); getchar(); return 3; }
    if (c == 'F') {getchar(); getchar(); return 5; }
    getchar(); c = getchar();
    if (c == 'E') {return 2;}
    if (c == 'U') {return 4;}
    if (c == 'N') {return 0;}
    if (c == 'T') {return 6;}
    return -1;
}

ll quick_pow(ll a, ll b, ll M) {
    ll ans=1; a%=M;
    for(; b; b>>=1, a=a*a%M) if (b & 1) ans = ans*a%M;
    return ans;
}
ll inv(ll a, ll M) {
    return quick_pow(a, M-2, M);
}

#define N 310
struct AugMatrix {
    int mt[N][N];
    int n, m; // m: # of rows/equations, n: # of cols/vars
    int P; // all entries mod P
    AugMatrix(int n, int m, int P):n(n), m(m), P(P) {
        mmst(mt, 0);
        rep(i,1,m){
            int k=read(); int sd = read_day(), fd = read_day();
            mt[i][n+1] = (fd - sd + 1 + 7)%7;
            rep(j,1,k) {
                int tmp = read();
                mt[i][tmp]++;
                mt[i][tmp] %= P;
            }
        }
    }

    void output() {
        rep(i,1,m){
            rep(j,1,n+1){
                cout << mt[i][j] << ' ';
            }
            cout << endl;
        }
    }
    
    void swap_rows(int i, int j) {
        if (i == j) return;
        rep(k,1,n+1) swap(mt[i][k], mt[j][k]);
    }
    void scalar_prod(int i, int t) {
        if (t == 1) return;
        rep(k,1,n+1) mt[i][k] = mt[i][k] * t % P;
    }
    void mul_and_add(int i, int j, int t) {
        rep(k,1,n+1) mt[i][k] = (mt[i][k] + mt[j][k] * t % P) % P;
    }

    ll gauss() {
        int r=1;
        rep(c,1,n) {
            int k=-1;
            rep(j,r,m) if (mt[j][c]) { k = j; break; }
            if (k == -1) continue;
            else swap_rows(r, k);
            scalar_prod(r, inv(mt[r][c], P));
            rep(j,1,m) if (j != r && mt[j][c]) {
                mul_and_add(j, r, P-mt[j][c]);
            }
            r++;
        }
        rep(i,1,m){
            mt[i][n+1] += P; mt[i][n+1] %= P;
        }

        rep(i,r,m){
            if (mt[i][n+1] != 0) return 0;
        }

        // logs(n, r);
        // return 1<<(n+1-r);
        if (n >= r) return 2;
        else return 1;
    }

    void output_ans() {
        rep(i,1,n){
            if (mt[i][n+1] <= 2) mt[i][n+1] += 7; 
            printf("%d%c",  mt[i][n+1], n-i?' ':'\n');
        }
    }
};

int main() {
#ifdef D
    freopen("POJ-2947.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n, m;
    while((n=read()) && (m=read())){
        AugMatrix A(n, m, 7);
        // A.output();
        ll ret = A.gauss();
        // A.output();
        // cout << ret << endl;
        if (ret == 1) {
            A.output_ans();
        } else if (ret == 0) {
            puts("Inconsistent data.");
        } else {
            puts("Multiple solutions.");
        }
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}