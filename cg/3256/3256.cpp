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
#define double long double
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
    int index;
    Line() {}
    Line(Point P, Vector v, int index):P(P), v(v), index(index) { ang = atan2(v.y, v.x); }
    bool operator< (const Line &L) const  {
        return ang < L.ang;
    }
    double value(double x) {
        return P.y + (x - P.x) * v.y / v.x;
    }
    void output() {
        printf("P=(%.2lf, %.2lf), v=(%.2lf, %.2lf), index=%d\n", P.x, P.y, v.x, v.y, index);
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

// begin 
#define inf 1e50 // should be large enough
#define N 11234
vector<Line> L;
void HalfplaneIntersection(vector<Line> &L, vector<Point> &ret) {
    sort(L.begin(), L.end());
    Point *p = new Point[N];
    Line *q = new Line[N];
    int first, last;
    q[first=last=0] = L[0];
    for(int i = 1; i < L.size(); i++) {
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
    if (last - first <= 1) return;
    p[last] = GetIntersection(q[last], q[first]);
    for(int i = first; i <= last; i++) {
        if (p[i].y >= inf) continue;
        ret.push_back(p[i]);
    }
}

double b[N], k[N];
vector<Point> ret;
vector<int> ans;

int main() {
#ifdef D
    freopen("3256.in", "r", stdin);
    double TIMEA = clock();
#endif
    int n = read();
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n) {
        cin >> k[i];
        Line l = Line(Point(0, b[i]), Vector(1, k[i]), i);
        L.push_back(l);
    }
    L.push_back(Line(Point(0, 0), Vector(0, -1), 0));
    L.push_back(Line(Point(0, 0), Vector(1, 0), 0));
    L.push_back(Line(Point(inf, 0), Vector(0, 1), 0));
    L.push_back(Line(Point(0, inf), Vector(-1, 0), 0));

    HalfplaneIntersection(L, ret);

    for(auto l : L) {
        if (l.index == 0) continue;
        for(auto p : ret) {
            if (!dcmp(l.value(p.x) - p.y)) {
                ans.push_back(l.index);
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    For(i, ans.size()) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}