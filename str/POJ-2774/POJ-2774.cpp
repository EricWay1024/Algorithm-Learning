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
typedef unsigned long long ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

int n;
const ll B1 = 10067;
const ll B2 = 10103;
// const ll M2 = 19260817;
// const ll M1 = 1e9 + 711;
const int N = 1e6+10;
ll b1pow[N], b2pow[N];
char tmp[N];

struct MyStr{
    char s[N]; 
    ll h1[N]; ll h2[N];
    int l;
    MyStr () { }

    void init (char *t) {
        l = 0; 
        int lt = strlen(t);
        For(i, lt) { push_back(t[i]); }
    }

    void push_back(char c) {
        s[++l] = c;
        h1[l] = (h1[l-1] * B1 + (ll)c);
        h2[l] = (h2[l-1] * B2 + (ll)c);
    }  

    ll slice1(int l, int r) {
        return (((h1[r] - h1[l-1] * b1pow[r-l+1])));
    }

    ll slice2(int l, int r) {
        return (((h2[r] - h2[l-1] * b2pow[r-l+1])));
    }

    void output() {
        rep(i,1,l) putchar(s[i]);
        putchar('\n');
    }
}a, b;


void init() {
    b1pow[0] = b2pow[0] = 1;
    rep(i,1,1e6) {
        b1pow[i] = b1pow[i-1] * B1;
        b2pow[i] = b2pow[i-1] * B2;
    }
}

ll st[N], tot;
bool check1(int k) {
    tot = 0;
    rep(i, 1, a.l - k + 1) {
        st[tot++] = a.slice1(i, i + k - 1);
    }
    sort(st, st + tot);
    rep(i, 1, b.l - k + 1) {
        ll x = b.slice1(i, i + k - 1);
        if (binary_search(st, st + tot, x)) return 1;
    }
    return 0;
}

bool check2(int k) {
    tot = 0;
    rep(i, 1, a.l - k + 1) {
        st[tot++] = a.slice2(i, i + k - 1);
    }
    sort(st, st + tot);
    rep(i, 1, b.l - k + 1) {
        ll x = b.slice2(i, i + k - 1);
        if (binary_search(st, st + tot, x)) return 1;
    }
    return 0;
}

bool check(int k) {
    return check1(k);
}

int main() {
#ifdef D
    freopen("POJ-2774.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    init();
    scanf("%s", tmp); getchar();
    a.init(tmp);
    scanf("%s", tmp);
    b.init(tmp);

    int l=0, r=min(a.l, b.l);

    int ans=0;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    printf("%d\n", ans);

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}