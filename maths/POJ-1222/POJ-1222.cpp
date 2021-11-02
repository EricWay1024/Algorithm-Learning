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


short mt[35][35];
void output() {
    cout << "---\n";
    rep(i,1,30){
        rep(j,1,31){
            cout << mt[i][j] << ' ';
        }
        cout << endl;
    }
}

int get_id(int i, int j) {
    if (i < 1 || i > 5 || j < 1 || j > 6) return -1;
    return (i-1)*6+j;
}

const int d[5][2] = {
    {0, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, 0}
};

void init_mt() {
    rep(i,1,5) {
        rep(j,1,6){
            int id0 = get_id(i, j);
            For(t, 5) {
                int id = get_id(i + d[t][0], j + d[t][1]);
                if (id == -1) continue;
                mt[id0][id] = 1;
            }
            mt[id0][31] = read();
        }
    }
}

void swap_rows(int i, int j) {
    if (i == j) return;
    rep(k,1,31) swap(mt[i][k], mt[j][k]);
}
void xor_equal_row(int i, int j) {
    rep(k,1,31) mt[i][k] ^= mt[j][k];
}
bool gauss() {
    rep(i,1,30){
        int k=-1;
        rep(j,i,30) if (mt[j][i]) { k=j; break; }
        if (k == -1) return 0;
        swap_rows(i, k);
        rep(j,1,30) if (j != i && mt[j][i] == 1) {
            xor_equal_row(j, i);
        }
        // output();
    }
    return 1;
}

void output_ans() {
    rep(i,1,5){
        rep(j,1,6){
            int id = get_id(i, j);
            printf("%d%c", mt[id][31], j==6?'\n':' ');
        }
    }
}

int main() {
#ifdef D
    freopen("POJ-1222.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read();
    rep(cas,1,T){
        printf("PUZZLE #%d\n", cas);
        init_mt();
        gauss();
        output_ans();
    }



    // while(T--) {
    //     solve();
    // }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}