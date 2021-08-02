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
const int M = 20071027;
const int maxnode = 1e6;
const int sigma_size = 26;

inline int idx(char c) { return c - 'a'; }
vector<int> xs;
struct Trie {
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int dp[maxnode];
    int sz;
    Trie () { init(); }
    void init() { sz = 1; mmst(ch[0], 0); }

    void insert(char *s) {
        int u = 0, n = strlen(s);
        For(i, n) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                mmst(ch[sz], 0); val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u]++;
    }

    void query(char *s, int suf, int n) {
        int u = 0;
        dp[suf] = 0;
        rep(i, suf, n-1) {
            int c = idx(s[i]);
            if (!ch[u][c]) break;
            u = ch[u][c];
            if (val[u]) { dp[suf] = (dp[suf] + (val[u] * dp[i + 1]) % M) % M; }
        }
    }

    int naive_query(char *s) {
        int u = 0, n=strlen(s);
        For(i, n) {
            int c = idx(s[i]);
            if (!ch[u][c]) break;
            u = ch[u][c];
        }
        return val[u];
    }
}my_trie;

char s[300100];
char tmp[300100];

// int mem[300100];
// int dp(int i) {
//     if (mem[i] > -1) return mem[i];
//     if (i == slen) return 1;
//     my_trie.query(s + i);
//     int ans = 0;
//     for(int x : xs) {
//         ans += dp(i + x + 1);
//         ans %= M;
//     }
//     return mem[i] = ans;
// }

int main() {
#ifdef D
    freopen("UVALive-3942.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int kase = 0;
    while(~scanf("%s", s)) {
        my_trie.init();
        int n = strlen(s);
        int k=read();
        For(i, k) {
            scanf("%s", tmp);
            my_trie.insert(tmp);
        }
        my_trie.dp[n] = 1;
        rev(i, n-1, 0) {
            my_trie.query(s, i, n);
        }
        printf("Case %d: %d\n", ++kase, my_trie.dp[0]);
        
    }



#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}