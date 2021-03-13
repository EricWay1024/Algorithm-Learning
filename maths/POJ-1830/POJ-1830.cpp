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
#include<unordered_map>
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
short mt[35][35]; int n;
void output() {
    cout << "---\n";
    rep(i,1,n){
        rep(j,1,n+1){
            cout << mt[i][j] << ' ';
        }
        cout << endl;
    }
}

void swap_rows(int i, int j) {
    if (i == j) return;
    rep(k,1,n+1) swap(mt[i][k], mt[j][k]);
}
void xor_equal_row(int i, int j) {
    rep(k,1,n+1) mt[i][k] ^= mt[j][k];
}
ll gauss() {
    int r=1;
    rep(c,1,n){
        int k=-1;
        rep(j,r,n) if (mt[j][c]) { k=j; break; }
        if (k == -1) continue;
        else swap_rows(r, k);
        rep(j,1,n) if (j != r && mt[j][c] == 1) {
            xor_equal_row(j, r);
        }
        r++;
        // output();
    }
    
    rep(i,r,n){
        if (mt[i][n+1] != 0) return 0;
    }
    return 1<<(n+1-r);  
}


int main() {
#ifdef D
    freopen("POJ-1830.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read();
    while(T--){
        mmst(mt, 0);
        n=read();
        For(_, 2){
            rep(i,1,n) mt[i][n+1] ^= read();
        }
        rep(i,1,n) mt[i][i]=1;
        int a, b;
        while(1) {
            a = read(), b=read();
            if (!a && !b) break;
            mt[b][a]=1;
        }
        ll res = gauss();
        if (res) cout << res << endl;
        else puts("Oh,it's impossible~!!");
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}