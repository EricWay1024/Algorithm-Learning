Diameter of Tree

https://vjudge.net/problem/CodeChef-DTREE

题意：给定一棵无根树，求出在每个节点被分别删除的情况下，剩下的森林中每棵树直径的最大值。

先以$1$号节点为根建树。设$u$是任意非根节点$v$的父亲。考虑$v$被删除的情形。此时，剩下的森林包含：

1. 以$v$的所有儿子为根的子树。在它们中要求出直径的最大值，这就自然需要对每个节点维护“以该节点为根的子树的直径”，记该数组为`dmtr[]`。考虑到直径的树上DP求法，我们自然还需要维护数组`down[]`，表示从每个节点向下延伸的最长路径长度（或以该节点到该节点为根的子树中最远的叶子的距离）。
2. 整棵树去掉以`v`为根的子树后的部分，可以视为一棵以`u`为根的树。我们需要求出这一部分的直径。按一般的直径求法，讨论直径是否过`u`：
   1. 直径不过`u`，则再分有两种情况：
      1. 直径在`v`的某个兄弟中。这种情况可以利用`dmtr[]`数组求解。
      2. 直径在整棵树去掉以`u`为根的子树后的部分。这种情况恰好和原问题是一样的，因此在求解时递归答案即可。
   2. 直径过`u`，也分为两种情况：
      1. 直径的两段都从`u`向下延伸，即在`v`的两个兄弟中。这种情况可以利用`down[]`数组求解。
      2. 直径的一段从`u`向下延伸，在`v`的一个兄弟中，但直径的另一端向上延伸，在整棵树去掉以`u`为根的子树后的部分中。这就需要我们另外维护一个数组`up[]`表示每个节点“向上”（在整棵树去掉以这个节点为根的子树的部分中）延伸的最长路径长度。

考虑`up[]`数组的求法。对于`v`而言，这条向上延伸的路径要么经过`u`以后继续向上，那就成了`up[u]`的情况；要么经过`u`以后向下延伸，进入`v`的某个兄弟。

因此整体算法过程如下：

1. 第一个深搜建树，并求`down[]`和`dmtr[]`。
2. 第二个深搜求`up[]`。
3. 第三个深搜求答案。

上面涉及许多选择兄弟的情况。每次我们都选择除了`v`自己最大的一个或两个兄弟。也就是说，选一个兄弟的时候，如果`v`自己是大哥，那就选二哥；不然直接选大哥。选两个兄弟的时候类似。

另一个问题是每个`dfs`不仅要更新`u`自己的信息，也要更新`u`的儿子`v`的信息。因为这里涉及到兄弟之间的处理，在父亲的层面才方便看清楚问题。需要注意“给儿子更新信息”和“递归调用儿子”这两个事情的先后依赖关系，这两者必然只能有一者在先，这也是为什么需要把前两个深搜给分开。

```cpp
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
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 100200
void update_mxs2(int t, int& mx1, int& mx2) {
    if (t >= mx1) mx2 = mx1, mx1 = t;
    else mx2 = max(mx2, t);
}

void update_mxs3(int t, int& mx1, int& mx2, int& mx3) {
    if (t >= mx1) mx3 = mx2, mx2 = mx1, mx1 = t;
    else if (t >= mx2) mx3 = mx2, mx2 = t;
    else mx3 = max(mx3, t);
}

struct Solve{
    int n;
    vector<int> son[N]; int fa[N];
    int down[N], up[N], dmtr[N];
    int ans[N];

    void dfs1(int u) {
        int dnmx1 = -1, dnmx2 = -1;
        for(int v : son[u]) if (v != fa[u]) {
            fa[v] = u;
            dfs1(v);
            update_mxs2(down[v], dnmx1, dnmx2); 
            dmtr[u] = max(dmtr[u], dmtr[v]);
        }
        down[u] = dnmx1 + 1;
        dmtr[u] = max(dmtr[u], dnmx1 + dnmx2 + 2);
    }

    void dfs2(int u) {
        int dnmx1 = -1, dnmx2 = -1;
        for(int v : son[u]) if (v != fa[u]) {
            update_mxs2(down[v], dnmx1, dnmx2); 
        }
        for(int v : son[u]) if (v != fa[u]) {
            up[v] = max(up[u] + 1, down[v] == dnmx1 ? dnmx2 + 2 : dnmx1 + 2);
            dfs2(v);
        }
    }

    void dfs3(int u) {
        int dnmx1 = -1, dnmx2 = -1, dnmx3 = -1;
        int drmx1 = 0, drmx2 = 0;
        int p = ans[u]; // obtained from fa[u]
        for(int v : son[u]) if (v != fa[u]) {
            ans[u] = max(ans[u], dmtr[v]);
            update_mxs3(down[v], dnmx1, dnmx2, dnmx3);
            update_mxs2(dmtr[v], drmx1, drmx2);
        }
        for(int v : son[u]) if (v != fa[u]) {
            int &mx = ans[v];
            mx = p;
            mx = max(mx, dmtr[v] == drmx1 ? drmx2 : drmx1);
            mx = max(mx, down[v] == dnmx1 ? up[u] + dnmx2 + 1 : up[u] + dnmx1 + 1);
            if (down[v] == dnmx1) mx = max(mx, dnmx2 + dnmx3 + 2);
            else if (down[v] == dnmx2) mx = max(mx, dnmx1 + dnmx3 + 2);
            else mx = max(mx, dnmx1 + dnmx2 + 2);
            dfs3(v);
        }
    }

    void solve() {
        n = read();
        rep(i, 1, n) son[i].clear();
        mmst(fa, 0);
        mmst(down, 0);
        mmst(up, 0);
        mmst(dmtr, 0);
        mmst(ans, 0);
        rep(i, 1, n-1){
            int u=read(), v=read();
            son[u].push_back(v);
            son[v].push_back(u);
        }
        dfs1(1);
        dfs2(1);
        dfs3(1);
        rep(i, 1, n) {
            printf("%d%c", ans[i], i < n ? 32 : 10);
        }
    }
}S;

int main() {
    int T=read();
    while(T--) {
        S.solve();
    }
    return 0;
}
```

