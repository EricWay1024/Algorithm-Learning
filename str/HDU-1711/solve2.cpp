#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
// #include<unordered_map>
#include <utility>
#include <vector>
#include <numeric>
#include <functional>
#include <climits>
#include <iomanip>
using namespace std;
#define rep(i, from, to) for (int i = (int)(from); i <= (int)(to); ++i)
#define rev(i, from, to) for (int i = (int)(from); i >= (int)(to); --i)
#define For(i, to) for (int i = 0; i < (int)(to); ++i)
#define see(x) (cerr << (#x) << '=' << (x) << endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
#define coutP(i) cout << fixed << setprecision(i)
void dbg()
{
    cout << "\n";
}
template <typename T, typename... A>
void dbg(T a, A... x)
{
    cout << a << ' ';
    dbg(x...);
}
#define logs(x...)            \
    {                         \
        cout << #x << " -> "; \
        dbg(x);               \
    }
#define mmst(a, x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
inline ll read()
{
    ll x = 0;
    bool s = 1;
    char c = getchar();
    while (c > '9' || c < '0')
    {
        if (c == '-')
            s = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return s ? x : ~x + 1;
}
const int M = 10100;
const int N = 1100000;

// array index starts from one
namespace b {
    int f[M];
    int m, n;
    int P[M], T[N];
    void getFail()
    {
        f[1] = f[2] = 1;
        rep(i, 2, m)
        {
            int j = f[i];
            while (j > 1 && P[i] != P[j])
                j = f[j];
            f[i + 1] = P[i] == P[j] ? j + 1 : 1;
        }
    }

    int find()
    {
        int j = 1;
        rep(i, 1, n) {
            while (j > 1 && P[j] != T[i]) j = f[j];
            if (P[j] == T[i]) ++j;
            if (j == m + 1) return i - m + 1;
        }
        return -1;
    }
}

using namespace b;

int main()
{
#ifdef D
    freopen("HDU-1711.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int KASE = read();
    while (KASE--)
    {
        n = read(), m = read();
        rep(i, 1, n) T[i] = read();
        rep(i, 1, m) P[i] = read();
        getFail();
        int ans = find();
        cout << ans << endl;
    }

#ifdef D
    clock_t TIMEB = clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB - TIMEA) / CLOCKS_PER_SEC);
#endif
    return 0;
}