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

const int N = 1e6+99;
const int sigma_size = 26;
inline int idx(char c) { return c - 'a'; }
int ans = 0;
char tmp[N];

struct AC_Automaton {
    int f[N];
    int ch[N][sigma_size];
    int val[N];
    int sz;
    bool vis[N];
    void init() { sz = 1; }

    void insert(char *s) {
        int n = strlen(s), u = 0;
        For(i, n) {
            int c = idx(s[i]);
            if (!ch[u][c]) ch[u][c] = sz++;
            u = ch[u][c];
        }
        val[u]++;
    }

    void getFail() {
        queue<int> q;
        For(c, sigma_size) {
            int u = ch[0][c];
            if (u) { f[u] = 0; q.push(u); }
        }

        while(q.size()) {
            int r = q.front(); q.pop();
            For(c, sigma_size) {
                int u = ch[r][c];
                if (!u) { ch[r][c] = ch[f[r]][c]; continue; }
                else q.push(u), f[u] = ch[f[r]][c];
            }
        }
    }

    int find(char *T) {
        int n = strlen(T);
        int u = 0; int ans = 0;
        For(i, n) {
            int c = idx(T[i]);
            u = ch[u][c];
            for(int j = u; j && !vis[j]; j = f[j]) ans += val[j], vis[j] = 1;
        }
        return ans;
    }

}my_ac;


int main() {
#ifdef D
    freopen("P3796.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n;
    while((n=read())) {
        rep(i, 1, n) {
            scanf("%s", tmp);
        }
        scanf("%s", tmp);
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}