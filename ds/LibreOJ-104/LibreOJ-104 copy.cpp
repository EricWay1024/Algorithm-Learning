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

struct Node {
    int key;
    Node* left; 
    Node* right;
    Node* p;

    Node(int _k = 0) { left = right = p = NULL; key = _k; }
};

struct Tree {
    Node* root;

    Tree() { root = NULL; }
};

void inorder_tree_walk(Node* x) {
    if (x != NULL) {
        inorder_tree_walk(x->left);
        printf("%d\n", x->key);
        inorder_tree_walk(x->right);
    }
}

Node* tree_search(Node* x, int k) {
    if (x == NULL || k == x->key) return x;
    if (k < x->key) return tree_search(x->left, k);
    else return tree_search(x->right, k);
}

Node* tree_minimum(Node* x) {
    while (x->left != NULL) x = x->left;
    return x; 
}

Node* tree_maximum(Node* x) {
    while (x->right != NULL) x = x->right;
    return x;
}

Node* tree_successor(Node* x) {
    if (x->right != NULL) return tree_minimum(x->right);
    Node* y = x->p;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}

Node* tree_predecessor(Node* x) {
    if (x->left != NULL) return tree_maximum(x->left);
    Node* y = x->p;
    while (y != NULL && x == y->left) {
        x = y; 
        y = y->p;
    }
    return y;
}

void tree_insert(Tree* T, Node* z) {
    Node* y = NULL;
    for (Node* x = T->root; x != NULL; x = (z->key < x->key ? x->left : x->right)) y = x; 
    z->p = y;
    if (y == NULL) T->root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}

void transplant(Tree* T, Node* u, Node* v) {
    if (u->p == NULL) T->root = v;
    else if (u == u->p->left) u->p->left = v;
    else u->p->right = v;
    if (v != NULL) v->p = u->p;
}

void tree_delete(Tree* T, Node* z) {
    if (z->left == NULL) transplant(T, z, z->right);
    else if (z->right == NULL) transplant(T, z, z->left);
    else {
        Node* y = tree_minimum(z->right);
        if (y->p != z) {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
    }
    delete z;
}
int main() {
#ifdef D
    freopen("LibreOJ-104.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
    auto T = new Tree();
    tree_insert(T, new Node(12));
    tree_insert(T, new Node(13));
    tree_insert(T, new Node(16));
    tree_insert(T, new Node(1));
    Node* x = tree_minimum(T->root);
    cout << x->key << endl;


#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}