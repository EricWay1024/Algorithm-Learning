#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}
const int maxn =  200;
int trie[maxn][26]; //字典树
int cntword[maxn];  //记录该单词出现次数
int fail[maxn];     //失败时的回溯指针
int tot = 0;//结点个数
bool tag[maxn];
ll L;
int n;
struct Mat {
	ull m[101][101];
    void output(int si) {
        for(int i=0; i<si; i++) {
            for(int j=0; j<si; j++) {
                cout << m[i][j] << ' ';
            }
            cout << endl;
        }
    }
};
Mat mul(Mat x,Mat y,int si) {
	Mat c;
	for(int i=0; i<si; i++) {
		for(int j=0; j<si; j++) {
			c.m[i][j] = 0;
		}
	}
	for(int i=0; i<si; i++) {
		for(int j=0; j<si; j++) {
			for(int k=0; k<si; k++) {
				c.m[i][j] = (c.m[i][j]+ x.m[i][k]*y.m[k][j]);
			}
		}
	}
	return c;
}
Mat poww(Mat x,ll y,int si) { //求矩阵x的y次幂
	Mat as;
	for(int i=0; i<si; i++)
		for(int j=0; j<si; j++)
			if(i==j)as.m[i][i] = 1;
			else as.m[i][j] = 0;//防止多次输入，清零

	while(y) {
		if(y&1)as = mul(as,x,si);
		x = mul(x,x,si);
		y>>=1;
	}
	return as;//返回ans
}
void insertWords(char s[],int len) {
	int root = 0;
	for(int i=0; i<len; i++) {
		int next = s[i] - 'a';
		if(!trie[root][next])
			trie[root][next] = tot++;
		root = trie[root][next];
	}
	tag[root]=true;      //当前结点单词数+1
}
void getFail() {
	queue <int>q;
	for(int i=0; i<26; i++) {   //将第二层所有出现了的字母扔进队列
		if(trie[0][i]) {
			fail[trie[0][i]] = 0;
			q.push(trie[0][i]);
		}
	}
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(tag[fail[now]])tag[now] = true;
		for(int i=0; i<26; i++) {
			if(trie[now][i]) {
				fail[trie[now][i]] = trie[fail[now]][i];
				q.push(trie[now][i]);
			} else trie[now][i] = trie[fail[now]][i];
		}
	}
}

void query() {
	ull ans = 0;
	Mat c,d;
	for(int i=0; i<tot+1; i++) {
		for(int j=0; j<tot+1; j++) {
			c.m[i][j] = 0;
			d.m[i][j] = 0;
		}
	}
	for(int i=0; i<tot; i++) {
			if(tag[i])continue;
		for(int j=0; j<26; j++) {
			if(!tag[trie[i][j]])c.m[i][trie[i][j]]++;
		}
	}
	for(int i=0; i<=tot; i++)c.m[i][tot] = 1;

	tot++;
	c = poww(c,(ll)(L),tot);
	d.m[0][0] = 1;
	d.m[0][1] = 26;
	d.m[1][0] = 0;
	d.m[1][1] = 26;
	d = poww(d,(ll)L,2);
	for(int i=0; i<tot; i++)ans+=c.m[0][i];
    logs(ans)
	ull res1 = d.m[0][1];
    logs(res1)
	ans = res1 - ans +1;
	cout<<ans<<endl;
}
int main() {
#ifdef D
    freopen("HDU-2243.in", "r", stdin);
    clock_t TIMEA = clock();
#endif
	char s[1000005];
	while(scanf("%d %lld",&n,&L)==2) {
		memset(fail,0,sizeof(fail));
		memset(trie,0,sizeof(trie));
		memset(tag,false,sizeof(tag));
		tot = 1;
		for(int i=0; i<n; i++) {
			scanf("%s",s) ;//输入单词
			insertWords(s,strlen(s));
		}
		fail[0] = 0;
		getFail();
		query();
	}

	return 0;
}
/*
4
ash shex bcd sha
ashex

*/