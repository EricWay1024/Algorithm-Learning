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

void readchar(char &c) {
    do c = getchar();
    while (!(c >= 32 && c <= 126));
}

void readup(char &c) {
    do c = getchar();
    while (!(c >= 'A' && c <= 'Z'));
}

// const int B = 10;
const int B = 1448;
const int N = 2 * 1024 * 1024 + 9000;
struct LinkedNodes {
    struct Node {
        Node* nxt;
        int size; 
        char d[B * 2 + 10];

        Node() { nxt = NULL; size = 0; }
        void add(char c) { d[++size] = c; }

        void combine() {
            if (nxt == NULL) return ; 
            if (size > B / 2 || nxt->size > B / 2) return ;
            rep(i, 1, nxt->size) {
                add(nxt->d[i]);
            }
            Node* temp = nxt->nxt;
            delete nxt;
            nxt = temp;
        }

        void insert(int x, char s[], int len) {
            // insert after xth char
            rep(i, x + 1, size) s[++len] = d[i];
            size = x;

            int t = (len + B - 1) / B;
            Node* temp = nxt;
            Node* last = this;
            rep(i, 1, t) {
                Node *q = new Node;
                int l = (i - 1) * B + 1;
                int r = min(i * B, len);
                rep(j, l, r) q->add(s[j]);
                last->nxt = q;
                last = q;
            }
            last->nxt = temp;
        }

        void remove(int x, int len) {
            // remove x+1, x+2, ... x+len
            rep(i, x + len + 1, size) {
                d[i - len] = d[i];
            }
            size -= len;
        }

        void query(int x, int len) {
            rep(i, x + 1, x + len) {
                putchar(d[i]);
            }
        }

        void output() {
            rep(i, 1, size) cout << d[i]; printf("  size = %d\n", size);
        }
    };

    Node* head; 
    int cur;

    LinkedNodes() { head = new Node(); cur = 0;}
    
    void move(int x) { cur = x; }
    void prev() { cur--; }
    void nekst() { cur++; }

    void maintain() {
        while (head->size == 0 && head->nxt != NULL) {
            Node* temp = head->nxt;
            delete head;
            head = temp;
        }
        for (Node *p = head; p != NULL; p = p->nxt) {
            p->combine();
            while (p->nxt != NULL && p->nxt->size == 0) {
                Node* temp = p->nxt->nxt;
                delete p->nxt;
                p->nxt = temp;
            }
        }
    }

    void insert(char s[], int len) {
        int x = cur; 
        for (Node* p = head; p != NULL; p = p->nxt) {
            if (x <= p->size) {
                p->insert(x, s, len);
                break;
            } else {
                x -= p->size;
            }
        }
    }

    void remove(int len) {
        int x = cur;
        for (Node *p = head; p != NULL; p = p->nxt) {
            if (x < p->size) {
                int clen = min(len, p->size - x);
                p->remove(x, clen);
                len -= clen;
                x = 0;
                if (len == 0) break;
            } else {
                x -= p->size;
            }
        } 
        maintain();
    }

    void query(int len) {
        int x = cur;
        for (Node *p = head; p != NULL; p = p->nxt) {
            if (x < p->size) {
                int clen = min(len, p->size - x);
                p->query(x, clen);
                len -= clen;
                x = 0;
                if (len == 0) break;
            } else {
                x -= p->size;
            }
        }
    }

    void output() {
        int i = 0;
        logs(cur);
        for (Node* p = head; p != NULL; p = p->nxt) {
            printf("Block %d: ", ++i); p->output();
        }
        cout << endl;
    }
};

char s[N];

int main() {
#ifdef D
    freopen("P4008.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    LinkedNodes* ls = new LinkedNodes();
    int T = read();
    while (T--) {
        char o; readup(o);
        // logs(o)
        if (o == 'M') {
            int k = read();
            ls->move(k);
        } else if (o == 'I') {
            int n = read();
            rep(i, 1, n) readchar(s[i]);
            ls->insert(s, n);
        } else if (o == 'P') {
            ls->prev();
        } else if (o == 'N') {
            ls->nekst();
        } else if (o == 'D') {
            int n = read();
            ls->remove(n);
        } else if (o == 'G') {
            int n = read();
            ls->query(n);
            putchar('\n');
        }
        // ls->output();
    }


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}