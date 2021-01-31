# LightOJ 1027 & LightOJ 1395: Expectation

## Memoryless Version

https://vjudge.net/problem/LightOJ-1027

We want to find out the expected time to get out of the maze. As the expectation of the sum of a series of random variables equals the sum of the expectation of a series of random variables, we could split the total time into contributions of each door. Formally, let random variable $T$ denote the expected time to get out, and $T_1, T_2, \dots, T_n$ denote the expected time we spend on door $i$. Also, let $X_i$ denote the expected number of times we go through door $i$, then we have
$$
E(T)=\sum_{i=1}^n E(T_i)=\sum_{i=1}^n t_iE(X_i)
$$
where $t_i$ is the given time to go through each door each time.

Then clearly all we need to do is to figure out $E(X_i)$. We can calculate it using the definition of expectations:
$$
E(X_i)=1 \cdot \frac1n + 1 \cdot \frac {n_2}{n} \cdot \frac 1n + 1 \cdot \left(\frac{n_2} {n}\right)^2\cdot \frac 1n + \dots = \frac 1 {n-n_2}=\frac1{n_1}
$$
where $n,n_1,n_2$ respectively denotes the number of all doors, the number of doors that take you out (type 1 door for short), and the number of doors that take you back to the beginning (type 2 door). To see this formula above: initially, you have the probability of $1/n$ to choose door $i$ once; however, if you happen to choose a type 2 door with probability $n_2 / n$ (not to the exclusion of door $i$ itself), you then still have the probability of $1/n$ to choose door $i$ once again, and this goes on and on. Using a simple Taylor expansion we could derive the final form of this formula.

Another more general way to show this:
$$
E(X_i)=1 \cdot \frac1n + 1 \cdot \frac {n_2}{n} \cdot E(X_i)
$$
This is because after being taken back by a type 2 door, **everything returns to the same as the beginning status**.

Thus our answer for $E(T)$ is
$$
E(T)=\frac 1 {n_1} \sum_{i=1}^n t_i
$$

## Memory Version

https://vjudge.net/problem/LightOJ-1395

If we could remember the last $K$ doors which did not take us out, this problem gets complicated because $E(X_i)$ for type 1 doors and type 2 doors are different. We should limit $K \le n_2$ because otherwise our memory is too large and useless. Let $T_1$ and $T_2$ respectively denote the set of subscripts of all type 1 and type 2 doors. Let $f(k)$ denote $E(X_i)$ when $i \in T_1$ and we have remembered $k$ doors $(0 \le k \le K)$ and $g(k)$ has the same definition of $f(k)$ except that $i \in T_2$. 

We first attempt to calculate $f(k)$. When $k=K$, we have 
$$
f(K) = \frac 1 {n-K} + \frac {n_2 - K} {n - K} \cdot f(K)
$$
Thus,
$$
f(K) = \frac 1 {n - n_2}
$$
When $k < K$, we have 
$$
f(k) = \frac 1 {n-k} + \frac {n_2 - k} {n-k} \cdot f(k+1)
$$
Notice that now we do not return to the initial status after choosing a type a door **because we now remember one more door**, which is reflected in the parameter of $f$. 

Try to let $k=K-1$ and we could obtain that
$$
f(K-1)=\frac 1 {n - n_2} = f(K)
$$
By mathematical induction we can prove that for all $k$, 
$$
f(k) = \frac 1 {n-n_2}
$$
which could be a little surprising before we observe that the problem here is actually the same as the memoryless version, as what we remember are only type 2 doors which do not interfere with type 1 doors, and the result of the memoryless version is only related to $n_1$. Nevertheless, we have double checked our conjecture, and we may now safely move onward to calculate $g(k)$.

To calculate $g(k)$, when $k=K$, we have
$$
g(K) = \frac {n_2 - K} {n_2} \cdot \frac {1}{n-K} + \frac{n_2 -K}{n -K} \cdot g(K)
$$
**Notice that given you could remember $K$ type 2 doors, a particular type 2 door $i$ may be unavailable to choose at a given turn!** Since all type 2 doors are identical, the probability that you can choose door $i$ (in other words, you do not remember entering it) at a given turn is $(n_2 - K) / n_2$. This is exactly how $g(K)$ differs from $f(K)$.

We could thus derive that 
$$
g(K)=\frac {n_2 - K} {n_2 (n - n_2)}
$$
When $k < K$,
$$
g(k) = \frac {n_2 - k} {n_2} \cdot \frac {1}{n-k} + \frac{n_2 -k}{n -k} \cdot g(k+1)
$$
There seems not to be a simple reduced form for $g(k)$, so we just use dynamic programming to calculate the value of $g(0)$.

Together, 
$$
E(T) = \frac 1 {n_1} \sum_ {i \in T_1} t_i + g(0) \sum_ {i \in T_2} t_i
$$
Notice when $n_2 = 0$ we let $g(0) = 0$, and when $n_1 = 0$ the expected time is infinity since we can never get out.

Code:

```cpp
#include<bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define coutP(i) cout<<fixed<<setprecision(i)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

ld g0(int K, int n, int n2) {
    if (!n2) {
        return 0;
    }
    ld g = (ld)(n2 - K) / n2 / (n - n2);
    rev(k, K-1, 0) {
        g = (ld)(n2 - k) / (n - k) * (1/(ld)n2 + g);
    }
    return g;
}

void solve() {
    int n=read(), K=read();
    ll st1 = 0; ll st2 = 0;
    int n1 = 0; int n2 = 0;
    rep(i,1,n){
        ll a=read();
        if (a > 0) {
            st1 += a;
            n1++;
        } else {
            st2 -= a;
            n2++;
        }
    }
    if (!n1) {
        puts("-1");
        return;
    }
    ld ans = (ld)st1 / n1 + g0(min(K, n2), n, n2) * (ld) st2;
    coutP(10) << ans << endl;
}

int main() {
    int T=read();
    rep(cas,1,T){
        printCase(cas);
        solve();
    }
    return 0;
}
```

