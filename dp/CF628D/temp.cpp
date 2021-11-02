#include <bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(register int i=(int)from;i<=(int)to;++i)
#define For(i,to) for(register int i=0;i<(int)to;++i)
typedef long long ll;
inline ll read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}

int main() {
#ifdef D
    // freopen("", "r", stdin);
#endif
    For(i, 10){
        cout << i << endl;
    }
    rep(i, 1, 100) {
        cout << i << endl;
    }

    return 0;
}