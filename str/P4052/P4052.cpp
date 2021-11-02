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

const int L = 110;
const int K = 65;
const int N = L * K;
const int SIGMA = 26;
const int M = 1e4 + 7;
#define idx(x) (x-'A')

struct AC_Automaton {
    int sz;
    int ch[N][SIGMA];
    int f[N]; int cnt[N];
    int dp[110][N];

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

    int query(int m) {
        mmst(dp, 0);
        dp[0][0] = 1;
        For(i, m) {
            rep(u, 0, sz) {
                For(c, SIGMA) {
                    if (!cnt[ch[u][c]]) {
                        dp[i+1][ch[u][c]] += dp[i][u];
                        dp[i+1][ch[u][c]] %= M;
                    }
                }
            }
        }

        int ans = 0;
        rep(u, 0, sz) {
            ans += dp[m][u];
            ans %= M;
        }
        return ans;
    }
}my_ac;


char s[L];


ll quick_pow(ll a, ll b) {
    ll ans=1; 
    for(a%=M; b; b>>=1, a=a*a%M) if (b&1) ans=ans*a%M;
    return ans;
}

int main() {
#ifdef D
    freopen("P4052.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n, m;
    cin >> n >> m;
    my_ac.init();
    rep(i, 1, n) {
        cin >> s;
        my_ac.insert(s);
    }
    my_ac.getFail();
    int ans = (quick_pow(26, m) - my_ac.query(m) + M) % M;
    cout << ans << endl;


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}