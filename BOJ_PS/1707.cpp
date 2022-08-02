#include <iostream>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;
vector<vector<int>> adj;
int mark[20001];
bool visit[20001];
stack<int> st;
int t;
int com, conn, sum = 0;
int dfs() {
	for (int i = 1; i <= com; i++) {
		if (!visit[i]) {
			st.push(i);
			mark[i] = 0;
		}
		while (!st.empty()) {
			int now = st.top();
			st.pop();
			if (!visit[now]) {
				visit[now] = true;
				for (const auto& s : adj[now]) {
					st.push(s);
					if (mark[s] != -1 && mark[s] != 1 - mark[now])
						return 0;
					if (mark[s] == -1)
						mark[s] = 1 - mark[now];
				}
			}
		}
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> com >> conn;
		int a, b;
		adj.clear();
		adj.resize(com + 1);
		memset(mark, -1, sizeof(int) * (com + 1));
		memset(visit, 0, com + 1);
		for (int i = 0; i < conn; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ans=dfs();
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}