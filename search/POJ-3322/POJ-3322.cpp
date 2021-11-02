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

// void dbg() {cout << "\n";}
// template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
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

const char dict[] = ".#EXO";
bool legal(char c) { For(i, 5) if (dict[i] == c) return 1; return 0; }
char get_game() { char c; do { c = getchar(); } while (!legal(c)); return c; }

const int N = 544;
char game[N][N];
int m, n;

struct Node {
    int x, y, p;

    // void output() {
    //     logs(x, y, p);
    // }

    // void output() {
    //     logs(x, y, p);
    //     rep(i,1,m) {rep(j,1,n) {
    //         if ((i == x && j == y) || (p == 1 && i == x + 1 && j == y) || (p == 2 && i == x && j == y + 1)) putchar('X');
    //         else putchar(game[i][j]);
    //     } putchar('\n'); }
    //     putchar('\n');
    // }

    bool check() {
        if (x > m || y > n || x < 1 || y < 1) return 0;

        if (p == 0) { return game[x][y] == '.'; }
        if (p == 1) { 
            return 
                (game[x][y] == '.' && game[x + 1][y] == '.') || 
                (game[x][y] == '.' && game[x + 1][y] == 'E') || 
                (game[x][y] == 'E' && game[x + 1][y] == '.') || 
                (game[x][y] == 'E' && game[x + 1][y] == 'E');
        }
        if (p == 2) {
            return 
                (game[x][y] == '.' && game[x][y + 1] == '.') || 
                (game[x][y] == '.' && game[x][y + 1] == 'E') || 
                (game[x][y] == 'E' && game[x][y + 1] == '.') || 
                (game[x][y] == 'E' && game[x][y + 1] == 'E');
        }

        return 0;
    }
}st, ed;

queue<Node> q;

const int dir[3][4][3] = {
    {{1, 0, 1}, {-2, 0, 1}, {0, 1, 2}, {0, -2, 2}},
    {{0, -1, 1}, {0, 1, 1}, {-1, 0, 0}, {2, 0, 0}},
    {{0, -1, 0}, {0, 2, 0}, {-1, 0, 2}, {1, 0, 2}}
};


int dist[N][N][3];

int bfs() {
    mmst(dist, -1);
    dist[st.x][st.y][st.p] = 0;
    while (q.size()) q.pop();
    q.push(st);
    while (q.size()) {
        Node u = q.front(); q.pop();
        // u.output();
        For(i, 4) {
            Node v;
            v.x = u.x + dir[u.p][i][0];
            v.y = u.y + dir[u.p][i][1];
            v.p = dir[u.p][i][2];
            if (!v.check() || dist[v.x][v.y][v.p] != -1) continue;
            dist[v.x][v.y][v.p] = dist[u.x][u.y][u.p] + 1;
            if (v.x == ed.x && v.y == ed.y && v.p == ed.p) return dist[v.x][v.y][v.p];
            q.push(v);
        }
    }
    return -1;
}


int main() {
#ifdef D
    freopen("POJ-3322.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    while (1) {
        m=read(), n=read();
        if (!m && !n) break;

        mmst(game, 0);
        vector< pair<int, int> > start;

        rep(i,1,m) rep(j,1,n) {
            game[i][j] = get_game();
            if (game[i][j] == 'O') ed.x = i, ed.y = j, ed.p = 0, game[i][j] = '.';
            else if (game[i][j] == 'X') {
                start.push_back(make_pair(i, j));
                game[i][j] = '.';
            }
        }

        // rep(i,1,m) {
        //     rep(j,1,n) {
        //         if (game[i][j] == 'X') {
        //             For(k, 4) {
        //                 int x = i + d2[i][0],
        //                 int y = i + d2[i][1]
        //             }
        //         }
        //     }
        // }

        sort(start.begin(), start.end());
        st.x = start[0].first, st.y = start[0].second;
        if (start.size() == 1) {
            st.p = 0;
        } else {
            st.p = (start[0].second == start[1].second) ? 1 : 2;
        }

        int ans = bfs();
        if (~ans) {
            printf("%d\n", ans);
        } else {
            puts("Impossible");
        }
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}