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
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
inline int read(){
    int x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
const int N = 211;
int game[N][N]; int m, n;
const int step[8][2] = {
    {-1, -2}, {-2, -1}, {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}
};
void mark(int x, int y, int v) {
    if (x >= 0 && x < m && y >= 0 && y < n) game[x][y]+=v;
}
void modify(int x, int y, int v) {
    For(i, 8) {
        int dx = step[i][0], dy = step[i][1];
        mark(x + dx, y + dy, v);
    }
}
void output() {
    For(i, m) {
        For(j, n) {
            cout << game[i][j] << " ";
        }
        cout << endl;
    }
}
int dfs(int x, int y) {
    // logs(x, y);
    // output();
    if (x == m) return 0;
    if (y == n) return dfs(x + 1, 0);

    if (game[x][y]) return dfs(x, y + 1);

    else {
        int ans1 = dfs(x, y + 1);

        modify(x, y, 1);
        int ans2 = dfs(x, y + 1) + 1;
        modify(x, y, -1);

        return max(ans1, ans2);
    }
}

int main() {
#ifdef D
    freopen("LightOJ-1010.in", "r", stdin);
    double TIMEA = clock();
#endif
    // rep(i, 3, 3){
    //     rep(j, 1, 10) {
    //         n = i, m = j;
    //         logs(n, m);
    //         cout << dfs(0, 0) << endl;
    //     }
    // }
    // n = 2;
    // rep(i, 1, 30) {
    //     m = i;
    //     int ans=dfs(0, 0);
    //     printf("m=%d, ans=%d\n", m, ans);
    //     int x = ceil((db)m/4) * 4;
    //     if ((m & 3) == 1) x -= 2;
    //     cout << x << endl;
    //     cout << (x==ans) << endl;
    // }
    // modify(5, 5, 1);
    // output();
    // modify(5, 5, -1);
    // output();
    int T=read();
    rep(i, 1, T){
        m=read(), n=read();
        if (m > n) swap(m, n);
        // m is min
        int ans;
        if (m==1) {
            ans = n;
        } 
        else if (m==2) {
            int x = ceil((db)n/4) * 4;
            if ((n & 3) == 1) x -= 2;
            ans = x;
        }
        else {
            int t=m*n;
            ans = ceil((db)t*0.5);
        }
        printf("Case %d: %d\n", i, ans);
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}