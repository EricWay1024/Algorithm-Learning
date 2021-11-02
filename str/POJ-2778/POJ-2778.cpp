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
typedef int ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}


const int L = 11;
const int K = 11;
const int N = L * K;
const int SIGMA = 4;
const int M = 100000;
const ll MOD = 100000;

struct mll {
    ll s;
    mll (ll s=0):s(s) { r(); };
    void r() { s %= MOD; }
    void fr() { r(); s += MOD; r(); }
    mll operator+ (const mll &b) const { return s+b.s; }
    mll operator- (const mll &b) const { return s-b.s; }
    mll operator* (const mll &b) const { return mll(1ll * s * b.s % MOD); }
    void operator+= (const mll &b) { s += b.s; r(); }
    void operator-= (const mll &b) { s -= b.s; r(); }
    void operator*= (const mll &b) { s *= b.s; r(); }
    operator ll() const { return s; }
    friend ostream& operator<< (ostream &out, mll &m) {
        m.fr(); out << m.s; return out;
    }
};


struct Matrix {
    mll s[N][N];
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

    Matrix quick_pow(long long b) {
        Matrix c = Matrix(n, 1);
        Matrix a = (*this);
        for(; b; b>>=1) {
            if (b & 1) c = c * a;
            a = a * a;
        }
        return c;
    }

    mll my_count() {
        mll res = 0;
        For(i,n) res += s[0][i];
        return res;
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

inline int idx(char c) {
    switch (c)
    {
    case 'A':
        return 0;
    case 'T':
        return 1;
    case 'C':
        return 2;
    case 'G':
        return 3;
    }
    return -1;
}

struct AC_Automaton {
    int sz;
    int ch[N][SIGMA];
    int f[N]; int cnt[N];

    void init() { 
        sz = 0; 
        mmst(ch, 0); 
        mmst(cnt, 0); 
    }

    void insert(char* s) {
        int n = strlen(s); int u = 0;
        For(i, n) {
            int c = idx(s[i]);
            if (!ch[u][c]) ch[u][c] = ++sz;
            u = ch[u][c];
        }
        cnt[u] = 1;
    }

    void getFail() {
        queue<int> q;
        mmst(f, 0);
        For(c, SIGMA) {
            if (ch[0][c]) q.push(ch[0][c]);
        }
        while(q.size()) {
            int r = q.front(); q.pop();
            For(c, SIGMA) {
                int &u = ch[r][c];
                if (!u) u = ch[f[r]][c];
                else {
                    f[u] = ch[f[r]][c]; 
                    cnt[u] |= cnt[f[u]];
                    q.push(u);
                }
            }
        }
    }

    Matrix query() {
        Matrix t(sz + 1);
        rep(u, 0, sz) {
            For(c, SIGMA) {
                if (!cnt[ch[u][c]]) 
                    t.s[u][ch[u][c]] = t.s[u][ch[u][c]] + mll(1);
            }
        }
        return t;
    }
}my_ac;

char s[L];

int main() {
#ifdef D
    freopen("POJ-2778.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    my_ac.init();
    long long m, n;
    cin >> m >> n;
    rep(i, 1, m) {
        scanf("%s", s);
        my_ac.insert(s);
    }
    my_ac.getFail();
    Matrix A = my_ac.query();
    A = A.quick_pow(n);
    cout << A.my_count() << endl;
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}