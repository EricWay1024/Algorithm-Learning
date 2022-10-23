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
        printf("(%.2lf, %.2lf)\n", x, y);
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

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1=Cross(a2-a1,b1-a1), c2=Cross(a2-a1,b2-a1),
        c3=Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

struct Segment {
    Point A, B;
};
bool SPI(Segment s1, Segment s2) {
    return SegmentProperIntersection(s1.A, s1.B, s2.A, s2.B);
}

Point p[5000];
Segment wall[5000];

struct Dijkstra {
    struct Edge {
        int from, to; double dist;
        Edge(int u, int v, double d):from(u), to(v), dist(d) {}
        void output() {
            p[from].output();
            p[to].output();
            printf("from=%d, to=%d, dist=%.2lf\n\n", from, to, dist);
        }
    };
    struct HeapNode {
        double d;  int u;
        bool operator< (const HeapNode &rhs) const {
            return d>rhs.d;
        }
    };
    int n, m;
    vector<Edge> edges;
    vector<int> G[5000];
    bool done[5000];
    double d[5000];

    void init(int n) {
        this -> n = n;
        For(i, n) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, double dist) {
        edges.push_back(Edge(from, to, dist));
        m=edges.size();
        edges[m-1].output();
        G[from].push_back(m-1);
    }

    double dijkstra(int s, int t) {
        priority_queue<HeapNode> Q;
        For(i, n) d[i] = 1e100;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeapNode){0,s});
        while(Q.size()) {
            HeapNode x=Q.top(); Q.pop();
            int u = x.u;
            if(done[u])continue;
            done[u]=1;
            For(i, G[u].size()) {
                Edge &e = edges[G[u][i]];
                if(d[e.to] > d[u] + e.dist) {
                    d[e.to] = d[u] + e.dist;
                    Q.push((HeapNode){d[e.to], e.to});
                }
            }
        }
        return d[t]; 
    }
}Dij;

double dist_two_points(Point ps, int ls, Point pt, int lt) {
    Segment x = (Segment){ps, pt};
    rep(i, ls + 1, lt - 1) {
        For(j, 3) {
            Segment y = wall[i*3 + j];
            if (SPI(x, y)) return -1;
        }
    }
    return Length(ps-pt);
}

int main() {
#ifdef D
    freopen("POJ-1556.in", "r", stdin);
    double TIMEA = clock();
#endif
    int n;
    while(n = read()) {
        if (n == -1) return 0;
        For(j, 4) p[j] = Point(0, 5);
        For(i, n) {
            double x; double y[4];
            cin >> x;
            For(j, 4) cin >> y[j];
            For(j, 4) {
                p[((i+1) << 2) + j] = Point(x, y[j]);
            }
            wall[i*3] = (Segment){Point(x, 0), Point(x, y[0])};
            wall[i*3+1] = (Segment){Point(x, y[1]), Point(x, y[2])};
            wall[i*3+2] = (Segment){Point(x, y[3]), Point(x, 10)};
        }
        For(j, 4) p[((n+1) << 2) + j] = Point(10, 5);

        Dij.init(((n+2) << 2));

        rep(i, 0, n+2-1) {
            For(j, 4) {
                Point ps = p[i*4+j];

                rep(l, i+1, n+2 - 1) {
                    bool flag = false;
                    For(r, 4) {
                        Point pt = p[l*4+r];

                        double d = dist_two_points(ps, i, pt, l);
                        if (d >= 0) {
                            // cout << i * 4 + j << endl;
                            // cout << l * 4 + r << endl;
                            Dij.AddEdge(i*4+j, l*4+r, d);
                            flag = true;
                        }
                    }
                    if (!flag) break;
                }
            }
        }

        double ans = Dij.dijkstra(0, ((n+1) << 2));
        printf("%.2lf\n", ans);
        
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/1000);
#endif
    return 0;
}