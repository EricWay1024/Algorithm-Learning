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
typedef double db;
inline int read(){
    int x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
const db eps=1e-8;
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
        cout << fixed << setprecision(2) << "POINT " << x << " " << y << endl; 
        // printf("POINT %.2lf, %.2lf\n", x, y);
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
    void output() { printf("P=(%.2lf, %.2lf), v=(%.2lf, %.2lf)\n", P.x, P.y, v.x, v.y); }
};
bool OnLine(Line L, Point p) { return dcmp(Cross(L.v, p-L.P))==0; }
Point GetIntersection(Line a, Line b) {
    Vector u = a.P-b.P;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.P+(a.v*t);
}

int main() {
#ifdef D
    freopen("POJ-1269.in", "r", stdin);
    db TIMEA = clock();
#endif
    puts("INTERSECTING LINES OUTPUT");
    int T=read();
    while(T--){
        Point a, b, c, d;
        a.input(); b.input(); c.input(); d.input();
        Line m = Line(a, b-a);
        Line n = Line(c, d-c);
        if (!dcmp(Cross(m.v, n.v))) {
            if (OnLine(m, n.P)) {
                puts("LINE");
            } else {
                puts("NONE");
            }
        } else {
            Point p=GetIntersection(m, n);
            p.output();
        }
    }
    puts("END OF OUTPUT");


#ifdef D
    db TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}