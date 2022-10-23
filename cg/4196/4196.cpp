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

const double eps=1e-10;
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x), y(y) { }
    void input(){ cin>>x>>y; }
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
    return a.x==b.x && a.y==b.y;
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
    double ang;
    Line() {}
    Line(Point P, Vector v):P(P), v(v) { ang = atan2(v.y, v.x); }
    bool operator< (const Line &L) const  {
        return ang < L.ang;
    }
};
bool OnLeft(Line L, Point p) {
    return Cross(L.v, p-L.P) > 0;
}
Point GetIntersection(Line a, Line b) {
    Vector u = a.P-b.P;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.P+(a.v*t);
}

typedef vector<Point> Polygon;
Line L[550]; int lcnt;
Polygon ret;
Point p[550];
Line q[550];

int HalfplaneIntersection() {
    int n = lcnt;
    sort(L, L + n);

    int first, last;
    q[first=last=0] = L[0];
    for(int i = 1; i < n; i++) {
        while(first < last && !OnLeft(L[i], p[last-1])) --last;
        while(first < last && !OnLeft(L[i], p[first])) ++first;
        q[++last] = L[i];
        if (!dcmp(Cross(q[last].v, q[last-1].v))) {
            --last;
            if(OnLeft(q[last], L[i].P)) q[last] = L[i];
        }
        if (first < last) p[last-1] = GetIntersection(q[last-1], q[last]);
    }
    while(first < last && !OnLeft(q[first], p[last-1])) --last;

    if (last - first <= 1) return 0;
    p[last] = GetIntersection(q[last], q[first]);

    int m = 0;
    for(int i = first; i <= last; i++) {
        ret.push_back(p[i]);
        ++m;
    }
    return m;
}

double getPolygonArea(Polygon &p) {
    double area = 0.0;
    for(int i = 1; i < p.size()-1; i++) {
        area += Cross(p[i]-p[0], p[i+1]-p[0]);
    }
    return area*0.5;
}

int main() {
#ifdef D
    freopen("4196.in", "r", stdin);
    double TIMEA = clock();
#endif
    int n = read();
    For(i, n) {
        int m = read();
        Polygon poly;
        For(j, m) {
            Point p; 
            p.input();
            poly.push_back(p);
        }
        For(j, m) {
            L[lcnt++] = Line(poly[j], poly[(j+1)%m]-poly[j]);
        }
    }
    int m = HalfplaneIntersection();
    double ans = m ? getPolygonArea(ret) : 0;
    printf("%.3lf\n", ans);

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}