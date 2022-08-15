#include <bits/stdc++.h>
using namespace std;
int n, m, ice[301][301], sur[301][301],year;
bool v[301][301];
inline bool valid(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }
void count() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			int tmp = 0;
			if (valid(y + 1, x) && !ice[y + 1][x])
				tmp++;
			if (valid(y, x + 1) && !ice[y][x + 1])
				tmp++;
			if (valid(y - 1, x) && !ice[y - 1][x])
				tmp++;
			if (valid(y, x - 1) && !ice[y][x - 1])
				tmp++;
			sur[y][x] = tmp;
		}
	}
}
bool dfs() {
	stack<pair<int,int>> s;
	int flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (flag && ice[i][j]&&!v[i][j]) {
				return false;
			}
			if (!flag&&ice[i][j]) {
				flag = true;
				s.push({ i,j });
				while (!s.empty()) {
					auto now = s.top();
					int a = now.first, b = now.second;
					s.pop();
					if (v[a][b])
						continue;
					v[a][b] = true;
					if (valid(a + 1, b) && !v[a+1][b]&&ice[a + 1][b])
						s.push({ a + 1,b });
					if (valid(a, b+1) && !v[a][b+1] && ice[a][b + 1])
						s.push({ a,b+1 });
					if (valid(a - 1, b) && !v[a - 1][b] && ice[a - 1][b])
						s.push({ a-1,b});
					if (valid(a, b - 1) && !v[a][b - 1] && ice[a][b - 1])
						s.push({a ,b -1});
				}
			}
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ice[i][j];
	while (1) {
		if (!dfs())
			break;
		else {
			year++;
			count();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (ice[i][j]) {
						ice[i][j] = ice[i][j] - sur[i][j] >= 0 ? ice[i][j] - sur[i][j] : 0;
					}
				}
			}
			int flag = false;
			for (int i = 0; i < n; i++) 
				for (int j = 0; j < m; j++) 
					if (ice[i][j]) 
						flag = true;
			if (!flag) {
				cout << 0;
				return 0;
			}
			memset(v, 0, 301 * 301);
		}
	}
	cout << year;
	return 0;
}