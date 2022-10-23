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
// #include<cstdint>
#include<climits>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef long long ll;
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
const double eps=1e-8;
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x), y(y) { }
    void input(){ cin>>x>>y; }
    void output() {
        printf("%.5lf, %.5lf\n", x, y);
    }
};
typedef Point Vector;
Vector operator+ (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator- (Vector A, Vector B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator* (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator/ (Vector A, double p) { return Vector(A.x/p, A.y/p); }
bool operator< (const Point &a, const Point &b) {
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool operator== (const Point &a, const Point &b) {
    return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);
}
double Cross(const Vector &A, const Vector &B) {
    return A.x*B.y - A.y*B.x;
}
double Dot(const Vector &A, const Vector &B){
    return A.x*B.x+A.y*B.y;
}
double Length(const Vector &A) {
    return sqrt(Dot(A, A));
}
double Area(Point a, Point b, Point c) {
    return 0.5 * Cross(b-a, c-a);
}

struct Line {
    Point P;
    Vector v;
    Line() {}
    Line(Point P, Vector v):P(P), v(v) {  }
    double value(double x) {
        return P.y + (x - P.x) * v.y / v.x;
    }
};
struct Segment {
    Point A, B;
};

int pointPosition(Line L, Point p) {
    return dcmp(Cross(L.v, p-L.P));
}
bool haveIntersection(Line L, Segment S) {
    return pointPosition(L, S.A) * pointPosition(L, S.B) <= 0;
}

Point pt[300];
Segment sg[300];

int main() {
#ifdef D
    freopen("POJ-3304.in", "r", stdin);
    double TIMEA = clock();
#endif
    int T = read();
    while(T--){
        int n = read();
        rep(i, 1, n) {
            pt[(i << 1) - 1].input();
            pt[i << 1].input();
            sg[i].A = pt[(i << 1) - 1];
            sg[i].B = pt[i << 1];
        }
        bool ans = false;
        rep(i, 1, n << 1) {
            rep(j, i + 1, n << 1) {
                if (pt[j] == pt[i]) continue; // remember to rule out duplicate points!
                Line l = Line(pt[i], pt[j]-pt[i]);
                bool allhave = true;
                rep(k, 1, n) {
                    if (!haveIntersection(l, sg[k])) {
                        allhave = false; break;
                    }
                }
                if (allhave) { ans = true; break; }
            }
            if (ans) break;
        }

        if (ans) puts("Yes!"); else puts("No!");
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}