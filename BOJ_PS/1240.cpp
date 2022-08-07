#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, ans;
vector<vector<pair<int, int>>> g;
bool v[1001];
int dist[1001];
priority_queue<pair<int,int>> q;
void func(int x, int y) {
	q.push({ 0,x });
	dist[x] = 0;
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		if (dist[cur.second]<cur.first)
			continue;
		for (const auto& s:g[cur.second]) {
			if (dist[s.first] > dist[cur.second] + s.second) {
				dist[s.first] = dist[cur.second] + s.second;
				q.push({ dist[s.first],s.first });
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		for (int i = 0; i < 1001; i++)
			dist[i] = 1e9;
		memset(v, 0, 1001);
		func(a, b);
		cout << dist[b] << '\n';
	}
	return 0;
}
