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
const double eps=1e-10;
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x), y(y) { }
    void input(){ cin>>x>>y; }
    void process() {
        if (!dcmp(x)) x = 0;
        if (!dcmp(y)) y = 0;
    }
    void output() {
        process();
        printf("%.5lf %.5lf\n", x, y);
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

Vector Normalize(Vector a) {
    return a/Length(a);
}

Point Project(Point a1, Point a2, Point b) {
    Vector v = Normalize(a2-a1);
    return a1 + v * Dot(b-a1, v);
}

double DistPoint2Line(Point a1, Point a2, Point b) {
    return Length(Project(a1, a2, b) - b);
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

Point ret[4];
double solve() {
    int m = ConvelHull();
    if (m == 1) {
        For(j, 4) ret[j] = ch[0];
        return 0;
    }
    if (m == 2) {
        ret[0] = ret[3] = ch[0];
        ret[1] = ret[2] = ch[1];
        return 0;
    }
    double ans = 1e100;
    // ch[m] = ch[0]; // already satisfies
    int v = 1, l, r = 1;

    #define nxt(i) i=(i+1)%m

    For(u, m) {
        while(Area(ch[u], ch[u+1], ch[v]) <= Area(ch[u], ch[u+1], ch[v+1])) nxt(v);
        if (!u) l = v; // important
        while(Dot(ch[u+1]-ch[u], ch[l+1]-ch[u]) <= Dot(ch[u+1]-ch[u], ch[l]-ch[u])) nxt(l);
        while(Dot(ch[u+1]-ch[u], ch[r+1]-ch[u]) >= Dot(ch[u+1]-ch[u], ch[r]-ch[u])) nxt(r);

        // cout << "---" << endl;
        // ch[u].output();
        // ch[u+1].output();
        // ch[v].output();
        // ch[l].output();
        // ch[r].output();
        // cout << "---" << endl;

        Point Vp = Project(ch[u], ch[u+1], ch[v]);
        Vector hv = ch[v] - Vp;
        double h = Length(hv);
        Point A[4];
        A[0] = Project(ch[u], ch[u+1], ch[l]);
        A[1] = Project(ch[u], ch[u+1], ch[r]);
        double w = Length(A[0]-A[1]);

        if (h * w < ans) { 
            ans = h * w;
            A[2] = A[1] + hv;
            A[3] = A[0] + hv;
            For(j, 4) ret[j] = A[j];
        }
    }
    return ans;
}

int main() {
#ifdef D
    freopen("3187.in", "r", stdin);
    int TIMEA = clock();
#endif
    n=read();
    For(i,n){
        p[i].input();
    }
    
    double ans = solve();

    int st = 0;
    For(j,4) 
        if (ret[j].y < ret[st].y || (ret[j].y == ret[st].y && ret[j].x < ret[st].x)) 
            st=j;
    
    printf("%.5lf\n", ans);
    For(i,4) {
        int j = (st + i) % 4;
        ret[j].output();
    }

#ifdef D
    int TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}