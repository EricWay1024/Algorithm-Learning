#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<vector>
#include<stack>
#include<string>
#define N 600
using namespace std; 


struct poly{
    long long p[N+2];
    
    void clear(){
        memset(p, 0, sizeof(p));
    }
    
    poly operator= (const poly &b){
        this->clear();
        for (int i=0; i<=N; i++) p[i]=b.p[i];
        return *this;
    }
    
    poly operator= (const int b){
        this->clear();
        p[0]=b;
        return *this;
    }
    
    poly operator+ (const poly &b) const{
        poly c;
        for (int i=0; i<=N; i++){
            c.p[i]=p[i]+b.p[i];
        }
        return c;
    }
    
    poly operator- (const poly &b) const{
        poly c;
        for (int i=0; i<=N; i++){
            c.p[i]=p[i]-b.p[i];
        }
        return c;
    }
    
    poly operator* (const poly &b) const {
        poly c;
        c.clear();
        for (int i=0; i<=N; i++){
            for (int j=0; j<=N; j++){
                if (i+j>N) continue;
                int k=i+j;
                c.p[k]+=p[i]*b.p[j];
            }
        }
        return c;
    }
    
    poly pow(const poly &b) const {
        //b must be an integer.
        int t=b.p[0];
        
        poly ans; ans=1;
        poly pas; pas=(*this);
        
        while (t){
            if (t&1) {ans=ans*pas;}
            pas=pas*pas;
            t>>=1;
        }
        return ans;
    }
    
    void print(){
        for (int i=N; i>=0; i--){
            if (p[i]==0) continue;
            if (i!=N) cout<<'+';
            cout<<p[i]<<"a^"<<i;
        }
        cout<<endl;
    }
            
    
    bool operator== (const poly&b) const {
        for (int i=0; i<=N; i++){
            if (p[i]!=b.p[i]) return false;
        }
        return true;
    }
    
};

stack<poly> s1;
stack<char> s2;

inline int f(char c){
    if (c=='^') return 3;
    if (c=='*' ) return 2;
    if (c=='+' || c=='-') return 1;
    else return 0;
}

inline void js(){
    poly a, b; char c;
    poly ans;
    b=s1.top(); s1.pop();
    a=s1.top(); s1.pop();
    c=s2.top(); s2.pop();
    if (c=='+') ans=a+b;
    if (c=='-') ans=a-b;
    if (c=='*') ans=a*b;
    if (c=='^') ans=a.pow(b);
    s1.push(ans);
}

const char L[18]="0123456789+-*^a()";

inline bool legal(char c){
    for (int i=0; i<17; i++){
        if (c==L[i]) return true; 
    }
    return false;
}
        
inline poly read(){
    string s;
    getline(cin, s);
    
    int len=s.size();
    
    int judge=0; bool ok=1;
    if (s.empty()) ok=0;
    for (int i=0; i<len; i++){
        if (s[i]=='(') judge++;
        if (s[i]==')') judge--;
        if (judge<0) ok=0;
    }
    if (judge>0) ok=0;
    if (!ok) {poly wrong; wrong.clear(); wrong.p[N+1]=1; return wrong;}
    
    //gets(s);
    bool flag=0; int temp=0; poly pt;
    poly a; a.clear(); a.p[1]=1;
    for (int i=0; i<len; i++){
        char &n=s[i];
        if (!legal(n)) continue;
        if (n=='a') {s1.push(a); continue;}
        if (n>='0' && n<='9') {temp=(temp<<1)+(temp<<3)+n-'0'; flag=1; continue;}
        
        if (flag) {pt=temp; s1.push(pt); temp=0; flag=0;}
        if (n=='(') {s2.push(n); continue;}
        if (n==')') {
            while (s2.top()!='(') js();
            s2.pop();
            continue;
        }
        while (!s2.empty() && f(s2.top())>=f(n)) js();
        s2.push(n);
    }
    
    if (flag) {pt=temp; s1.push(pt);}
    while (!s2.empty()) js();
    poly res=s1.top();
    s1.pop();
    return res;
    //s1.top().print();
}



int main(){
    
    poly aim; aim=read();
    //aim.print();
    int n; scanf("%d\n", &n);  
    for (int i=0; i<n; i++){
        poly now=read();
        //now.print();
        if (now==aim) {char c='A'+i; cout<<c;}
    }
    cout<<endl;	
    return 0;
}