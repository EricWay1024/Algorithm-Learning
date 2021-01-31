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
#include<iomanip>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll;
typedef long double ld;
typedef double db;
inline ll read(){
    ll x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}
struct Date {
    int y, m, d;

    bool valid() {
        if (m>12) return false;
        if (m==1||m==3||m==5||m==7||m==8||m==10||m==12) {
            return d<=31;
        }
        if (m==4||m==6||m==9||m==11){
            return d<=30;
        }
        if ((y%4==0 && y%100!=0) || y%400==0) {
            return d<=29;
        }
        return d<=28;
    }

    void nextDay() {
        d++;
        if (!valid()) d=1, m++;
        if (!valid()) m=1, y++;
    }

    bool nextMonth() {
        m++;
        if (m > 12) m=1, y++;
        return (valid()); 
    }

    void output() {
        printf("%d %d %d\n", y, m, d);
    }

    int calc_hash() {
        return d + m * 150 + (y-1899) * 150 * 150;
    }

    // void get_from_hash(int h) {
    //     d = h % 150;
    //     h/=150;
    //     m = h % 150;
    //     h/=150;
    //     y = (h % 150) + 1899;
    // }

    bool operator> (const Date &b) {
        return y>b.y || (y==b.y && m>b.m) || (y==b.y && m==b.m && d>b.d);
    }

    bool operator== (const Date &b) {
        return y==b.y && m==b.m && d==b.d;
    }

    bool operator>= (const Date &b) {
        return y>b.y || (y==b.y && m>b.m) || (y==b.y && m==b.m && d>=b.d);
    }

    void input() {
        y=read(), m=read(), d=read();
    }

};

map<int, int> mp;
int solve(Date dt) {
    if (dt == (Date){2001, 11, 4}) return -1;
    if (dt > (Date){2001, 11, 4}) return 1;
    int &ret = mp[dt.calc_hash()];
    if (ret) return ret;

    Date ndt = dt;
    ndt.nextDay();
    int res1 = solve(ndt);

    int res2 = 1;
    Date nmdt = dt;
    if (nmdt.nextMonth()) {
        res2 = solve(nmdt);
    }

    if (res1 == -1 || res2 == -1) return ret = 1;
    else return ret = -1;

}

int main() {
#ifdef D
    freopen("HDU-1079.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    int T=read();
    while(T--){
        Date dt; dt.input();
        cout << (solve(dt) == 1 ? "YES" : "NO") << endl;
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}