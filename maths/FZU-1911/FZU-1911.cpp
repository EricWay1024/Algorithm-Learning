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
// #include<cstdint>
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

int game[20][20];
bool flag=0;
void outputgame(int k) {
    cout << "---" << endl;
    rep(i,1,k){
        rep(j,1,k){
            cout << game[i][j] << ' ';
        }
        cout << endl;
    }
}

bool checkgame(int k){
    set<int> st;
    rep(i,1,k){
        int sum=0;
        rep(j,1,k){
            sum+=game[i][j];
        }
        if (st.count(sum)) return 0;
        st.insert(sum);
    }

    rep(j,1,k){
        int sum=0;
        rep(i,1,k){
            sum+=game[i][j];
        }
        if (st.count(sum)) return 0;
        st.insert(sum);
    }
    return flag=1;

}
void search(int k, int x, int y) {
    // if (flag) return;
    if (x == k+1) {
        search(k, 1, y+1);
        return;
    }
    if (y == k+1) {
        if (checkgame(k)) outputgame(k);
        return;
    }
    rep(d,-1,1){
        game[x][y]=d;
        search(k, x+1, y);
    }
}


int main() {
#ifdef D
    freopen("FZU-1911.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    flag = 0;
    search(4, 1, 1);


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}