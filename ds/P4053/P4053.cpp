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
const int N = 150100;
bool my_greater(ll x, ll y) { return x > y; }
struct Heap {
    int n; ll a[N];
    bool (*cmp)(ll, ll);
    Heap(bool (*_cmp)(ll, ll)) : cmp(_cmp) {} ;

    void percolateUp(int u) {
        while (u > 1 && cmp(a[u], a[u >> 1])) swap(a[u], a[u >> 1]), u >>= 1;
    }

    void percolateDown(int u) {
        for (int v = u << 1; v <= n; u = v, v = u << 1) {
            if (v + 1 <= n && cmp(a[v + 1], a[v])) v++;
            if (!cmp(a[v], a[u])) break;
            swap(a[v], a[u]);
        }
    }

    void insert(int x) {
        a[++n] = x;
        percolateUp(n);
    }

    void pop() {
        a[1] = a[n--];
        percolateDown(1);
    }

    ll top() { return a[1]; }
    int size() { return n; }
};

vector< pair<ll, ll> > ts;

int main() {
#ifdef D
    freopen("P4053.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    auto h = new Heap(my_greater);
    int n = read();
    rep(i,1,n) {
        ll t = read(), l = read();
        ts.push_back(make_pair(l, t));
    }
    sort(ts.begin(), ts.end());
    ll sumt = 0;
    for (auto p : ts) {
        ll l, t; tie(l, t) = p;
        if (sumt + t <= l) {
            sumt += t;
            h->insert(t);
        } else if (h->size()){
            ll topt = h->top();
            if (topt >= t && sumt - topt + t <= l) {
                sumt = sumt - topt + t;
                h->pop();
                h->insert(t);
            }
        }
    }

    cout << (h->size()) << endl;


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}