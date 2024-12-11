#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for (int i = a; i <= b; i++)
const ll inf = 0x7f7f7f7f;
ll s, A, B, TTT;
double ans = inf, t, dis[410][410];
double x[410], y[410], T[110];
double diss(double x1, double y1, double x2, double y2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
double ds(double x1, double y1, double x2, double y2) { return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); }
int main()
{
    scanf("%lld", &TTT);
    while (TTT--)
    {
        memset(dis, 0, sizeof(dis)), ans = inf;
        scanf("%lld%lf%lld%lld", &s, &t, &A, &B);
        f(i, 1, s)
        {
            scanf("%lf%lf%lf%lf%lf%lf%lf", &x[(i - 1) * 4 + 1], &y[(i - 1) * 4 + 1], &x[(i - 1) * 4 + 2], &y[(i - 1) * 4 + 2], &x[(i - 1) * 4 + 3], &y[(i - 1) * 4 + 3], &T[i]);
            double dab = ds(x[(i - 1) * 4 + 1], y[(i - 1) * 4 + 1], x[(i - 1) * 4 + 2], y[(i - 1) * 4 + 2]);
            double dac = ds(x[(i - 1) * 4 + 1], y[(i - 1) * 4 + 1], x[(i - 1) * 4 + 3], y[(i - 1) * 4 + 3]);
            double dbc = ds(x[(i - 1) * 4 + 2], y[(i - 1) * 4 + 2], x[(i - 1) * 4 + 3], y[(i - 1) * 4 + 3]);
            if (dab + dac == dbc)
                x[i * 4] = x[(i - 1) * 4 + 2] + x[(i - 1) * 4 + 3] - x[(i - 1) * 4 + 1], y[i * 4] = y[(i - 1) * 4 + 2] + y[(i - 1) * 4 + 3] - y[(i - 1) * 4 + 1];
            else if (dab + dbc == dac)
                x[i * 4] = x[(i - 1) * 4 + 1] + x[(i - 1) * 4 + 3] - x[(i - 1) * 4 + 2], y[i * 4] = y[(i - 1) * 4 + 1] + y[(i - 1) * 4 + 3] - y[(i - 1) * 4 + 2];
            else if (dbc + dac == dab)
                x[i * 4] = x[(i - 1) * 4 + 2] + x[(i - 1) * 4 + 1] - x[(i - 1) * 4 + 3], y[i * 4] = y[(i - 1) * 4 + 2] + y[(i - 1) * 4 + 1] - y[(i - 1) * 4 + 3];
            
            cout << i << " " << x[i*4] << " " << y[i*4] << endl;
        }
        f(i, 1, s * 4) f(j, 1, s * 4) if (i != j)
        {
            if ((i - 1) / 4 != (j - 1) / 4)
                dis[i][j] = t * diss(x[i], y[i], x[j], y[j]);
            else
                dis[i][j] = T[(i - 1) / 4 + 1] * diss(x[i], y[i], x[j], y[j]);
        }
        f(k, 1, s * 4) f(i, 1, s * 4) f(j, 1, s * 4) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        f(i, 1, 4) f(j, 1, 4) {
            ans = min(ans, dis[(A - 1) * 4 + i][(B - 1) * 4 + j]);
            // cout <<  dis[(A - 1) * 4 + i][(B - 1) * 4 + j] << endl;
        }
        printf("%.1lf\n", ans);
    }
    return 0;
}