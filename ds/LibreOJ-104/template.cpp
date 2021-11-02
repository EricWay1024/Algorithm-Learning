#include<bits/stdc++.h>
#define b out(root),cout << endl;
using namespace std;
const int N=100000+5;
const int inf=2147483647;

int n;
int tot = 0;
int root = 0;

struct splay{
    int ch[2], size, cnt, val, fa;
}a[N];

int gi(){
    int ans = 0 , f = 1; char i = getchar();
    while(i<'0'||i>'9'){if(i=='-')f=-1;i=getchar();}
    while(i>='0'&&i<='9'){ans=ans*10+i-'0';i=getchar();}
    return ans * f;
}

void out(int x){
    if(a[x].ch[0]) out(a[x].ch[0]);
    printf("%d ",a[x].val);
    if(a[x].ch[1]) out(a[x].ch[1]);
}

int get(int x){
    return a[a[x].fa].ch[1] == x;
}

void update(int x){
    a[x].size=a[a[x].ch[0]].size+a[a[x].ch[1]].size+a[x].cnt;
}

void rotate(int x){
    int fa = a[x].fa , gfa = a[fa].fa;
    int d1 = get(x) , d2 = get(fa);
    a[fa].ch[d1]=a[x].ch[d1^1] , a[a[x].ch[d1^1]].fa=fa;
    a[gfa].ch[d2]=x , a[x].fa=gfa;
    a[fa].fa=x , a[x].ch[d1^1]=fa;
    update(fa); update(x);
}

void splay(int x,int goal){
    while(a[x].fa != goal){
	    int fa = a[x].fa, gfa = a[fa].fa;
	    int d1 = get(x), d2 = get(fa);
	    if(gfa != goal){
	        if(d1 == d2) rotate(fa);
	        else rotate(x);
	    }
	    rotate(x);
    }
    if(goal == 0) root = x;
}

int find(int val){
    int x = root;
    while(a[x].val != val && a[x].ch[a[x].val<val])
	    x = a[x].ch[a[x].val<val];
    return x;
}

void insert(int val){
    int x = root, fa = 0;
    while(a[x].val != val && x)
	    fa = x, x = a[x].ch[a[x].val<val];
    if(x) a[x].cnt++;
    else{
	    x = ++tot;
	    if(fa) a[fa].ch[a[fa].val<val] = x;
	    a[x].size = a[x].cnt = 1;
	    a[x].fa = fa; a[x].val = val;
    }
    splay(x , 0);
}

int getPreNext(int val,int type){
    splay(find(val) , 0); int x = root;
    if(a[x].val < val && type == 0) return x;
    if(a[x].val > val && type == 1) return x;
    x = a[x].ch[type];
    while(a[x].ch[type^1])
	    x = a[x].ch[type^1];
    return x;
}

void Remove(int val){
    int last = getPreNext(val,0), next = getPreNext(val,1);
    splay(last , 0); splay(next , last);
    if(a[a[next].ch[0]].cnt > 1){
	    a[a[next].ch[0]].cnt--;
	    splay(a[next].ch[0] , 0);
    }
    else a[next].ch[0] = 0;
}

int getValByRank(int k){
    int x = root;
    if(a[x].size < k) return inf;
    while(1){
	    int son = a[x].ch[0];
	    if(k <= a[son].size) x = son;
	    else if(k > a[son].size+a[x].cnt){
	       k -= a[son].size+a[x].cnt;
	        x = a[x].ch[1];
		}
	    else return a[x].val;
    }
}

int getRankByVal(int val){
    splay(find(val) , 0);
    return a[a[root].ch[0]].size;
}

int main(){
    insert(-inf); insert(inf);
    int flag, x; n = gi();
    for(int i=1;i<=n;i++){
	    flag = gi(); x = gi();
	    if(flag == 1) insert(x);
	    if(flag == 2) Remove(x);
	    if(flag == 3) printf("%d\n",getRankByVal(x));
	    if(flag == 4) printf("%d\n",getValByRank(x+1));
	    if(flag == 5) printf("%d\n",a[getPreNext(x,0)].val);
	    if(flag == 6) printf("%d\n",a[getPreNext(x,1)].val);
    }
    return 0;
}