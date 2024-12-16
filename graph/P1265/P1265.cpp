#include <bits/stdc++.h>
#define N 5123
using namespace std;
struct Point
{
    long long x;
    long long y;
} city[N];

long long dist(Point &a, Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int n, m;
bool v[N];
long long d[N];

void prim()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int x = -1;
        long long min_dist = LONG_LONG_MAX;
        for (int j = 1; j <= n; j++)
        {
            if (!v[j] && (d[j] < min_dist))
                min_dist = d[j], x = j;
        }
        v[x] = 1;
        for (int y = 1; y <= n; y++)
        {
            if (!v[y])
                d[y] = min(d[y], dist(city[x], city[y]));
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> city[i].x >> city[i].y;
    }
    prim();
    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += sqrt((double)d[i]);
    printf("%.2f\n", ans);
    return 0;
}
