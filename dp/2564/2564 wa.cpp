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
using namespace std;
#define rep(i,from,to) for(register int i=(int)(from);i<=(int)(to);++i)
#define For(i,to) for(register int i=0;i<(int)(to);++i)
typedef long long ll;
inline int read(){
    ll x=0; ll sign=1; char c=getchar();
    while(c>'9' || c<'0') {if (c=='-') sign=-1;c=getchar();}
    while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*sign;
}
#define N 1001000
int n, k;
int pearl_cnt;
pair< int, int > pearl[N]; 

struct MYQ {
    deque< set<int> > q;
    set<int> allv;
    
    int get_front_x() {
        for(int j : q.front()) {
            return pearl[j].first;
        }
        return -1;
    }

    int get_back_x() {
        for(int j : q.back()) {
            return pearl[j].first;
        }
        return -1;
    }

    int pop_front(int v) {
        if (q.size() == 0) return 0;

        auto s = q.front();
        for(int j : s) {
            if (pearl[j].second == v) {
                s.erase(j);
                q.pop_front();
                if (s.size()) q.push_front(s);
                return 1;
            }
        }

        return 0;
    }

    void push_back(int i, int x, int v) {
        allv.insert(v);

        if (!q.size()) {
            q.push_back({i});
            return;
        }
        
        if (get_back_x() == x) {
            auto s = q.back();
            q.pop_back();
            s.insert(i);
            q.push_back(s);

        } else {
            q.push_back({i});
        }    
    }

    bool all_kind() {
        return allv.size() == k;
    }

    int get_current_ans() {
        return get_back_x() - get_front_x();
    }

}q;

int main() {
#ifdef D
    freopen("2564.in", "r", stdin);
    double TIMEA = clock();
#endif
    n = read();
    k = read();
    rep(i, 1, k) {
        int t = read();
        For(_, t) {
            pearl[++pearl_cnt] = make_pair(read(), i);
        }
    }
    sort(pearl + 1, pearl + n + 1);


    int ans = INT32_MAX;
    
    rep(i, 1, n) {
        auto &prl = pearl[i];
        int x, v; tie(x, v) = prl;

        q.pop_front(v);
        q.push_back(i, x, v);

        if (q.all_kind()) {
            ans = min(ans, q.get_current_ans());
        }
    }

    cout << ans << endl;


#ifdef D
    double TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (TIMEB-TIMEA)/1000);
#endif
    return 0;
}