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

const int INF = 0x7fffffff;

struct Node {
    Node* fa; Node* ch[2];
    int val, size, tag, num;
};
typedef Node* nd;
nd null = new Node();
nd root = null;

int get(nd x) { return x == x->fa->ch[1]; }
nd New(int val, nd fa) {
    nd x = new Node();
    x->val = val;
    x->fa = fa;
    if (fa != null) fa->ch[val > fa->val] = x;
    x->size = 1;
    x->ch[0] = x->ch[1] = null;
    return x;
}

void update(nd x) {
    x->size = x->ch[0]->size + x->ch[1]->size + 1;
}
void push_down(nd x) {
    if (x->tag) {
        x->ch[0]->tag ^= 1;
        x->ch[1]->tag ^= 1;
        x->tag = 0;
        swap(x->ch[0], x->ch[1]);
        swap(x->ch[0]->val, x->ch[1]->val);
    }
}
void rotate(nd x) {
    nd fa = x->fa; nd gfa = fa->fa;
    int d1 = get(x); int d2 = get(fa);
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
        int d1 = get(x); int d2 = get(fa);
        if (gfa != goal) {
            if (d1 == d2) rotate(fa); else rotate(x);
        }
        rotate(x);
    }
    if (goal == null) root = x;
}

void insert(int val) {
    nd x = root, fa = null;
    while (x != null) fa = x, x = x->ch[val > x->val];
    x = New(val, fa);
    splay(x, null);
}

nd kth(int k) {
    nd x = root;
    if (k > x->size) return null;
    while (1) {
        push_down(x);
        if (k <= x->ch[0]->size) x = x->ch[0];
        else if (k <= x->ch[0]->size + 1) return x;
        else {
            k -= x->ch[0]->size + 1;
            x = x->ch[1];
        }
    }
}

int main() {
#ifdef D
    freopen("P4402.in", "r", stdin);
    clock_t TIMEA = clock();
#endif


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}