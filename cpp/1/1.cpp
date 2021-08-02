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


class Student {
private:
    string name;
    int age;
public:
    Student(string name, int age): name(name), age(age) { }

    static bool cmp1 (const Student &s1, const Student &s2) {
        return s1.age < s2.age || (s1.age == s2.age && s1.name < s2.name);
    }
    static bool cmp2 (const Student &s1, const Student &s2) {
        return s1.name < s2.name || (s1.name == s2.name && s1.age < s2.age);
    }

    void output() {
        cout << name << ", age: " << age << endl;
    }

};

int main() {
#ifdef D
    // freopen("1.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    Student A("Google", 12);
    Student B("Baidu", 1024);
    Student C("Yahoo", 100);
    vector<Student> v = {A, B, C};
    sort(v.begin(), v.end(), Student::cmp2);
    for(auto s : v) {
        s.output();
    }
    sort(v.begin(), v.end(), Student::cmp1);
    for(auto s : v) {
        s.output();
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}