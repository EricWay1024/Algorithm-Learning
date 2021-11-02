#include<bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int f0(int n) {
    int ans=0;
    rep(i,1,n-1){
        ans += i * n / gcd(i, n);
    }
    return ans;
}

int phi(int n) {
    int ans=0;
    rep(i,1,n-1) if (gcd(i,n)==1) ans++;
    return ans;
}

int f1(int n) {
    int ans=0;
    rep(d, 1, n) if(!(n%d)) {
        printf("d=%d\n", d);
        ans += d * phi(d) / 2;
    }
    return ans * n;
}
int main() {
    rep(i,1,10) {
        cout << f0(i) << ' ' << f1(i) << endl;
    }
}