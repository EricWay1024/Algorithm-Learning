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


// ll calc(ll n) {
//     ll ans = 0;
//     while (n) {
//         ans += n % 10;
//         n /= 10;
//     }
//     return ans;
// }

// ll solve2(ll n) {
//     ll ans = 0;
//     rep(i,1,n) {
//         int t = calc(i);
//         ans += t;
//     }
//     return ans;
// }

ll mem[20][1000];
vector<int> num;
ll dp(ll st, ll pre, ll op) {
    if (st == -1) return pre;
    int mx = op ? num[st] : 9;
    if (!op && mem[st][pre] != -1) return mem[st][pre];
    ll res = 0;
    rep(i, 0, mx) {
        res += dp(st - 1, pre + i, op && (i == num[st]));
    }
    if (!op) mem[st][pre] = res;
    return res;
}

ll solve(ll n) {
    if (n <= 0) return 0;
    num.clear();
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    int s = num.size();
    memset(mem, -1, sizeof(mem));
    return dp(s - 1, 0, 1);
}


int main() {
#ifdef D
    freopen("digitsum.in", "r", stdin);
    clock_t TIMEA = clock();
#endif

    // rep(i,1,2000) {
    //     cout << i << " " << solve(i) << " " << solve2(i) << endl;
    // } 
    ll l, r, T; 
    cin >> T;
    while(T-- && cin >> l >> r) cout << solve(r) - solve(l - 1) << endl;

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}