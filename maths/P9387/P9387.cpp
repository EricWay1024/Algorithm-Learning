#include<bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
#ifdef D
    void dbg() {cerr << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cerr << a << ' '; dbg(x...);}
    #define logs(x...) {cerr << #x << " -> "; dbg(x);}
#else
    #define logs(...) {}
#endif
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long double ld; typedef double db;
template <typename T> vector<T>& operator<< (vector<T> &v, T &x) { v.emplace_back(x); return v; }
struct MyIn { 
    template <typename T> MyIn& operator>> (T &x) { x=0;bool s=0;char c=getchar();while(c>'9'||c<'0'){if(c=='-')s=1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}if(s)x=-x;return (*this); } 
} rin;
const int N2 = 112; const int N3 = 1123; const int N4 = 11234; const int N5 = 112345; const int N6 = 1123456; const int N7 = 11234567;

const int N = 100;
int mem[N]; // 初始化为-1
int solve(int n) {
    if (n == 0) return 0; // 初始状态
    if (mem[n] > -1) return mem[n];
    set<int> st; 
    rep(b,1,n) {
        int r = n - b;
        rep(a,0,r) {
            int c = r - a;
            int i = (a ^ c);
            st.insert(solve(i));
        }
    }
    for(int i=0; ; i++) {
        if (!st.count(i)) return mem[n]=i;
    }
}

int f2(int y, int x) {
    int ans = 0;
    rep(s,0,x-1) {
        rep(a,0,s) {
            int c = s - a;
            if ((a ^ c ^ x )== y) ans++;
        }
    }
    return ans;
}

const long long MOD = 1e9+7;

struct mll {
    long long s;
    mll (long long s=0):s(s) { r(); };
    void r() { s %= MOD; }
    void fr() { r(); s += MOD; r(); }
    mll operator+ (const mll &b) const { return s+b.s; }
    mll operator- (const mll &b) const { return s-b.s; }
    mll operator* (const mll &b) const { return s*b.s; }
    void operator+= (const mll &b) { s += b.s; r(); }
    void operator-= (const mll &b) { s -= b.s; r(); }
    void operator*= (const mll &b) { s *= b.s; r(); }
    operator long long() const { return s; }
    friend ostream& operator<< (ostream &out, mll &m) {
        m.fr(); out << m.s; return out;
    }
};

typedef mll ll;

ll quick_pow(ll a, long long b) {
    ll ans=1;
    for(; b; b >>= 1ll){
        if(b & 1ll) {
            ans *= a;
        }
        a *= a;
    }
    return ans;
}

ll f(long long s, long long x, long long i) {
    long long p = 1ll << i; 
    if (p == 2) {
        return x == 1 && s == 1;
    }
    long long q = 1ll << (i - 1);
    if (s < q) {
        if (x < q)
            return f(s, x, i - 1);
        else
            return (mll)2ll * f(s, x - q, i - 1);
    } else {
        if (x < q) return 0ll;
        else return (mll)q - f(p - 1 - s, p - 1 - x, i - 1);
    }
}

// 边长为p = 2^i的矩阵的第s行的完整求和
ll g(long long s, long long i) {
    long long p = 1ll << i; 
    if (p == 2) {
        return s == 1;
    }

    if (s < p / 2) {
        return (mll)3ll * g(s, i - 1);
    } else {
        return quick_pow(2, 2 * i - 2) - g(p - 1 - s, i - 1);
    }
}


// 边长为p = 2^i的矩阵第i行的第0, 1,..., x列求和
ll h(long long s, long long x, long long i) {
    long long p = 1ll << i; 
    if (p == 2) {
        return x == 1 && s == 1;
    }
    if (x == p - 1) return g(s, i);
    
    long long q = 1ll << (i - 1);
    if (s < q) {
        if (x < q) {
            return h(s, x, i - 1);
        } else {
            return g(s, i - 1) + ((mll)2ll * h(s, x - q, i - 1));
        }
    } else {
        if (x < q) {
            return 0ll;
        } else {
            return (g(s, i) - ((mll)(p - 1 - x) * (mll)q)) + h(p - 1 - s, p - 2 - x, i - 1); 
        }
    }

}

long long calc(long long n) {
    long long j = n % 4;
    if (j == 0) {
        return n;
    } else if (j == 1) {
        return 1;
    } else if (j == 2) {
        return n + 1;
    } else 
        return 0;
}

int main() {
#ifdef D
    freopen("test.in", "r", stdin);
#endif

    // mmst(mem, -1);
    // rep(i,1,30) {
    //     logs(i, solve(i));
    // }


    int n = 4;
    rep(i,0,(1<<n)-1) {
        ll ans = 0;
        rep(j,0,(1<<n)-1) {
            ans += f2(i, j);
            assert(f2(i, j) == f(i, j, 61));
            assert(ans == h(i, j, 61));

            cout << f2(i, j) << " ";

        }
        cout << endl;
        assert(ans == g(i, n));
    }
    exit(0);

    int T; 
    rin >> T; 
    while (T--) {
        long long n, m; 
        rin >> n >> m;
        long long s = calc(n) ^ m;
        mll ans = f(s, m, 61) + h(s, n, 61);
        cout << ans << endl;
    }
    return 0;
}