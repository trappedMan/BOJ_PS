#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <string>
using namespace std;
int n, m;
int lab[8][8]; int tmp[8][8];
bool visit[8][8];
int maxval = 0;
pair<int, int> dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };

inline bool valid(int i, int j) { return i >= 0 && i < n&& j >= 0 && j < m;}

void bfs() {
	memset(visit, 0, 64);
	memcpy(tmp, lab, sizeof(int) * 8 * 8);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && tmp[i][j] == 2) {
				q.push(make_pair(i, j));
				visit[i][j] = true;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (const auto& d : dir) {
						int yy = y + d.first, xx = x + d.second;
						if (valid(yy, xx)) {
							if (tmp[yy][xx] == 0&&!visit[yy][xx]) {
								visit[yy][xx] = true;
								tmp[yy][xx] = 2;
								q.push(make_pair(yy, xx));
							}
						}
					}
				}
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0)
				temp++;
		}
	}
	maxval = maxval < temp ? temp : maxval;
}

void back(int cnt, int y, int x) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int j = x + 1; j < m; j++) {
		if (lab[y][j] == 0) {
			lab[y][j] = 1;
			back(cnt + 1, y, j);
			lab[y][j] = 0;
		}
	}
	for (int i = y + 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				back(cnt + 1, i, j);
				lab[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				back(1, i, j);
				lab[i][j] = 0;
			}
		}
	}
	cout << maxval;
	return 0;
}