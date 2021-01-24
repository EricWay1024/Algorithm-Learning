#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define N 2123
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
ll f[N][N][2];
ll h[N];
ll sz[N];
int n;
vector<int> son[N];
#define inf 1e15


void dp(int u) {
    f[u][0][0] = h[u];
    f[u][1][1] = 0;
    sz[u] = 1;
    for(int v : son[u]) {
        dp(v);
        sz[u] += sz[v];
    }

    for(int v : son[u]) {
        ll ans;
        rev(m, sz[u], 0) {
            if (m > 0) {
                ans = inf;
                rep(l, 0, m - 1) {
                    ans = min(ans, f[u][m-l][1] + min(f[v][l][1], f[v][l][0]));
                }
                f[u][m][1] = ans;
            }

            ans = inf;
            rep(l, 0, m) {
                ans = min(ans, f[u][m-l][0] + min(f[v][l][1], f[v][l][0] + h[v]));
            }
            f[u][m][0] = ans;
        }
    }
}

int main() {
#ifdef D
    freopen("NJ-M.in", "r", stdin);
#endif
    int T; T=read();
    while(T--) {
        n=read();
        for(int i=1; i<=n; i++) son[i].clear();
        memset(h, 0, sizeof(h));
        memset(f, 0x3f, sizeof(f));
        memset(sz, 0, sizeof(sz));

        for(int i=2; i<=n;i++) {
            int p;
            p=read();
            son[p].push_back(i);
        }

        for(int i=1; i<=n;i++) {
            h[i]=read();
        }

        dp(1);


        // rep(i, 1, n) {
        //     cout << sz[i] << endl;
        //     rep(j, 0, sz[i]) {
        //         rep(k, 0, 1) {
        //             printf("f[%d][%d][%d]=%lld ", i, j, k, f[i][j][k]);
        //         }
        //         cout << endl;
        //     }
        //     cout<<endl;
        // }
        // cout << endl;


        rep(i, 0, n) {
            if (i) putchar(' ');
            printf("%lld", min(f[1][i][0], f[1][i][1]));
        }
        putchar('\n');
    }
    return 0;
}