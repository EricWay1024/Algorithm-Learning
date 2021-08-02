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
char get_ans(ll s, int t) {
    return ((s >> ((t-1)*2)) & 3) + 'A';
}

char ans[11];
#define assert(x) if(!(x)){ return 0; }

// #define same(x, y) (ans[x]==ans[y])
// #define same(x, y, z) (ans[x]==ans[y] && ans[x]==ans[z])

bool same(int x, int y) {
    return ans[x] == ans[y];
}

bool same(int x, int y, int z) {
    return ans[x] == ans[y] && ans[x] == ans[z];
}

bool notNext(int x, int y) {
    return abs(ans[x] - ans[y]) != 1;
}

int cnt[300];
bool check(ll s) {
    mmst(ans, 0);
    mmst(cnt, 0);

    rep(i, 1, 10) {
        ans[i] = get_ans(s, i);
    }

    assert(
        (ans[2]=='A' && ans[5]=='C') ||
        (ans[2]=='B' && ans[5]=='D') ||
        (ans[2]=='C' && ans[5]=='A') ||
        (ans[2]=='D' && ans[5]=='B')
    );

    assert(
        (ans[3]=='A' && same(2, 4, 6) && ans[3]!=ans[6]) ||
        (ans[3]=='B' && same(2, 3, 4) && ans[3]!=ans[6]) || 
        (ans[3]=='C' && same(3, 4, 6) && ans[2]!=ans[6]) ||
        (ans[3]=='D' && same(2, 3, 6) && ans[4]!=ans[6])
    );

    assert(
        (ans[4]=='A' && ans[1]==ans[5]) ||
        (ans[4]=='B' && ans[2]==ans[7]) ||
        (ans[4]=='C' && ans[1]==ans[9]) ||
        (ans[4]=='D' && ans[6]==ans[10])
    );

    assert(
        (ans[5]=='A' && same(5, 8)) ||
        (ans[5]=='B' && same(5, 4)) ||
        (ans[5]=='C' && same(5, 9)) ||
        (ans[5]=='D' && same(5, 7))
    );

    assert(
        (ans[6]=='A' && same(8, 2, 4)) ||
        (ans[6]=='B' && same(8, 1, 6)) ||
        (ans[6]=='C' && same(8, 3, 10)) ||
        (ans[6]=='D' && same(8, 5, 9))
    );

    rep(i, 1, 10) {
        cnt[ans[i]]++;
    }
    int v = 10;
    int u = 0;
    rep(i, 'A', 'D') {
        v = min(v, cnt[i]);
        u = max(u, cnt[i]);
    }

    assert(
        (ans[7]=='A' && cnt['C']==v) ||
        (ans[7]=='B' && cnt['B']==v) ||
        (ans[7]=='C' && cnt['A']==v) || 
        (ans[7]=='D' && cnt['D']==v)
    );

    assert(
        (ans[8]=='A' && notNext(1, 7)) ||
        (ans[8]=='B' && notNext(1, 5)) ||
        (ans[8]=='C' && notNext(1, 2)) ||
        (ans[8]=='D' && notNext(1, 10)) 
    );

    bool tmp = (ans[1] != ans[6]);
    assert(
        (ans[9]=='A' && same(5, 6) == tmp) ||
        (ans[9]=='B' && same(5, 10) == tmp) ||
        (ans[9]=='C' && same(5, 2) == tmp) ||
        (ans[9]=='D' && same(5, 9) == tmp) 
    );

    int d = u - v;
    assert(
        (ans[10]=='A' && d==3) ||
        (ans[10]=='B' && d==2) ||
        (ans[10]=='C' && d==4) ||
        (ans[10]=='D' && d==1) 
    );


    return 1;
}

void output() {
    rep(i,1,10) putchar(ans[i]);
    putchar('\n');
}


int main() {
#ifdef D
    // freopen("tmp.in", "r", stdin);
    clock_t TIMEA = clock();
#endif

    for(ll s=0; s<(1<<20); ++s) {
        if (check(s)) output();
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}