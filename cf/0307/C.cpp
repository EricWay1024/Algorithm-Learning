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
#include<unordered_map>
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

int ex_gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = ex_gcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
bool solve(int a, int b, int c, int& x, int& t) {
    // solve for ax=c (mod b), x is the smallest solution and x + kt are all solutions
    int y;
    int d = ex_gcd(a, b, x, y);
    if (c % d != 0) return 0;
    int k = c / d;
    x *= k;
    t = b / d;
    x %= t; x += t; x %= t;
    return 1;
}

vector<int> sqrtinv[10] = {
    {0},
    {1, 9},
    {},
    {},
    {2, 8},
    {5},
    {4, 6},
    {},
    {},
    {3, 7}
};

int b[30];
int a[30];
char tmp[30]; 

int c[30];
bool flag = 0;

int n;
void dfs(int k) {
    if (flag) return;
    if (k == -1) {
        mmst(c, 0);
        rep(i,0,n){
            rep(j,0,n){
                c[i+j] += a[i]*a[j];
                c[i+j] %= 10;
            }
        }
        rep(i,0,2*n) if (c[i] != b[i]) return;
        
        rep(i,0,n){
            cout << a[n-i];
        }
        cout << endl;
        flag = 1;
        return;
    }


    if (k == n) {
        for(auto i : sqrtinv[b[n+k]]){
            a[k] = i;
            dfs(k-1);
        }
    } else {
        int A = 2 * a[n];
        int B = 10;
        int C = b[n+k];
        rep(i,1,n-k-1) C -= a[n-i] * a[k+i];
        int x, t;
        int ret = solve(A, B, C, x, t);
        if (!ret) return;

        rep(i,0,10){
            int new_x = x + i * t;
            if (new_x > 9) break;
            a[k] = new_x;
            dfs(k-1);
        }

    }

}


int main() {
#ifdef D
    freopen("C.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    scanf("%s", tmp);
    int m = strlen(tmp);
    For(i,m) {
        b[m-1-i] = tmp[i]-'0';
    }

    if (m % 2 == 0) puts("-1");
    else {
        n = m/2;
        dfs(n);
        if (!flag) puts("-1");
    }



#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}