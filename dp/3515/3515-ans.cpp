

#include<bits/stdc++.h>
#define N 500010

using namespace std;

int n,head,tail,a[N];int dp[N],sqr[N];
struct node{
	int l,r,p;
}q[N];

int w(int j,int i) {
	return a[j]-a[i]+ceil(sqr[i-j]);
}

int binary_search(int t,int x) {
	int ans=q[t].r+1,l=q[t].l,r=q[t].r;
	while(l<=r) {
		int mid=l+r>>1;
		if(w(q[t].p,mid)<=w(x,mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}

void insert(int i) {
	q[tail].l=max(q[tail].l,i);
	while(head<=tail&&w(i,q[tail].l)>=w(q[tail].p,q[tail].l)) tail--;
	if(head>tail) {
		q[++tail].l=i;
		q[tail].r=n;
		q[tail].p=i;
	}
	else {
		int pos=binary_search(tail,i);
		if(pos>n) return ;
		q[tail].r=pos-1;
		q[++tail].l=pos;
		q[tail].r=n;
		q[tail].p=i;
	}
}

void work() {
	head=1,tail=0;
	for(int i=1;i<=n;i++) {
		insert(i);
		if(head<=tail&&q[head].r<i) head++;
		else q[head].l=i;
		dp[i]=max(dp[i],w(q[head].p,i));
        printf("i=%d, j=%d\n", i, q[head].p);
	}
}

int main() {
#ifdef D
    freopen("3515.in", "r", stdin);
    double TIMEA = clock();
#endif
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sqr[i]=sqrt(i);
	}
	
	work();
	for(int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]),swap(dp[i],dp[n-i+1]);
	work();
	
	for(int i=n;i>=1;i--) cout<<dp[i]<<endl;
	
	return 0;
}
