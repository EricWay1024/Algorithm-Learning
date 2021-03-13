ll MOD;
struct mll {
    ll s;
    mll (ll s=0):s(s) { r(); };
    void r() { s %= MOD; }
    void fr() { r(); s += MOD; r(); }
    mll operator+ (const mll &b) const { return s+b.s; }
    mll operator- (const mll &b) const { return s-b.s; }
    mll operator* (const mll &b) const { return s*b.s; }
    void operator+= (const mll &b) { s += b.s; r(); }
    void operator-= (const mll &b) { s -= b.s; r(); }
    void operator*= (const mll &b) { s *= b.s; r(); }
    operator ll() const { return s; }
    friend ostream& operator<< (ostream &out, mll &m) {
        m.fr(); out << m.s; return out;
    }
};

struct Matrix {
    mll s[5][5];
    int n;
    mll& operator() (int x, int y) {
        return s[x][y];
    }
    mll* operator[] (int x) {
        return s[x];
    }
    Matrix(int n, int i=0):n(n) {
        mmst(s, 0);
        if(i) For(j,n) s[j][j]=i;
    }

    Matrix operator* (const Matrix &b) const {
        Matrix c = Matrix(n);
        For(i,n){
            For(k,n){
                mll t=s[i][k];
                For(j,n){
                    c.s[i][j] += t * b.s[k][j];
                }
            }
        }
        return c;
    }

    Matrix operator+ (const Matrix &b) const {
        Matrix c = Matrix(n);
        For(i,n){
            For(j,n){
                c[i][j] = s[i][j] + b.s[i][j];
            }
        }
        return c;
    }

    Matrix operator- (const Matrix &b) const {
        Matrix c = Matrix(n);
        For(i,n){
            For(j,n){
                c[i][j] = s[i][j] - b.s[i][j];
            }
        }
        return c;
    }

    Matrix quick_pow(ll b) {
        Matrix c = Matrix(n, 1);
        Matrix a = (*this);
        for(; b; b>>=1) {
            if (b & 1) c = c * a;
            a = a * a;
        }
        return c;
    }

    void initA() {
    }

    void initB() {
    }

    void output() {
        For(i,n){
            For(j,n){
                cout << s[i][j] << " ";
            }
            cout << endl;
        }
    }
};
