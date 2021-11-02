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
#include<numeric>
#include<functional>
#include<cstdint>
#include<climits>
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(register int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
struct Point {
    int x, y;
    Point(int x=0, int y=0):x(x), y(y) { }
    void input(){ x=read();y=read(); }
    void output() {
        printf("(%lf, %lf)\n", x, y);
    }
};
typedef Point Vector;
Vector operator+ (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator- (Vector A, Vector B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator* (Vector A, int p) { return Vector(A.x*p, A.y*p); }
bool operator< (const Point &a, const Point &b) {
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool operator== (const Point &a, const Point &b) {
    return a.x==b.x && a.y==b.y;
}
int Cross(const Vector &A, const Vector &B) {
    return A.x*B.y - A.y*B.x;
}
int Dot(const Vector &A, const Vector &B){
    return A.x*B.x+A.y*B.y;
}
int Length2(const Vector &A) {
    return Dot(A, A);
}

#define N 51234
Point p[N];
int n;
Point ch[N];

int ConvelHull() {
    int k, m=0;
    sort(p, p+n);
    n = distance(p, unique(p, p+n));
    For(i,n){
        while(m>1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    k = m;
    rev(i, n-2, 0){
        while(m>k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if (n > 2) m--;
    return m;
}


int solve() {
    int m = ConvelHull();
    if (m == 1) return 0;
    if (m == 2) return Length2(ch[0]-ch[1]);
    int ans = 0;
    // ch[m] = ch[0]; // already satisfies
    int v = 1;
    For(u, m) {
        while(1) {
            int diff = Cross(ch[u+1]-ch[u], ch[v+1]-ch[v]);
            if (diff <= 0) {
                ans = max(ans, Length2(ch[u]-ch[v]));
                if (diff == 0) ans = max(ans, Length2(ch[u]-ch[v+1]));
                break;
            }
            v = (v+1)%m;
        }
    }
    return ans;
}

int main() {
#ifdef D
    freopen("1452.in", "r", stdin);
    int TIMEA = clock();
#endif
    n=read();
    For(i,n){
        p[i].input();
    }
    cout << solve() << endl;
#ifdef D
    int TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}