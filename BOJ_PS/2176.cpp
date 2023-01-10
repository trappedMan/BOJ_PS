#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, d[1001], dp[1001];
vector<vector<pair<int, int>>> g;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = 1000000000;
	}
	d[2] = 0;
	dp[2] = 1;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
	}
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0,2 });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int w = cur.first, dest = cur.second;
		if (d[dest] < w)
			continue;
		for (const auto& it : g[dest]) {
			if (d[it.first] > d[dest] + it.second) {
				d[it.first] = d[dest] + it.second;
				pq.push({ d[it.first],it.first });
			}
			if (d[dest] < d[it.first]) {
				dp[it.first] += dp[dest];
			}
		}
	}
	cout << dp[1];
	return 0;
}
