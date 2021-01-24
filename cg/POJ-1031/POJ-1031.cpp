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
    double theta() {
        return atan2(y, x);
    }
};
typedef Point Vector;
Vector operator+ (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator- (Vector A, Vector B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator* (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator/ (Vector A, double p) { return Vector(A.x/p, A.y/p); }
db Dot(Vector a, Vector b) {
    return a.x*b.x+a.y*b.y;
}
db Length(Vector a) {
    return sqrt(Dot(a, a));
}
const db pi = acos(-1.0);

db Angle(Vector a, Vector b) {
    db ans = b.theta() - a.theta();
    if (ans > pi) ans -= 2 * pi;
    if (ans <= -pi) ans += 2 * pi;
    return ans;
}
// db Angle(Vector a, Vector b) {
//     return acos(Dot(a, b)/Length(a)/Length(b));
// }
db k, h; int n;
vector<Point> poly;

void solve() {
    poly.clear();
    cin >> k >> h >> n;
    For(i, n) {
        Point p; 
        p.input();
        poly.push_back(p);
    }
    db sum = 0;
    db mx = 0, mn = 0;

    For(i, n) { 
        db theta = Angle(poly[i], poly[(i+1)%n]);
        sum += theta;
        if (sum > mx) mx = sum;
        if (sum < mn) mn = sum;
        if (mx - mn >= 2 * pi) {
            mx = mn + 2 * pi;
            break;
            //如果是个类似螺旋形状就会大于2pi
        }
    }

    db ans = k * h * (mx - mn);
    printf("%.2lf\n", ans);
}

int main() {
#ifdef D
    freopen("POJ-1031.in", "r", stdin);
    // UVA-667
    double TIMEA = clock();
#endif
    int T=read();
    while(T--){
        solve();
        if(T)putchar(10);
    }


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}