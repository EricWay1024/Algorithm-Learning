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

int n, m;
const int N = 30;
char game[N][N];
struct Node {
    int x, y, p;
};
const int dir[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

queue< pair<int, int> > qa;
int da[N][N];
int bfs_person(int sx, int sy, int fx, int fy, int bx, int by) {
    while (qa.size()) qa.pop();
    mmst(da, -1);
    qa.push(make_pair(sx, sy));
    da[sx][sy] = 0;
    while (qa.size()) {
        pair<int, int> u = qa.front(); qa.pop();
        int cx = u.first; int cy = u.second;
        For(i, 4) {
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];
            if (nx > m || nx < 1 || ny > n || ny < 1) continue;
            if (nx == sx && ny == sy) continue;
            if (game[nx][ny] == '#') continue;
            if (da[nx][ny] != -1) continue;
            da[nx][ny] = da[cx][cy] + 1;
            if (nx == fx && ny == fy) return da[nx][ny];
        }
    }
    return -1;
}


queue<Node> qb;
int fb[N][N][4], fm[N][N][4];
// 太难写，写不动了

int main() {
#ifdef D
    freopen("POJ-1475.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    while ((m = read()) && (n = read())) {
        rep(i,1,m) {
            scanf("%s", game[i] + 1);
        }

        rep(i,1,m) {
            rep(j,1,n) {

            }
        }
    }

    

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}