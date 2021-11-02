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

int read_digit() {
    char c;
    do {c=getchar();} while((c>'9'||c<'1') && (c!='.') && (c!='e'));
    return c == '.' ? 0 : (c == 'e' ? -1 : c - '0');
}


int row[9], col[9], squ[9];
int game[9][9];
int bcnt[3000];

int get_sq(int i, int j) {
    return 3 * (i / 3) + (j / 3);
}

int get_legal(int i, int j) {
    return row[i] & col[j] & squ[get_sq(i, j)];
}

struct Node {
    int i, j, p;
    Node (int a=0, int b=0) { i = a, j = b; }
}spc[100]; int scnt;

bool cmp(const Node &a, const Node &b) {
    return a.p < b.p;
}


void output_binary(int s) {
    vector<int> temp;
    For(i, 10) {
        temp.push_back(s & 1);
        s >>= 1;
    }
    reverse(temp.begin(), temp.end());
    For(i, temp.size()) {
        cout << temp[i];
    }
    cout << endl;
}

void output_game() {
    For(i, 9) {For(j, 9) putchar(game[i][j] + '0');  }
    putchar('\n');
}

bool found = 0;
void dfs(int x) {
    if (found) return; 
    if (x == scnt) {
        output_game();
        found = 1;
        return;
    }
    int i = spc[x].i;
    int j = spc[x].j;
    int s = get_sq(i, j);
    int t = get_legal(i, j);
    if (t == 0) return ;

    rep(k, 1, 9) if (t & (1 << k)) {
        game[i][j] = k;
        row[i] ^= (1 << k);
        col[j] ^= (1 << k);
        squ[s] ^= (1 << k);

        dfs(x + 1);

        game[i][j] = 0;
        row[i] ^= (1 << k);
        col[j] ^= (1 << k);
        squ[s] ^= (1 << k);
    }
}

int main() {
#ifdef D
    freopen("POJ-3074.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    rep(i, 1, 1023) {
        if ((i & 1) == 0) bcnt[i] = bcnt[i >> 1];
        else bcnt[i] = bcnt[i >> 1] + 1;
    }

    while (1) {
        For(i, 9) {
            col[i] = squ[i] = row[i] = 1022;
        }
        scnt = 0;
        found = 0;

        For(i, 9) {
            For(j, 9) {
                game[i][j] = read_digit();
                if (game[i][j] == -1) {
                    return 0;
                } else if (game[i][j]) {
                    row[i] ^= (1 << game[i][j]);
                    col[j] ^= (1 << game[i][j]);
                    int s = get_sq(i, j);
                    squ[s] ^= (1 << game[i][j]);
                } else {
                    spc[scnt++] = Node(i, j);
                }
            }
        }

        // For(i, 9) {
        //     cout << i << endl;
        //     output_binary(row[i]);
        //     output_binary(col[i]);
        //     output_binary(squ[i]);
        // }

        For(k, scnt) {
            int i = spc[k].i;
            int j = spc[k].j;
            int t = get_legal(i, j);
            spc[k].p = bcnt[t];
        }

        sort(spc, spc + scnt, cmp);

        dfs(0);

    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}