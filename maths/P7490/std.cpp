#include <bits/stdc++.h>
#define LL __int128
#define ll long long
const ll ntf = 20190816170251;
using namespace std;
inline char rc()
{
    static char buf[1048576], *pn = buf, *pe = buf;
    return (pn == pe) && (pe = (pn = buf) + fread(buf, 1, 1048576, stdin), pn == pe) ? EOF : *pn++;
}
inline int read()
{
    int x = 0;
    char cc = rc();
    while (cc < '0' || cc > '9')
        cc = rc();
    while (cc >= '0' && cc <= '9')
        x = x * 10 + cc - '0', cc = rc();
    return x;
}
inline ll _read()
{
    ll x = 0;
    char cc = rc();
    while (cc < '0' || cc > '9')
        cc = rc();
    while (cc >= '0' && cc <= '9')
        x = x * 10 + cc - '0', cc = rc();
    return x;
}
void print(LL x)
{
    if (x > 9)
        print(x / 10);
    putchar(x % 10 ^ 48);
}
int id, n, m;
ll s[300007], d, p, q, r, SG[300007];
double sigma[7] = {0, 0.8047378541243, 0.5464101615137, 0.61803398874989};
inline ll _gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return _gcd(b, a % b);
}

// return floor(x * sigma)
ll _sigma(ll x)
{
    if (id < 4)
    {
        return x * sigma[id];
    }
    else
    {
        return x * p / q;
    }
}

ll sg(ll x)
{
    ll t1 = _sigma(x);
    if (t1 == 0)
        return 0;
    ll t2 = _sigma(x - t1);
    if (t1 == t2 && sg(x - t1) == t2)
        return t1 - 1;
    else
        return t1;
}

const LL M = ntf;
LL quick_pow(LL a, LL b)
{
    LL ans = 1;
    a %= M;
    for (; b; b >>= 1, a = a * a % M)
        if (b & 1)
            ans = ans * a % M;
    return ans;
}
LL inv(LL a)
{
    return quick_pow(a, M - 2);
}

int main()
{
    id = rc() - '0', n = read();
    for (int i = 1; i <= n; ++i)
        s[i] = _read();

    if (id >= 4)
    {
        p = _read(), q = _read(), d = _gcd(p, q), p /= d, q /= d;
    }
    d = r = m = 0;

    for (int i = 1; i <= n; ++i)
        SG[i] = sg(s[i]), d ^= SG[i];
    for (int i = 1; i <= n; ++i)
    {
        if (_sigma(s[i]) == 0)
        {
            m++;
        }
        else
        {
            ll aim = SG[i] ^ d;
            if (aim <= _sigma(s[i]) && aim != SG[i])
            {
                r += inv(_sigma(s[i]));
                if (r >= ntf)
                {
                    r -= ntf;
                }
            }
        }
    }
    print(d ? r * inv(n - m) % ntf : 0);
    putchar('\n');
    return 0;
}