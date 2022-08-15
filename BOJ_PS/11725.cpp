#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int n, a, b;
bool v[100001];
int parent[100001];
void dfs() {
	stack<int> s;
	s.push(1);
	while (!s.empty()) {
		auto now = s.top();
		s.pop();
		if (v[now])
			continue;
		v[now] = true;
		for (auto k : g[now]) {
			if (!v[k]) {
				parent[k] = now;
				s.push(k);
			}
		}	
	}
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	g.resize(n+1);
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs();
	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
	return 0;
}
