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

inline int idx(char c) { return c; }
const int N = 50004;
const int SIGMA = 133;
map<int, int> mp;

struct AC_Automaton {
    int sz;
    int ch[N][SIGMA];
    int f[N]; int cnt[N];
    int index[N];

    void init() { 
        sz = 0; 
        mmst(ch, 0); 
        mmst(cnt, 0); 
        mmst(index, 0);
    }

    void insert(char* s, int v) {
        int n = strlen(s); int u = 0;
        For(i, n) {
            int c = idx(s[i]);
            if (!ch[u][c]) ch[u][c] = ++sz;
            u = ch[u][c];
        }
        cnt[u]++;
        index[u] = v;
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
                else f[u] = ch[f[r]][c], q.push(u);
            }
        }
    }

    void query(char* s) {
        int n = strlen(s); int u = 0;
        For(i, n) {
            int c = idx(s[i]);
            u = ch[u][c];
            for(int j = u; j && cnt[j]; j = f[j]) {
                mp[index[j]]++;
            }
        }
    }
}my_ac;

char virus[1024][55];
char source[2000008];

int main() {
#ifdef D
    freopen("HDU-3065.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int n;
    while(~scanf("%d", &n)) {
        my_ac.init();
        mp.clear();
        rep(i, 1, n) {
            scanf("%s", virus[i]);
            my_ac.insert(virus[i], i);
        }
        my_ac.getFail();
        scanf("%s", source);
        my_ac.query(source);
        for(auto p : mp) {
            int a, b; tie(a, b) = p;
            if (!a) continue;
            printf("%s: %d\n", virus[a], b);
        }
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}