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
#include<iomanip>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef long double db;
inline int read(){
    int x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
const db eps=1e-10;
const db pi=acos(-1.0);
int dcmp(db x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct Point {
    db x, y;
    Point(db x=0, db y=0):x(x), y(y) { }
    void input(){ cin>>x>>y; }
    void output() {
        printf("(%.2lf, %.2lf)\n", x, y);
    }
};
typedef Point Vector;
Vector operator+ (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator- (Vector A, Vector B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator* (Vector A, db p) { return Vector(A.x*p, A.y*p); }
Vector operator/ (Vector A, db p) { return Vector(A.x/p, A.y/p); }
bool operator<(const Point& a, const Point& b) {
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool operator==(const Point& a, const Point& b) {
    return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);
}
db Dot(Vector a, Vector b) {return a.x*b.x+a.y*b.y;}
db Length(Vector a) {return sqrt(Dot(a, a));}
db Angle(Vector a, Vector b) {return acos(Dot(a, b)/Length(a)/Length(b));}
db Cross(Vector a, Vector b) {return a.x*b.y-a.y*b.x;}
Point GetLineProjection(Point P, Point A, Point B) {
    Vector v=B-A;
    return A+v*(Dot(v,P-A)/Dot(v,v));
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1=Cross(a2-a1,b1-a1), c2=Cross(a2-a1,b2-a1),
        c3=Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
struct Line {
    Point P; Vector v; double ang; Line() {}
    Line(Point P, Vector v):P(P), v(v) { ang = atan2(v.y, v.x); }
    bool operator< (const Line &L) const  { return ang < L.ang; }
    double value(double x) { return P.y + (x - P.x) * v.y / v.x; }
    void output() { printf("P=(%.2lf, %.2lf), v=(%.2lf, %.2lf)\n", P.x, P.y, v.x, v.y); }
};
bool OnLeft(Line L, Point p) { return dcmp(Cross(L.v, p-L.P)) >= 0; }
bool OnRight(Line L, Point p) { return dcmp(Cross(L.v, p-L.P)) <= 0; }
Point GetIntersection(Line a, Line b) {
    Vector u = a.P-b.P;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.P+(a.v*t);
}

#define N 30
Point pt[N][2];
int n;

bool canGoThrough(int k, Line l) {
    return OnLeft(l, pt[k][0]) && OnRight(l, pt[k][1]);
}

int farthestReach(Line l) {
    rep(i, 1, n) {
       if (!canGoThrough(i, l)) return i - 1; 
    }
    return n; 
}

vector<Line> ls;
int solve() {
    int mx = 0;
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            rep(u, 0, 1) {
                rep(v, 0, 1) {
                    Line l = Line(pt[i][u], pt[j][v]-pt[i][u]);
                    int k = farthestReach(l);
                    if (k > mx) {
                        ls.clear();
                        ls.push_back(l);
                        mx = k;
                    } else if (k == mx) {
                        ls.push_back(l);
                    }
                }
            }
        }
    }
    return mx;
}



int main() {
#ifdef D
    freopen("POJ-1039.in", "r", stdin);
    db TIMEA = clock();
#endif
    while(n=read()) {
        mmst(pt, 0);
        ls.clear();

        rep(i, 1, n) {
            db x, y; cin >> x >> y;
            pt[i][0] = Point(x, y);
            pt[i][1] = Point(x, y-1);
        }

        int st = solve();
        if (st == n) {
            puts("Through all the pipe.");
        } else {
            db ans = -1e100;
            Line l1 = Line(pt[st][0], pt[st+1][0]-pt[st][0]);
            Line l2 = Line(pt[st][1], pt[st+1][1]-pt[st][1]);
            db xs = pt[st][0].x;
            db xt = pt[st+1][0].x;
            For(i, ls.size()) {
                Line l = ls[i];
                db x1 = GetIntersection(l, l1).x;
                db x2 = GetIntersection(l, l2).x;
                // ans = max(ans, x1);
                // ans = max(ans, x2);
                if (dcmp(x1 - xs) >= 0 && dcmp(x1 - xt) <= 0) ans = max(ans, x1);
                if (dcmp(x2 - xs) >= 0 && dcmp(x2 - xt) <= 0) ans = max(ans, x2);
            }
            cout << fixed << setprecision(2) << ans << "\n";
        }
    }

#ifdef D
    db TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}