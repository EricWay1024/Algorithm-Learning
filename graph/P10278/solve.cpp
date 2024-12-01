// Title:  Painting Fence Posts
// Source: USACO24OPEN Silver
// Author: Jerrywang
#include <bits/stdc++.h>
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, s, t) for (int i = s; i <= t; ++i)
#define debug(x) cerr << #x << ":" << x << endl;
const int N = 1000010;
using namespace std;

int n, nn, m;
map<int, set<int>> row, col;
// row,col:   相同行（列）上的点的列（行）坐标
map<pii, int> id;
pii point[N];
// point[i]:  原始编号为i的点的坐标
// id[{x,y}]: 坐标为(x,y)的点的最小原始编号
vector<int> g[N];
int a[N], a_id[N], cnt[N];
ll d[N];
// a[i]:      环上编号为i的点的原始编号
// a_id[i]:   原始编号为i的点的环上编号
ll dis(pii a, pii b)
{
    return abs(a.F - b.F) + abs(a.S - b.S);
}
void add(int u, int v)
{
    g[u].push_back(v), g[v].push_back(u);
}
bool vis[N];
void dfs(int u)
{
    a[++nn] = u;
    vis[u] = 1;
    for (int v : g[u])
        if (!vis[v])
            dfs(v);
}

int main()
{
#ifdef Jerrywang
    freopen("E:/OI/in.txt", "r", stdin);
#endif
    scanf("%d%d", &m, &n);
    rep(i, 1, n)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        id[{x, y}] = i, point[i] = {x, y};
        row[x].insert(y), col[y].insert(x);
    }
    rep(i, 1, m)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        point[n + i] = {x1, y1}, point[n + m + i] = {x2, y2};
        if (!id[{x1, y1}])
            id[{x1, y1}] = n + i, row[x1].insert(y1), col[y1].insert(x1);
        if (!id[{x2, y2}])
            id[{x2, y2}] = n + m + i, row[x2].insert(y2), col[y2].insert(x2);
    }
    for (auto &[x, S] : row)
    {
        auto i = S.begin();
        while (i != S.end())
        {
            for (; i != S.end(); i++)
                if (id[{x, *i}] <= n)
                    break;
            auto j = next(i), k = i;
            for (; j != S.end(); j++)
                if (id[{x, *j}] <= n)
                    break;
            if (j == S.end())
                break;
            for (; k != j; k++)
                add(id[{x, *k}], id[{x, *next(k)}]);
            i = next(j);
        }
    }
    for (auto &[y, S] : col)
    {
        auto i = S.begin();
        while (i != S.end())
        {
            for (; i != S.end(); i++)
                if (id[{*i, y}] <= n)
                    break;
            auto j = next(i), k = i;
            for (; j != S.end(); j++)
                if (id[{*j, y}] <= n)
                    break;
            if (j == S.end())
                break;
            for (; k != j; k++)
                add(id[{*k, y}], id[{*next(k), y}]);
            i = next(j);
        }
    }
    dfs(1);
    rep(i, 1, nn) a[nn + i] = a[i], a_id[a[i]] = i;
    rep(i, 2, nn + nn) d[i] = dis(point[a[i]], point[a[i - 1]]), d[i] += d[i - 1];
    rep(i, 1, m)
    {
        int u = a_id[id[point[n + i]]], v = a_id[id[point[n + m + i]]];
        ll d1, d2;
        if (d[u] < d[v])
        {
            d1 = d[v] - d[u], d2 = d[nn + u] - d[v];
            if (d1 < d2)
                cnt[u]++, cnt[v + 1]--;
            else
                cnt[v]++, cnt[nn + u + 1]--;
        }
        else
        {
            d1 = d[u] - d[v], d2 = d[nn + v] - d[u];
            if (d1 < d2)
                cnt[v]++, cnt[u + 1]--;
            else
                cnt[u]++, cnt[nn + v + 1]--;
        }
    }
    rep(i, 1, nn + nn) cnt[i] += cnt[i - 1];
    rep(i, 1, n)
        printf("%d\n", cnt[a_id[i]] + cnt[nn + a_id[i]]);

    return 0;
}