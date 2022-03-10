/*#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> graph;
int* depth;
int** parent;
int n, m, K;
void dfs(int root) {
	for (int next : graph[root]) {
		if (depth[next] == -1) {
			parent[next][0] = root;
			depth[next] = depth[root] + 1;
			dfs(next);
		}
	}
}
void complete_parent() {
	for (int k = 1; k < K; k++) {
		for (int cur = 1; cur <= n; cur++) {
			if (parent[cur][k - 1] == -1)
				continue;
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
		}
	}
}
int lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	int diff = depth[u] - depth[v];
	for (int i = 0; diff != 0; i++) {
		if (diff & 1)
			u = parent[u][i];
		diff >>= 1;
	}

	if (u != v) {
		for (int i = K - 1; i >= 0; i--) {
			if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	return u;
}
int main()
{
	FAST;
	int tmp1, tmp2;
	cin >> n;
	K = ceil(log2(n));
	depth = new int[n + 1];
	parent = new int* [n + 1];
	for (int i = 0; i <= n; i++)
		*(parent + i) = new int[K];
	for (int i = 0; i <= n; i++)
		depth[i] = -1;
	depth[1] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < K; j++) {
			parent[i][j] = -1;
		}
	}
	graph.assign(n + 1, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}
	dfs(1);
	complete_parent();
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		cout << lca(tmp1, tmp2) << '\n';
	}
	delete[] depth;
	for (int i = 0; i <= n; i++)
		delete[] * (parent + i);
	delete[] parent;
	return 0;
}*/