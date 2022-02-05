//dfs,bfs,vector<vector>,stack,queue 복합사용. vector에 더미 노드 박아놓지 않더라도 reserve,resize 써두면 됨
//vector의 정렬까지 잘 기억해두자
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;
bool* isvisited;
stack<int> dfsst;
queue<int> bfsqu;
vector<int>::iterator iter;

void dfs(vector<vector<int>> adj,int start) {
	int now;
	dfsst.push(start);
	while (!dfsst.empty()) {
		now = dfsst.top();
		dfsst.pop();
		if (!isvisited[now]) {
			isvisited[now] = true;
			cout << now << " ";
			for (iter = adj[now].begin(); iter != adj[now].end(); iter++) {
				if (!isvisited[*iter]) {
					dfsst.push(*iter);
				}
			}
		}
	}
	cout << '\n';
}
void bfs(vector<vector<int>> adj,int start) {
	int now;
	bfsqu.push(start);
	while (!bfsqu.empty()) {
		now = bfsqu.front();
		bfsqu.pop();
		if (!isvisited[now]) {
			isvisited[now] = true;
			cout << now << " ";
			for (iter = adj[now].begin(); iter != adj[now].end(); iter++) {
				if (!isvisited[*iter]) {
					bfsqu.push(*iter);
				}
			}
		}
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int V, E, start;
	int src, dest;
	vector<vector<int>> adj;
	cin >> V >> E >> start;
	isvisited = new bool[V + 1];
	adj.reserve(V + 1);
	adj.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> src >> dest;
		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}

	for (int i = 1; i <= V; i++) {
		sort(adj[i].begin(), adj[i].end(),greater<int>());
	}
	memset(isvisited, false, V + 1);
	dfs(adj,start);
	for (int i = 1; i <= V; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	memset(isvisited, false, V + 1);
	bfs(adj,start);
	delete[] isvisited;
	return 0;
}