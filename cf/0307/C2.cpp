#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(int)(a); i<=(int)(b); ++i)
#define For(i,n) for(int i=0; i<(int)(n); ++i)
typedef long long ll;
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << " "; dbg(x...);}
#define logs(x...) {cout<<#x<<"->"; dbg(x); }
#define mmst(a, n) memset(a, n, sizeof(a))
char tmp[30];
int s[30];
int n;

int a[30];
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
bool liEu(int a, int b, int c, int& x, int& y) {
  int d = ex_gcd(a, b, x, y);
  if (c % d != 0) return 0;
  int k = c / d;
  x *= k;
  y *= k;
  return 1;
}

void dfs(int x) {
    if (x == n) {
        For(i,n){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    if (x == 0) {
        for(auto i : sqrtinv[s[x]]) {
            a[x] = i;
            dfs(x+1);
        }
    } else {
        ll b=0;
        rep(i,1,x-2) {
            b += (s[i] * s[x-i]) % 10;
        }
        b %= 10;
        b = 10 - b;

        int z, y;
        int ret = liEu(2 * a[0], b, 10, z, y);
        if (!ret) return;
        logs(z)

        rep(t, 1, 9) {
            if (z + b * t > 9) break;
            a[x] = z + b * t;
            dfs(x+1);
        }
    }
}
int main() {
#ifdef D
    freopen("C.in", "r", stdin); 
#endif
    scanf("%s", tmp);
    n = strlen(tmp);
    For(i,n) s[i] = tmp[n-1-i]-'0';
    dfs(0);


}