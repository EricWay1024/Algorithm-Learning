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

const int SIZE = 100010;
const int INF = 0x7fffffff;
struct Treap {
    struct Node {
        int l, r;
        int val, dat;
        int cnt, size;

        void output() {
            logs(l, r, val, dat, cnt, size);
        }
    } a[SIZE];

    int tot, root, n;

    void output(int p) {
        cout << p << " "; a[p].output();
        if (a[p].l) output(a[p].l);
        if (a[p].r) output(a[p].r);
    }

    int New(int val) {
        a[++tot].val = val;
        a[tot].dat = rand();
        a[tot].cnt = a[tot].size = 1;
        return tot;
    }

    void Update(int p) {
        a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
    }

    void Build() {
        root = New(-INF);
        a[root].r = New(INF);
        Update(root);
    }

    void zig(int &p) {
        int q = a[p].l;
        a[p].l = a[q].r, a[q].r = p, p = q;
        Update(a[p].r); Update(p);
    }

    void zag(int &p) {
        int q = a[p].r;
        a[p].r = a[q].l, a[q].l = p, p = q;
        Update(a[p].l); Update(p);
    }

    void Insert(int &p, int val) {
        if (p == 0) {
            p = New(val);
            return ;
        } 
        
        if (val == a[p].val) {
            a[p].cnt++;
        } else if (val < a[p].val) {
            Insert(a[p].l, val);
            if (a[p].dat < a[a[p].l].dat) zig(p);
        } else {
            Insert(a[p].r, val);
            if (a[p].dat < a[a[p].r].dat) zag(p);
        }

        Update(p);
    }

    void Remove(int &p, int val) {
        if (p == 0) return ;
        if (val == a[p].val) {
            if (a[p].cnt > 1) {
                a[p].cnt--;
                Update(p);
                return;
            }

            if (a[p].l || a[p].r) {
                if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat) {
                    zig(p), Remove(a[p].r, val);
                } else {
                    zag(p), Remove(a[p].l, val);
                }
                Update(p);
            }
            else p = 0;
            return ;
        } 

        if (val < a[p].val) Remove(a[p].l, val);
        else Remove(a[p].r, val);
        Update(p);
    }

    int GetRankByVal(int p, int val) {
        if (p == 0) return 0;
        else if (val == a[p].val) return a[a[p].l].size + 1;
        else if (val < a[p].val) return GetRankByVal(a[p].l, val);
        else return GetRankByVal(a[p].r, val) + a[a[p].l].size + a[p].cnt;
    }

    int GetValByRank(int p, int rank) {
        if (p == 0) return INF;
        else if (a[a[p].l].size >= rank) return GetValByRank(a[p].l, rank);
        else if (a[a[p].l].size + a[p].cnt >= rank) return a[p].val;
        else return GetValByRank(a[p].r, rank - a[a[p].l].size - a[p].cnt);
    }

    int GetPre(int val) {
        int ans = 1;
        int p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].l > 0) {
                    p = a[p].l;
                    while (a[p].r > 0) p  = a[p].r;
                    ans = p;
                }
                break;
            }
            if (a[p].val < val && a[p].val > a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }

    int GetNext(int val) {
        int ans = 2;
        int p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].r > 0) {
                    p = a[p].r;
                    while (a[p].l > 0) p = a[p].l;
                    ans = p;
                }
                break;
            }
            if (a[p].val > val && a[p].val < a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }
};

int main() {
#ifdef D
    freopen("LibreOJ-104.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    auto treap = new Treap();
    treap->Build();
    int n;
    cin >> n;
    while (n--) {
        int opt, x; 
        opt = read(), x = read();
        if (opt == 1) {
            treap->Insert(treap->root, x);
        } else if (opt == 2) {
            treap->Remove(treap->root, x);
        } else if (opt == 3) {
            printf("%d\n", treap->GetRankByVal(treap->root, x) - 1);
        } else if (opt == 4) {
            printf("%d\n", treap->GetValByRank(treap->root, x + 1));
        } else if (opt == 5) {
            printf("%d\n", treap->GetPre(x));
        } else {
            printf("%d\n", treap->GetNext(x));
        }
        // treap->output(treap->root); cout << "----\n";
    }



#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}