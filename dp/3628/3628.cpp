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
#define For(i,to) for(int i=0;i<(int)(to);++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 1123456
#define sq(i) ((i)*(i))
ll a, b, c, n, x[N], s[N], f[N], q[N], l, r;

ll h(ll i) {
    return a*sq(s[i])+b*s[i]+c;
}
ll p(ll i) {
    return a*sq(s[i])-b*s[i];
}

#define xx(j) (s[j])
#define yy(j) (f[j]+p(j))
#define slope(j1,j2) (double)(yy(j1)-yy(j2))/(xx(j1)-xx(j2))

int main() {
#ifdef D
    freopen("3628.in", "r", stdin);
    double TIMEA = clock();
#endif  
    n = read();
    a = -read(), b = -read(), c = -read();
    rep(i,1,n){
        x[i]=read();
        s[i]=s[i-1]+x[i];
    }
    l=r=1;
    rep(i,1,n){
        while(l<r && slope(q[l], q[l+1])<(double)2*a*s[i]) l++;
        f[i]=f[q[l]]+h(i)+p(q[l])-2*a*s[i]*s[q[l]];
        while(l<r && slope(q[r-1],q[r])>slope(q[r-1],i)) r--;
        q[++r]=i;
    }
    cout<<-f[n]<<endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}