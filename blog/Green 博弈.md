# Green Hackenbush 博弈

经典游戏**Green Hackenbush**。给定一个有根图，每次删除一条边，每条边删除后，不再和根相连的所有边也自动删除。无法删除者为负。公平游戏版本中，两个玩家都可以删所有的边。

此处考虑这是一个有根树的情况。最简单的情况是竹竿：如果竹竿长度是`n`，则每步都可以将竹竿长度变成`0`到`n-1`之间的任何数值，显然等价于一个Nim游戏。这自然可以拓展到竹林的情况，即多堆石子的组合Nim游戏，用Nim和求SG函数即可。

下面考虑树的情况。对于树的每个节点`u`，它的每个孩子都可以看成是互相独立的游戏，而每个孩子通过递归最后都可以化归为竹竿的情况。当然这一论述并不严谨，但结论非常直观，`sg[u]`就等于所有的孩子`v`的`sg[v]+1`的Nim和。

下面考虑图的情况。给两个结论：

1. 任何环内的节点可以融合成一点而不会改变图的SG函数值。
2. 拥有奇数条边的环可简化为一条边，偶数条边的环可简化为一个节点。

## LightOJ-1355 变形

[LightOJ - 1355 ](https://vjudge.net/problem/LightOJ-1355/origin)

是Green博弈的有根树的情形，但树有边权。原理是一样的，我们打个表找规律。设`v`是`u`的儿子边权为`w`，当`sg[v]=y`时，找`sg[u]`关于`w`和`y`的函数关系。

```cpp
int mem[100][100];
int sg(int w, int y) {
    if (w == 1) return y + 1;
    if (y == 0 && (w % 2) == 0) return 0; 
    if (mem[w][y] > -1) return mem[w][y];

    set<int> st;
    st.insert(sg(w-1, y));
    rep(i, 0, y-1) st.insert(sg(w, i));

    for(int i=0; ; ++i) {
        if (!st.count(i)) return mem[w][y]=i;
    }

}
```

可以观察到规律是：

```cpp
int sg(int w, int y) {
    if (w == 1) return y + 1;
    return (w&1) ? y^1 : y;
}
```

代码：

```cpp
int n;
const int N = 1024;
vector< pair<int, int> > son[N];
int dfs(int u, int fa) {
    int ans = 0;
    for(auto p: son[u]) {
        int v, w; tie(v, w) = p;
        if (v == fa) continue;
        ans ^= sg(w, dfs(v, u));
    }
    return ans;
}
void solve() {
    n=read();
    rep(i,1,n) son[i].clear();
    rep(i,1,n-1){
        int u=read()+1;
        int v=read()+1;
        int w=read();
        son[u].push_back(make_pair(v, w));
        son[v].push_back(make_pair(u, w));
    }
    int ans = dfs(1, 0);
    puts(ans ? "Emily" : "Jolly");
}
```

## Reference

https://blog.csdn.net/acm_cxlove/article/details/7854532