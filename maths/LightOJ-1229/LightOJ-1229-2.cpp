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
#include<utility>
#include<vector>
#include<numeric>
#include<functional>
// #include<cstdint>
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
// #define logs(x...) {cout << #x << " -> "; dbg(x);}
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


const int N=214;
int mem[N];
string tmp;
string game;
int sg(int n) {
    if (n < 0) return 0;
    if (mem[n]>-1) return mem[n];
    short vis[N] = {0};
    rep(i,0,n-1) vis[sg(i-2) ^ sg(n-1-i-2)] = 1;
    for(int i=0; ; ++i) if (!vis[i]) return mem[n]=i;
}

void init() {
    mmst(mem, -1);
}
bool check(int m, int len) {
    game = tmp;
    if (game[m] == 'X') return 0;
    game[m] = 'X';

    For(j, len-2) {
        if (game[j]=='X' && game[j+1]=='X' && game[j+2]=='X') {
            return 1;
        }
    }
    For(j, len-1) {
        if (game[j]=='X' && game[j+1]=='X') {
            return 0;
        }
    }
    For(j, len-2) {
        if (game[j]=='X' && game[j+1]=='.' && game[j+2]=='X'){
            return 0;
        }
    }

    int last=-1;
    int ans=0;
    For(i, len) {
        if (game[i]=='X') {
            if (last > -1) {
                ans ^= sg(i-last-5);
            } else {
                ans ^= sg(i-last-3);
            }
            last = i;
        }
    }
    ans ^= sg(len-last-3);

    return ans==0;

}

vector<int> ans;
void solve() {
    cin >> tmp;
    ans.clear();
    int len = tmp.length();
    For(i, len) {
        if (check(i, len)) ans.push_back(i+1);
    }
    if (ans.empty()) {
        puts("0");
    } else {
        bool first = 1;
        for(int m : ans) {
            if (!first) putchar(32);
            else first = 0;
            printf("%d", m);
        }
        putchar(10);
    }
}


int main() {
#ifdef D
    freopen("LightOJ-1229.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init();
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }
#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}