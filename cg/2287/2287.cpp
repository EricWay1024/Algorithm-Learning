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
const double eps = 1e-10;
double randeps() {
    return (rand() / (double)RAND_MAX - 0.5) * eps;
}
struct Point {
    double x,y,z;
    void input(){
        cin >> x >> y >> z;
        x += randeps();
        y += randeps();
        z += randeps();
    }
};
typedef Point Vector;
Vector operator- (const Vector &a, const Vector &b) {
    return (Vector){a.x-b.x, a.y-b.y, a.z-b.z};
}
double operator* (const Vector &a, const Vector &b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
Vector Cross(Vector a, Vector b) {
    return (Vector){a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
}
double Length(Vector a) {
    return sqrt(a*a);
}
double Area(Point a, Point b, Point c) {
    return Length(Cross(b-a, c-a)) * 0.5;
}
#define N 112
Point P[N];
int n;

// struct Face{
//     int v[3];
//     Vector normal() {
//         return Cross(P[v[1]]-P[v[0]], P[v[2]]-P[v[0]]);
//     }
// };

bool check(int i, int j, int k) {
    Vector normal = Cross(P[j]-P[i], P[k]-P[i]);
    int c1 = 0; int c2 = 0;
    For(l, n) {
        if (l == i || l == j || l == k) continue;
        if ((P[l] - P[i]) * normal > 0) c1++;
        else c2++;
        if (c1 && c2) return false;
    }
    return true;
}


int main() {
#ifdef D
    freopen("2287.in", "r", stdin);
    double TIMEA = clock();
#endif
    cin >> n;
    For(i, n) P[i].input();
    double ret = 0.0;
    For(i, n){
        rep(j, i+1, n-1){
            rep(k, j+1, n-1){
                if (check(i, j, k)){
                    ret += Area(P[i], P[j], P[k]);
                }
            }
        }
    }
    printf("%.6lf\n", ret);

#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}