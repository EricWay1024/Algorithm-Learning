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
// void dbg() {cout << "\n";}
// template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
// #define logs(x...) {cout << #x << " -> "; dbg(x);}
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
void readch(char& ch) {
  do ch = getchar();
  while (!isalpha(ch));
}

const int N = 1e6;
const int SQN = 1e3;
struct LinkedNodes {
    struct Node {
        Node* nxt;
        int size;
        char d[SQN * 2 + 10];

        Node() { nxt = NULL; size = 0; }

        void split() {
            if (size < SQN * 2) return ;
            Node* q = new Node;
            rep(i, SQN + 1, size) {
                q->append(d[i]);
            }
            q->nxt = nxt;
            nxt = q;
            size = SQN;
        }

        void append(char c) {
            d[++size] = c;
            split();
        }

        void insert(char c, int x) {
            size++;
            rev(i, size, x + 1) { swap(d[i - 1], d[i]); }
            d[x] = c;
            split();
        }

        void output() {
            rep(i, 1, size) cout << d[i];
            cout << endl;
        }
    };

    Node* head;
    Node* tail;
    int size;

    LinkedNodes() { head = new Node; tail = head; size = 0; }

    char query(int x) {
        for (Node* p = head; p != NULL; p = p->nxt) {
            if (x <= p->size) return p->d[x];
            else x -= p->size;
        }
    }

    void append(char c) {
        while (tail->nxt != NULL) tail = tail->nxt;
        tail->append(c);
        size++;
    }

    void insert(char c, int x) { 
        for (Node* p = head; p != NULL; p = p->nxt) {
            if (x <= p->size) {
                p->insert(c, x);
                size++;
                break;
            } else {
                x -= p->size;
            }
        }
    }

    void output() {
        for (Node* p = head; p != NULL; p = p->nxt) {
            p->output();
        }
    }
};


char s[N + 100];
int main() {
#ifdef D
    freopen("POJ-2887.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    LinkedNodes* lns = new LinkedNodes();
    scanf("%s", s);
    int len = strlen(s);
    For(i, len) {
        lns->append(s[i]);
    }
    int m = read();
    while (m--) {
        char o; readch(o);
        if (o == 'I') {
            char c; int x;
            readch(c); x = read();
            if (x > lns->size) lns->append(c);
            else lns->insert(c, x);
        } else {
            int x = read();
            printf("%c\n", lns->query(x));
        }
    }

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}