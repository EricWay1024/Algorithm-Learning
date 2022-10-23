using ll = long long;
const int N = 5e5 + 10;

// with lazy, interval update, interval query
namespace lazy {

struct seg {
    ll U(ll x, ll y) { return x + y; }
    static const ll a0 = 0;
    void toz(ll x) { z += x, state = 1; }
    void toa() { a += z * (r - l + 1), z = 0, state = 0; }
    ll a, z; bool state;
    int l, r; seg *lc, *rc; 
    void init(int _l, int _r, seg *&pl) {
        l = _l, r = _r; state = 0; z = 0;
        if (l == r) { a = a0; return; }
        int m = (l + r) >> 1;
        lc = ++pl; lc->init(l, m, pl);
        rc = ++pl; rc->init(m + 1, r, pl);
        up();
    }
    void build(ll in[]) {
        if (l == r) { a = in[l]; return; }
        lc->build(in); rc->build(in);
        up();
    } 
    void up() { a = U(lc->a, rc->a); }
    void down() {
        if (!state) return;
        if (l < r) { lc->toz(z); rc->toz(z); }
        toa();
    }
    void update(int x, int y, ll k) {
        if (x > r || y < l) { down(); return; }
        if (x <= l && y >= r) { toz(k); down(); return; }
        down();
        lc->update(x, y, k);
        rc->update(x, y, k);
        up();
    }
    ll query(int x, int y) {
        if (x > r || y < l) return a0;
        down();
        if (x <= l && y >= r) return a;
        return U(lc->query(x, y), rc->query(x, y));
    }
} tr[N * 2], *pl;
void init(int l, int r, ll in[] = nullptr) {
    pl = tr;
    tr->init(l, r, pl);
    if (in) tr->build(in);
}// 先输入in，然后init，然后用tr->update and tr->query

}

namespace nolazy {
// without lazy, point update, interval query
struct seg {
    ll U(ll x, ll y) { return x + y; }
    static const ll a0 = 0;
    ll a;
    int l, r; seg *lc, *rc; 
    void init(int _l, int _r, seg *&pl) {
        l = _l, r = _r;
        if (l == r) { a = a0; return; }
        int m = (l + r) >> 1;
        lc = ++pl; lc->init(l, m, pl);
        rc = ++pl; rc->init(m + 1, r, pl);
        up();
    }
    void build(ll in[]) {
        if (l == r) { a = in[l]; return; }
        lc->build(in); rc->build(in);
        up();
    } 
    void up() { a = U(lc->a, rc->a); }
    void update(int x, ll k) {
        if (x < l || x > r) { return; }
        if (x == l && x == r) { a += k; return;  }
        lc->update(x, k);
        rc->update(x, k);
        up();
    }
    ll query(int x, int y) {
        if (x > r || y < l) return a0;
        if (x <= l && y >= r) return a;
        return U(lc->query(x, y), rc->query(x, y));
    }
} tr[N * 2], *pl;
void init(int l, int r, ll in[] = nullptr) {
    pl = tr;
    tr->init(l, r, pl);
    if (in) tr->build(in);
}// 先输入in，然后init，然后用tr->update and tr->query

}

namespace nolazy2 {

// without lazy, point update, interval query
struct seg {
    ll U(ll x, ll y) { return x + y; }
    static const ll a0 = 0;
    ll a;
    int l, r; seg *lc, *rc; 
    void init(int _l, int _r, seg *&pl, ll in[]) {
        l = _l, r = _r;
        if (l == r) { a = in ? in[l] : a0; return; }
        int m = (l + r) >> 1;
        lc = ++pl; lc->init(l, m, pl, in);
        rc = ++pl; rc->init(m + 1, r, pl, in);
        up();
    }
    void up() { a = U(lc->a, rc->a); }
    void update(int x, ll k) {
        if (x < l || x > r) { return; }
        if (x == l && x == r) { a += k; return;  }
        lc->update(x, k);
        rc->update(x, k);
        up();
    }
    ll query(int x, int y) {
        if (x > r || y < l) return a0;
        if (x <= l && y >= r) return a;
        return U(lc->query(x, y), rc->query(x, y));
    }
} tr[N * 2], *pl;
void init(int l, int r, ll in[] = nullptr) {
    pl = tr;
    tr->init(l, r, pl, in);
}// 先输入in，然后init，然后用tr->update and tr->query
}