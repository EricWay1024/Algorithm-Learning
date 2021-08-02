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

const int N = 0.5e6;
const int sigma_size = 130;
inline int idx(char c) { return c; }
int ans = 0;
vector<int> virus;
queue<int> q;

struct AC_Automaton {
    int f[N];
    int ch[N][sigma_size];
    int val[N];
    int sz;
    bool vis[N];
    void init() { sz = 1; }

    void insert(char *s, int v) {
        int n = strlen(s), u = 0;
        For(i, n) {
            int c = idx(s[i]);
            if (!ch[u][c]) ch[u][c] = sz++;
            u = ch[u][c];
        }
        val[u] = v;
    }

    void getFail() {
        while(q.size()) q.pop();

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

    void find(char *T) {
        int n = strlen(T), u = 0; 
        virus.clear();
        mmst(vis, 0); // important
        For(i, n) {
            int c = idx(T[i]);
            u = ch[u][c];
            for(int j = u; j && !vis[j] && val[j]; j = f[j]) {
                virus.push_back(val[j]);
                vis[j] = 1;
                if (virus.size() >= 3) return;
            }
        }
    }

}my_ac;

char tmp[N];

int main() {
#ifdef D
    freopen("HDU-2896.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int k=read();
    my_ac.init();
    rep(i, 1, k) {
        scanf("%s", tmp);
        my_ac.insert(tmp, i);
    }
    my_ac.getFail();
    int l=read();
    int total = 0;
    rep(i, 1, l) {
        scanf("%s", tmp);
        my_ac.find(tmp);
        if (virus.size()) {
            total++;
            sort(virus.begin(), virus.end());
            printf("web %d:", i);
            for(auto v : virus) {
                printf(" %d", v);
            }
            putchar('\n');
        }
    }
    printf("total: %d\n", total);

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}