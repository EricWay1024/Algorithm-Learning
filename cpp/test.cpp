//#include <bits/stdc++.h>
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
#include<functional>
#include<numeric>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}

int x[100];
int main() {
#ifdef D
    // freopen("", "r", stdin);
    double TIMEA = clock();
#endif
    double sss = -1.0/0.0;
    cout << sss << endl;
    return 0;
    ll M = 1000000007ll;
    cout << M*M << endl;
    return 0;
    string c = "sfdf";
    cout << c + '1' << endl;

    auto f = [](int x, int y) -> int {
        return (x >> y) & 1;
    };
    cout << f(2, 1) << endl;
    iota(x, x + 10, 0);
    transform(x, x + 10, x, [](int x) -> int {
        cout << x << endl;
        return x + 1;
    });

    transform(x, x + 10, x, [](int x) -> int {
        cout << x << endl;
        return x + 1;
    });

    int t = accumulate(x, x + 10, 0);
    cout << t << endl;
    int s = accumulate(x, x + 10, 0, [](int x, int y) -> int {
        return x > y ? x : y;
    });
    cout << s << endl;

    int maxx = distance(x, max_element(x, x + 10));

    cout << x[maxx] << " " << maxx << endl;

    cout << none_of(x, x + 10, [](auto x) -> int { return x > 100; }) << endl;
    cout << any_of(x, x + 10, [](auto x) -> int { return x > 100; }) << endl;
    cout << all_of(x, x + 10, [](auto x) -> int { return x > 100; }) << endl;

    int target[100];
    copy_n(x, 5, target);
    for_each(target, target + 5, [](int &x) -> void {
        cout << x << endl;
        x += 1;
        cout << x << endl;
    });

    for(int i = 0; i < 5; i++) {
        cout << target[i] << endl;
    }

    iota(target, target+100, 1000);
    copy_if(x, x + 10, target, [](int x) -> bool {return x > 6;});
    for(int i = 0; i < 10; i++) {
        cout << target[i] << endl;
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}