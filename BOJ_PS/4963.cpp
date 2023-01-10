#include <bits/stdc++.h>
using namespace std;
int w, h, grid[50][50];
bool v[50][50];
queue<pair<int, int>> q;
stack<pair<int, int>> s;
inline bool valid(int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; }
int dfs() {
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!v[i][j] && grid[i][j] == 1) {
				cnt++;
				s.push({ i,j });
				while (!s.empty()) {
					int ff = s.top().first, ss = s.top().second;
					s.pop();
					if (v[ff][ss]) continue;
					v[ff][ss] = true;
					vector<pair<int, int>> arr(8);
					arr = { {ff,ss + 1},{ff + 1,ss + 1},{ff + 1,ss},{ff + 1,ss - 1},{ff,ss - 1},
	{ff - 1,ss - 1},{ff - 1,ss},{ff - 1,ss + 1} };
					for (int x = 0; x < 8; x++) {
						int a = arr[x].first, b = arr[x].second;
						if (valid(a, b) && !v[a][b] && grid[a][b] == 1) {
							s.push({ a,b });
						}
					}
				}
			}
		}
	}
	return cnt;
}
int bfs() {
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!v[i][j] && grid[i][j] == 1) {
				cnt++;
				q.push({ i,j });
				while (!q.empty()) {
					int ff = q.front().first, ss = q.front().second;
					q.pop();
					if (v[ff][ss]) continue;
					v[ff][ss] = true;
					vector<pair<int, int>> arr(8);
					arr = { {ff,ss + 1},{ff + 1,ss + 1},{ff + 1,ss},{ff + 1,ss - 1},{ff,ss - 1},
	{ff - 1,ss - 1},{ff - 1,ss},{ff - 1,ss + 1} };
					for (int x = 0; x < 8; x++) {
						int a = arr[x].first, b = arr[x].second;
						if (valid(a, b) && !v[a][b] && grid[a][b] == 1) {
							q.push({ a,b });
						}
					}
				}
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (1) {
		memset(v, 0, 2500);
		cin >> w >> h;
		if (!w && !h) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> grid[i][j];
			}
		}
		//cout << bfs() << '\n';
		cout << dfs() << '\n';
	}
	return 0;
}
