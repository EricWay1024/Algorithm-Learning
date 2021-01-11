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
typedef long double ld;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x), y(y) { }
    void read(){ cin >> x >> y; }
    void output() {
        printf("(%lf, %lf)\n", x, y);
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
const double eps = 1e-10;
int dcmp(double x){
    if (fabs(x)<eps) return 0;
    else return x < 0 ? -1 : 1;
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

#define N 112345
Point p[N];
int n;
Point ch[N];
int k, m;

void ConvelHull() {
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

int main() {
#ifdef D
    freopen("2742.in", "r", stdin);
    double TIMEA = clock();
#endif
    n=read();
    For(i,n){
        p[i].read();
    }
    ConvelHull();
    double ans = 0.0;
    For(i,m-1){
        ans += Length(ch[i+1]-ch[i]);
    }
    For(i,m-1){
        ch[i].output();
    }
    printf("%.2lf\n", ans);


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}