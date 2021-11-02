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
typedef double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
const ld eps = 1e-5;

struct Poly {
    ld s[30];
    ld& operator[] (int i) {
        return s[i];
    }
    Poly (char var, ld v=0) {
        mmst(s, 0);
        if (var == 1) {
            s[27] = v;
        } else {
            s[var - 'a' + 1] = v;
        }
    }
    
    Poly operator+ (const Poly &b) const {
        Poly c(1, 0);
        rep(i,1,27) c[i] = s[i] + b.s[i];
        return c;
    }

    Poly operator- (const Poly &b) const {
        Poly c(1, 0);
        rep(i,1,27) c[i] = s[i] - b.s[i];
        return c;
    }

    Poly operator* (const ld &t) const {
        Poly c(1, 0);
        rep(i,1,27) c[i] = s[i] * t;
        return c;
    }

    Poly operator/ (const ld &t) const {
        Poly c(1, 0);
        rep(i,1,27) c[i] = s[i] / t;
        return c;
    }
    void output() {
        rep(i,1,26){
            if (s[i])
            cout << s[i] << (char)('a'+i-1) << '+';
        }
        cout << s[27] << endl;
    }

};

string s;

Poly get_from_s(int &i) {
    Poly res(1, 0);
    i++; // remove '('
    int cnt = 0;
    while(1) {
        while(s[i] == ' ') i++;
        if (s[i] == '(') {
            res = res + get_from_s(i);
            cnt++;
        } 
        
        else if (s[i] == ')') {
            i++;
            break;
        } 
        
        else if (s[i] >= 'a' && s[i] <= 'z') {
            res = res + Poly(s[i], 1);
            i++;
            cnt++;
        } 
        
        else {
            int x = 0, sign = 1;
            if (s[i] == '-') sign = -1, i++;
            while(s[i] >= '0' && s[i] <= '9') {
                x *= 10; x += s[i] - '0'; i++;
            }
            // logs(x)
            // logs(i, s[i])
            res = res + Poly(1, sign * x);
            cnt++;
        }
    }
    res = res / (ld)cnt;
    // cout << "---" << endl;
    // res.output();
    return res;
}

Poly parser() {
    int i=0;
    while(s[i] > 'z' || s[i] < 'a') i++;
    Poly left(s[i], 1);
    while(s[i] != '(') i++;
    Poly right = get_from_s(i);
    Poly equation = left - right;
    // equation.output();
    return equation;
}

struct Gauss {
    ld mt[30][30];
    int n;
    bool free[30];
    ld ans[30];

    Gauss(int n):n(n) {mmst(mt, 0);}
    void init(int i, Poly &e) {
        rep(k,1,n) mt[i][k] = e[k];
        mt[i][n+1] = -e[27];
    }
    void swap_rows(int i, int j) {
        rep(k,1,n+1) swap(mt[i][k], mt[j][k]);
    }
    void scalar_prod(int i, ld t) {
        rep(k,1,n+1) mt[i][k] *= t;
    }
    void mul_and_add(int i, int j, ld t) {
        rep(k,1,n+1) mt[i][k] += mt[j][k] * t;
    }

    int dcmp(ld x) {
        if (abs(x) < eps) return 0;
        return x > 0 ? 1 : -1;
    }
    bool gauss() {
        int r=1;
        rep(c,1,n){
            int k=r;
            rep(j,r+1,n) if (abs(mt[j][c]) > abs(mt[k][c])) k = j;
            if (k != r) swap_rows(r, k);
            if (dcmp(mt[r][c]) == 0) continue;
            scalar_prod(r, 1/mt[r][c]);
            rep(j,1,n) if (j != r && dcmp(mt[j][c]) != 0) {
                mul_and_add(j, r, -mt[j][c]);
            }
            r++;
        }

        mmst(free, -1);
        rep(i,r,n) {
            if (dcmp(mt[i][n+1])) {
                return 0;
            }
        }

        rep(i,1,n){
            int cnt = 0;
            int c = -1;
            rep(j,1,n) {
                if (dcmp(mt[i][j]) && free[j]) {
                    cnt++;
                    c = j;
                }
            }
            if (cnt == 1) {
                ld tmp = mt[i][n+1];
                rep(j,1,n){
                    if (j != c && dcmp(mt[i][j])) {
                        tmp -= mt[i][j] * ans[j];
                    }
                }
                ans[c] = tmp / mt[i][c];
                free[c] = 0;
                if (!dcmp(ans[c])) ans[c] = 0;
            }
        }
        return 1;
    }

    void output() {
        rep(i,1,n){
            rep(j,1,n+1){
                cout << mt[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void output_ans() {
        rep(i,1,n){
            printf("Expected score for %c ", 'a'-1+i);
            if (free[i]) printf("undefined\n");
            else printf("= %.3lf\n", (db)ans[i]);
        }
    }
};

int main() {
#ifdef D
    freopen("POJ-1487.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n;
    int cas=0;
    while(1){
        getline(cin, s);
        n=0;
        For(i,s.length()-1){
            n*=10; n+=s[i]-'0';
        }
        // n=read(); getline(cin, s);
        if (n == 0) break;

        Gauss G(n);

        rep(i,1,n){
            getline(cin, s);
            Poly e = parser();
            G.init(i, e);
        }
        G.gauss();
        // G.output();

        if (cas) printf("\n");
        printf("Game %d\n", ++cas);
        G.output_ans();

    }


#ifdef D
    clock_t TIMEB=clock();
    // printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}