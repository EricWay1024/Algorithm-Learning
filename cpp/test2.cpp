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

inline int read(){
    int x=0;bool s=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=0;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return s?x:~x+1;
}

int main() {
    // int a=read();
    // cout << a << endl;
    cout << atan2(-0.1, -1);

    // string s; cin >> s;
    // int c; cin >> c;
    // cout << s << endl;
    // cout << c << endl;
    // int a[][3] = {{1}, {3, 2}, {4,5,6}, {0}};
    // for(int i = 0; i < 4; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         printf("a[%d][%d]=%d ", i, j, a[i][j]);
    //     }
    //     cout<<endl;
    // }
    return 0;
}