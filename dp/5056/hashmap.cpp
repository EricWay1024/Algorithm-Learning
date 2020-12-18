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
#include<tuple>
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}

#define N 600000
#define M 590027

class HashMap {
private:
    struct Key {
        int i, j, k;
        Key(int _i=-1, int _j=-1, int _k=-1) {
            i = _i, j = _j, k = _k;
        }
    }key[N];
    int head[M]; int nxt[N];
    ll value[N];
    int sz;

public:
    HashMap() { clear(); }
    void clear() {
        memset(head, -1, sizeof(head));
        memset(nxt, -1, sizeof(nxt));
        memset(value, -1, sizeof(value));
        sz = 0;
    }
    #define ForHash(i,h) for(int i=head[h];~i;i=nxt[i])
    void push(int i, int j, int k, ll v) {
        int h = (i + j + k) % M;
        ForHash(u, h) {
            if (key[u].i == i && key[u].j == j && key[u].k == k) { 
                value[u] = v; 
                return;
            }
        }
        nxt[sz] = head[h]; head[h] = sz; 
        key[sz] = Key(i, j, k); value[sz] = v; sz++;
    }
    ll get(int i, int j, int k) {
        int h = (i + j + k) % M;
        ForHash(u, h) {
            if (key[u].i == i && key[u].j == j && key[u].k == k) 
                return value[u];
        }
        return -1;
    }
};
HashMap H;

int main() {
#ifdef D
    // freopen("", "r", stdin);
    double TIMEA = clock();
#endif
    H.push(1, 2, 3, 4);
    cout << H.get(1,2, 3) << endl;

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}