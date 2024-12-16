#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
struct P
{
    int x, y, i;
    bool operator<(P a) const
    {
        return x < a.x || (x == a.x && (y < a.y || (y == a.y && i < a.i)));
    }
} p[N * 2];
bool ans[N];
int a[N], t, s[N];
bool f[N];
void add(int x)
{
    for (; x <= t; x += x & -x)
        ++s[x];
}
int sum(int x)
{
    int r = 0;
    for (; x; x -= x & -x)
        r += s[x];
    return r;
}
int main()
{
    int n, m, o, i, u = 0, d, h = -1, y, z;
    scanf("%d%d", &n, &m);
    o = n + m; // 点的总数
    for (i = 1; i <= n; ++i)
    {
        scanf("%d%d", &p[i].x, &p[i].y);

        // 所有 shortcut 的列坐标
        a[i] = p[i].y;
    }
    for (i = 1; i <= m; ++i)
    {

        scanf("%d%d", &p[i + n].x, &p[i + n].y);
        p[i + n].i = i;
        // 只有 query 的 p[_].i非零
    }
    sort(p + 1, p + o + 1);
    sort(a + 1, a + n + 1);
    t = unique(a + 1, a + n + 1) - a - 1;
    for (i = 1; i <= o; ++i)
        if (p[i].i)
        { // 询问
            // 如果这个点已经被标记成了shortcut
            if (!p[i - 1].i && p[i - 1].x == p[i].x && p[i - 1].y == p[i].y)
                ans[p[i].i] = 1;
            else if (p[i].x != h)
            {
                y = upper_bound(a + 1, a + t + 1, p[i].y) - a - 1;
                if ((p[i].y != a[y] || !f[y]) && p[i].y + u - sum(y) == p[i].x)
                    ans[p[i].i] = 1;
            }
        }
        else
        { // shortcut
            y = lower_bound(a + 1, a + t + 1, p[i].y) - a;
            // sum(y) = v 等于在p[i].y前面被删去了多少列
            d = u - sum(y);
            z = p[i].x - p[i].y;
            if (z < d)
            {
                // f[y] 是离散化后序号为 y 的列是否被删去了
                if (!f[y])
                    f[y] = 1, add(y);
            }
            else if (z > d && h != p[i].x)
                h = p[i].x, ++u;
            // h 是最后一个被删去的行号, u 是被删掉的总行数
        }
    for (i = 1; i <= m; ++i)
        puts(ans[i] ? "LOSE" : "WIN");
    return 0;
}