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

bool my_less(int a, int b) { return a < b; }
bool my_greater(int a, int b) { return a > b; }
const int N = 1e5 + 100;
struct Heap {
    int n, a[N];
    bool (*cmp)(int, int);
    Heap(bool (*_cmp)(int, int)) : cmp(_cmp) {} ;
    void percolateUp(int u) {
        while (u > 1 && cmp(a[u], a[u >> 1])) swap(a[u], a[u >> 1]), u >>= 1;
    }

    void percolateDown(int u) {
        for (int v = u * 2; v <= n; u = v, v = u * 2) {
            if (v + 1 <= n && cmp(a[v + 1], a[v])) v++;
            if (!cmp(a[v], a[u])) break;
            swap(a[v], a[u]);
        }
    }

    void clear() { n = 0; }

    void insert(int x) {
        a[++n] = x;
        percolateUp(n);
    }

    int top() {
        return a[1];
    }

    int size() {
        return n;
    }

    void pop() {
        a[1] = a[n--];
        percolateDown(1);
    }
};

struct KHeap {
    Heap h1 = Heap(my_greater);
    Heap h2 = Heap(my_less);

    void maintain() {
        int n = h1.size() + h2.size();
        int k = (n + 1) / 2;
        while (h1.size() < k) {
            h1.insert(h2.top()); h2.pop();
        }

        while (h1.size() > k) {
            h2.insert(h1.top()); h1.pop();
        }
    }

    void insert(int x) {
        if (h1.size() == 0 || x <= h1.top()) {
            h1.insert(x);
        } else {
            h2.insert(x);
        }

        maintain();
    }

    int query() {
        return h1.top();
    }

    void remove() {
        h1.pop();
        maintain();
    }

    void clear() {
        h1.clear(); h2.clear();
    }

};

int main() {
#ifdef D
    freopen("SP16254.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T = read();
    auto kh = new KHeap();
    while (T--) {
        kh->clear();
        int n; 
        while ((n = read())) {
            if (n == -1) {
                cout << (kh->query()) << endl;
                kh->remove();
            } else {
                kh->insert(n);
            }
        }
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}