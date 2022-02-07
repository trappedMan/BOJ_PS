#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n, m, p;
typedef long long ll;
vector<vector<pair<int, ll>>> graph;
priority_queue <pair<ll,int>> q;
bool v[100001];
ll c[100001];
int main()
{
	FAST;
	int src, dest;
	ll weight, ans = 0;
	cin >> n >> m;
	graph.assign(n + 1, vector<pair<int,ll>>());
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	cin >> p;
	for (int i = 0; i < p; i++) {
		cin >> src >> dest >> weight;
		graph[src].push_back({ dest,weight });
		c[dest] += weight;
	}
	for (int i = 1; i <= n; i++)
		q.push({-c[i],i });
	while (!q.empty()&&m>0) {
		auto now = q.top();
		q.pop();
		if (v[now.second])
			continue;
		v[now.second] = true;
		m--;
		for (const auto& iter : graph[now.second]) {
			if (!v[iter.first]) {
				c[iter.first] -= iter.second;
				q.push({ -c[iter.first],iter.first });
			}
		}
		ans = max(ans,-now.first);
	}
	cout << ans;
	return 0;
}