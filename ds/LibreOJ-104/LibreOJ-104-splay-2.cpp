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

struct Node {
    Node* ch[2]; Node* fa;
    int size, cnt, val;
    void out() {
        logs(val, fa->val, ch[0]->val, ch[1]->val);
    }
};
typedef Node* nd;
nd null = new Node();
nd root = null;

void output(nd x) {
    if (x->ch[0] != null) output(x->ch[0]);
    cout << x->val << " ";
    if (x->ch[1] != null) output(x->ch[1]);
}
#define bb output(root),cout<<endl;

int get(nd x) { return x->fa != null && x->fa->ch[1] == x; }
void update(nd x) {
    x->size = x->cnt + x->ch[0]->size + x->ch[1]->size;
}


nd New(int val, nd fa) {
    nd x = new Node();
    x->val = val;
    x->size = x->cnt = 1;
    x->fa = fa;
    if (fa != null) fa->ch[val > fa->val] = x;
    x->ch[0] = x->ch[1] = null;
    return x;
}

void rotate(nd x) {
    nd fa = x->fa; nd gfa = x->fa->fa;
    int d1 = get(x), d2 = get(fa);
    nd y = x->ch[d1 ^ 1];

    x->ch[d1 ^ 1] = fa;
    fa->fa = x;

    fa->ch[d1] = y;
    y->fa = fa;

    gfa->ch[d2] = x;
    x->fa = gfa;

    update(fa);
    update(x);
}

void splay(nd x, nd goal) {
    while (x->fa != goal) {
        nd fa = x->fa; nd gfa = fa->fa;
        int d1 = get(x), d2 = get(fa);
        if (gfa != goal) { if (d1 == d2) rotate(fa); else rotate(x); }
        rotate(x);
    }
    if (goal == null) root = x;
}

void insert(int val) {
    nd x = root, fa = null;
    while (x != null && x->val != val) fa = x, x = x->ch[val > x->val];
    if (x != null) x->cnt++;
    else x = New(val, fa);
    splay(x, null);
}

nd find(int val) {
    nd x = root;
    while (x->val != val && x->ch[val > x->val] != null) x = x->ch[val > x->val];
    return x;
}

nd getPreNext(int val, int type) {
    splay(find(val), null);
    nd x = root;
    if (x->val < val && type == 0) return x;
    if (x->val > val && type == 1) return x;
    x = x->ch[type];
    while (x->ch[type ^ 1] != null) x = x->ch[type ^ 1];
    return x;
}

void Remove(int val){
    nd pre = getPreNext(val, 0);
    nd nxt = getPreNext(val, 1);
    splay(pre, null);
    splay(nxt, pre);
    nd x = nxt->ch[0];
    if (x->cnt > 1) {
        x->cnt--;
        splay(x, null);
    } else {
        delete x;
        nxt->ch[0] = null;
        splay(nxt, null);
    }
}

int getValByRank(int k) {
    nd x = root;
    if (x->size < k) return INF;
    while (1) {
        nd y = x->ch[0];
        if (x == null) return -INF;
        if (k <= y->size) x = y;
        else if (k <= y->size + x->cnt) return x->val;
        else {
            k -= y->size + x->cnt;
            x = x->ch[1];
        }
    }
}

int getRankByVal(int val) {
    splay(find(val), null);
    return root->ch[0]->size + 1;
}

void init() {
    insert(-INF);
    insert(INF);
}

int main() {
#ifdef D
    freopen("LibreOJ-104.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init();
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
            printf("%d\n", getPreNext(val, 0)->val);
        } else if (opt == 6) {
            printf("%d\n", getPreNext(val, 1)->val);
        }
        // bb;
    }

#ifdef D
    clock_t TIMEB=clock();
    // printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}