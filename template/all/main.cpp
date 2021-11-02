#include<bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
#ifdef D
void dbg() {cout << endl;}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#else
#define logs(x...) { }
#endif
#define mmst(a,x) memset(a, x, sizeof(a))
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
int main() {
#ifdef D
    freopen("", "r", stdin);
#endif
    return 0;
}