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
bool OnLeft(Line L, Point p) { return Cross(L.v, p-L.P) > 0; }
Point GetIntersection(Line a, Line b) {
    Vector u = a.P-b.P;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.P+(a.v*t);
}
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
        ret.push_back(p[i]);
    }
}
void ConvelHull(Point *p, Point *ch, int n, int &m) {
    m = 0;
    sort(p, p+n);
    For(i,n){
        while(m>1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    k = m;
    rev(i, n-2, 0){
        while(m>k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
}
typedef vector<Point> Polygon;
double getPolygonArea(Polygon &p) {
    double area = 0.0;
    for(int i = 1; i < p.size()-1; i++) {
        area += Cross(p[i]-p[0], p[i+1]-p[0]);
    }
    return area*0.5;
}