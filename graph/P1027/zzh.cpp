#include<bits/stdc++.h>
using namespace std;
struct z{
	double x, y;
}s[110][4];
struct Edge{
	int to;
	double va;
};
struct Node {
	int p;
	double dis;
};
bool operator <(Node a, Node b) {
	return a.dis > b.dis;
}
int k, S, t, a, b;
double d[110];
double dis[410];
vector<Edge> e[410];
priority_queue<Node> q;
double dist(int i, int j){
	z a, b;
	a.x = s[i / 4][i % 4].x;
	a.y = s[i / 4][i % 4].y;
	b.x = s[j / 4][j % 4].x;
	b.y = s[j / 4][j % 4].y;
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
z f(z a, z b, z c){
	double dab = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	double dac = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
	double dbc = sqrt((c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y));
	double mx = max(max(dab, dac), dbc);
	z d, e;
	if(dac == mx){
		e.x = a.x + c.x;
		e.y = a.y + c.y;
		d.x = e.x - b.x;
		d.y = e.y - b.y;
	}else if(dab == mx){
		e.x = a.x + b.x;
		e.y = a.y + b.y;
		d.x = e.x - c.x;
		d.y = e.y - c.y;
	}else{
		e.x = c.x + b.x;
		e.y = c.y + b.y;
		d.x = e.x - a.x;
		d.y = e.y - a.y;
	}
	return d;
}
void dij(int s){
    for (int i = 0; i < 410; i++) dis[i] = 1e9;
	q.push((Node){s, 0});
	dis[s] = 0;
	while(!q.empty()) {
		Node st = q.top();
		q.pop();
		if(st.dis > dis[st.p]) continue;
		for(int i = 0; i < e[st.p].size(); i++) {
			double new_dis = st.dis + e[st.p][i].va;
			if(new_dis < dis[e[st.p][i].to]) {
				dis[e[st.p][i].to] = new_dis;
				q.push((Node){e[st.p][i].to, new_dis});
			}
		}
	}
}
int main(){
	int k;
	cin >> k;
	while(k--){
		cin >> S >> t >> a >> b;
		for(int i = 0;i < S;i++){
			cin >> s[i][1].x >> s[i][1].y >> s[i][2].x >> s[i][2].y >> s[i][3].x >> s[i][3].y >> d[i];
			s[i][4] = f(s[i][1], s[i][2], s[i][3]);
		}
		for(int i = 1;i <= 4 * S;i++){
			for(int j = 1;j <= 4 * S;j++){
                if (i == j) continue;
				if((i - 1) / 4 == (j - 1) / 4){
					e[i].push_back(Edge{j, d[(i - 1) / 4] * dist(i, j)});
				}else{
					e[i].push_back(Edge{j, t * dist(i, j)});
				}
			}
		}
		double ans = 1e9;
		int x, y;
		for(int i = 1;i <= 4;i++){
			x = 4 * (a - 1) + i;
            dij(x);
			for(int j = 1;j <= 4;j++){
				y = 4 * (b - 1) + j;
				if(dis[y] < ans){
					ans = dis[y];
				}
			}
		}
		cout << fixed << setprecision(1) << ans << endl;
	}
	return 0;
}