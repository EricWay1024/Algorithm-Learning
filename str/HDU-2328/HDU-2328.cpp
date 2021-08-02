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
// #include<unordered_map>
#include<utility>
#include<vector>
#include<numeric>
#include<functional>
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
const int N = 4010;
vector<string> s;
int k; int i0;
const int M = 10100;

// array index starts from zero
struct KMP {
    int f[N];
    void getFail(string &P)
    {
        f[0] = f[1] = 0;
        int m = P.length();
        rep(i, 1, m - 1)
        {
            int j = f[i];
            while (j && P[i] != P[j])
                j = f[j];
            f[i + 1] = P[i] == P[j] ? j + 1 : 0;
        }
    }

    int find(string &T, string &P)
    {
        getFail(P);
        int n = T.length(), m = P.length();
        int j = 0;
        For(i, n) {
            while (j && P[j] != T[i]) j = f[j];
            if (P[j] == T[i]) ++j;
            if (j == m) return i - m + 1;
        }
        return -1;
    }
}my_kmp;

set<string> subs;
void get_substr(int l) {
    string &t = s[i0];
    subs.clear();
    For(i, t.size() - l + 1) {
        subs.insert(t.substr(i, l));
    }
}

string ans_str;
bool check(int l) {
    if (l==0) return true;
    get_substr(l);
    for(auto t : subs) {
        my_kmp.getFail(t);
        bool flag = true;
        For(i, k) {
            if (i == i0) continue;
            if (my_kmp.find(s[i], t) == -1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans_str = t;
            return true;
        }
    }
    return false;
}

int main() {
#ifdef D
    freopen("HDU-2328.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    while((k=read())) {
        int l=0, r=300;
        s.clear();
        For(i, k) {
            string tmp; cin >> tmp;
            s.push_back(tmp);
            if (tmp.length() < r) {
                r = tmp.length();
                i0 = i;
            }
        }

        int ans=0; ans_str = "";
        while(l <= r) {
            int mid = (l+r)>>1;
            if (check(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        if (ans_str.length()) cout << ans_str << endl;
        else puts("IDENTITY LOST");

    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}