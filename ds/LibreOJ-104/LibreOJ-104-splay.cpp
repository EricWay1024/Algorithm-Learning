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

const int SIZE = 100000 + 10;
const int INF = 0x7fffffff;

int tot, root;

struct Node {
    int ch[2], size, cnt, val, fa;
} a[SIZE];

#define lc(x) (a[x].ch[0])
#define rc(x) (a[x].ch[1])

void out(int x) {
    if (lc(x)) out(lc(x));
    printf("%d ", a[x].val);
    if (rc(x)) out(rc(x));
}
#define bb out(root),cout<<endl;

int get(int x) { return a[a[x].fa].ch[1] == x; }
void update(int x) {
    a[x].size = a[x].cnt + a[lc(x)].size + a[rc(x)].size;
}

// turn x into (x's current father)'s father
void rotate(int x) {
    int fa = a[x].fa, gfa = a[fa].fa;
    int d1 = get(x), d2 = get(fa);

    a[fa].ch[d1] = a[x].ch[d1 ^ 1];
    a[a[x].ch[d1 ^ 1]].fa = fa;

    a[gfa].ch[d2] = x;
    a[x].fa = gfa;

    a[fa].fa = x;
    a[x].ch[d1 ^ 1] = fa;

    update(fa);
    update(x);
}

// turn x into goal's son; when goal == 0, turn x into root
void splay(int x, int goal) {
    while (a[x].fa != goal) {
        int fa = a[x].fa, gfa = a[fa].fa;
        int d1 = get(x), d2 = get(fa);
        if (gfa != goal) {
            if (d1 == d2) rotate(fa);
            else rotate(x);
        }
        rotate(x);
    }
    if (goal == 0) root = x;
}

int New(int val, int fa) {
    a[++tot].val = val;
    a[tot].cnt = a[tot].size = 1;
    if (fa) {
        a[fa].ch[a[fa].val < val] = tot;
        a[tot].fa = fa;
    } else {
        root = tot;
    }
    return tot;
}

void insert(int val) {
    int x = root, fa = 0;
    while (x && a[x].val != val) fa = x, x = a[x].ch[a[x].val < val];
    if (x) a[x].cnt++;
    else x = New(val, fa);
    splay(x, 0);
}

int getValByRank(int rank) {
    int x = root;
    if (a[x].size < rank) return INF;
    while (1) {
        if (x == 0) return 0;
        else if (rank <= a[lc(x)].size) x = lc(x);
        else if (rank <= a[lc(x)].size + a[x].cnt) return a[x].val;
        else {
            rank -= a[lc(x)].size + a[x].cnt;
            x = rc(x);
        }
    }
}

int find(int val) {
    int x = root;
    while (a[x].val != val && a[x].ch[a[x].val < val]) 
        x = a[x].ch[a[x].val < val];
    return x;
}

int getRankByVal(int val) {
    splay(find(val), 0);
    return a[lc(root)].size + 1;
}

int getPreNext(int val, int type) {
    splay(find(val), 0);
    int x = root;
    if (type == 0 && a[x].val < val) { return x; }
    if (type == 1 && a[x].val > val) { return x; }
    x = a[x].ch[type];
    while (a[x].ch[type ^ 1]) x = a[x].ch[type ^ 1];
    return x;
}

void Remove(int val) {
    int lst = getPreNext(val, 0);
    int nxt = getPreNext(val, 1);
    splay(lst, 0);
    splay(nxt, lst);
    if (a[a[nxt].ch[0]].cnt > 1) {
        a[a[nxt].ch[0]].cnt--;
        splay(a[nxt].ch[0], 0);
    } else {
        a[nxt].ch[0] = 0;
        update(nxt);
        update(lst);
    }
}



int main() {
#ifdef D
    freopen("LibreOJ-104.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    insert(-INF);
    insert(INF);
    int n = read();
    while (n--) {
        int opt = read(), val = read();
        if (opt == 1) {
            insert(val);
        } else if (opt == 2) {
            Remove(val);
        } else if (opt == 3) {
            printf("%d\n", getRankByVal(val) - 1);
        } else if (opt == 4) {
            printf("%d\n", getValByRank(val + 1));
        } else if (opt == 5) {
            printf("%d\n", a[getPreNext(val, 0)].val);
        } else if (opt == 6) {
            printf("%d\n", a[getPreNext(val, 1)].val);
        }
        // bb;
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}