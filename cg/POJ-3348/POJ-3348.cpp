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
typedef int db;
inline int read(){
    int x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

struct Point {
    db x, y;
    Point(db x=0, db y=0):x(x), y(y) { }
    void input(){ cin>>x>>y; }
};
typedef Point Vector;
Vector operator+ (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator- (Vector A, Vector B) { return Vector(A.x-B.x, A.y-B.y); }
bool operator<(const Point& a, const Point& b) {
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool operator==(const Point &a, const Point &b){
    return a.x==b.x && a.y==b.y;
}
db Cross(Vector a, Vector b) {return a.x*b.y-a.y*b.x;}

#define N 10010
Point p[N], ch[N];
int ConvexHull(int n) {
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
db ConvexPolygonArea(int n) {
    db area = 0;
    rep(i, 1, n-2) {
        area += Cross(ch[i]-ch[0],ch[i+1]-ch[0]);
    }
    return area;
}

int main() {
#ifdef D
    freopen("POJ-3348.in", "r", stdin);
    db TIMEA = clock();
#endif
    int n=read();
    For(i,n){
        p[i].input();
    }
    int m = ConvexHull(n);
    db area = ConvexPolygonArea(m);
    int ans = area / 100;
    printf("%d\n", ans);

#ifdef D
    db TIMEB=clock();
    printf("\n# Time consumed: %.3lfs.\n", (TIMEB-TIMEA)/1000.0);
#endif
    return 0;
}