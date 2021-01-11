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
#include<climits>
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(register int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
typedef long int ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}

struct Point {
    int x, y;
    Point(int x=0, int y=0):x(x), y(y) { }
    void input(){ cin>>x>>y; }
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


struct Line {
    Point P;
    Vector v;
    Line() {}
    Line(Point P, Vector v):P(P), v(v) {}

    bool OnLeft(Point p) {
        return Cross(v, p-P) > 0;
    }
};

vector<Line> L;
int pcnt[5123];


int main() {
#ifdef D
    freopen("2318.in", "r", stdin);
    int TIMEA = clock();
#endif
    bool first=1;
    int n;
    while(n=read()) {
        if (first) { first = 0; }
        else putchar('\n');
        memset(pcnt, 0, sizeof(pcnt));
        L.clear();
        int m = read();
        int left=read(), up=read(), right=read(), down=read();
        For(i, n) {
            int ux=read(); int lx=read();
            L.push_back(Line(Point(lx, down), Point(ux, up) - Point(lx, down)));
        }
        L.push_back(Line(Point(right, down), Vector(1, 0)));

        For(i, m) {
            Point p; p.x=read(); p.y=read();
            int l = 0; int r = n; int ans = 0;
            while(l <= r) {
                int mid = (l+r) >> 1;
                if (L[mid].OnLeft(p)) {
                    ans = mid, r = mid - 1;
                }
                else l = mid + 1;
            }
            pcnt[ans]++;
        }

        rep(i, 0, n) {
            printf("%d: %d\n", i, pcnt[i]);
        }
    }

#ifdef D
    int TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}