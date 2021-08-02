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
const int N = 1e5+100;
inline int idx(char c) { return c - 'a'; }
struct Trie {
    int ch[N][26];
    int val[N];
    int sz;
    void init() { sz = 1; mmst(ch[0], 0); }

    void insert(string &s) {
        int n=s.length(), u=0;
        For(i, n) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                mmst(ch[sz], 0); val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
            val[u]++;
        }
    }

    string query(string &s) {
        string res = "";
        int n=s.length(), u=0;
        For(i, n) {
            int c = idx(s[i]);
            u = ch[u][c];
            res.push_back(s[i]);
            if (val[u] == 1) {
                break;
            }
        }
        return res;
    }
}my_trie;


vector<string> dict;

int main() {
#ifdef D
    freopen("POJ-2001.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    string tmp;
    my_trie.init();
    while(cin >> tmp) {
        dict.push_back(tmp);
        my_trie.insert(tmp);
    }
    For(i, dict.size()) {
        string &w = dict[i];
        cout << w << ' ' << my_trie.query(w) << endl;
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}