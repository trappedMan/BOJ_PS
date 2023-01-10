#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool v[3001][3001];
pair<int,pair<int,int>> st[300001];
queue<pair<int, pair<int, int>>> q;
inline bool valid(int y,int x) { return 1 <= x && x <= m && 1 <= y && y <= n; }
void bfs(int y, int x, int p) {
	if (v[y][x]) return;
	v[y][x] = true;
	if (p == 0) return;
	if (valid(y + 1, x) && !v[y + 1][x]) q.push({ p - 1,{y + 1,x} });
	if (valid(y - 1, x) && !v[y - 1][x]) q.push({ p - 1,{y - 1,x} });
	if (valid(y, x + 1) && !v[y][x + 1]) q.push({ p - 1,{y,x + 1} });
	if (valid(y, x - 1) && !v[y][x - 1]) q.push({ p - 1,{y,x - 1} });
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) { 
		cin >> st[i].second.first >> st[i].second.second >> st[i].first;
	}
	sort(st, st + k, greater<>());
	int x = 0;
	for (int pw = 3000; pw >= 0; pw--) {	//최대 세기 3000부터 내려가면서 해당 세기의 station이 있으면 큐에 푸쉬.
		while (x < k && st[x].first == pw) {
			q.push({ st[x].first,{st[x].second.first,st[x].second.second} });
			x++;
		}
		while (!q.empty() && q.front().first == pw) {
			auto cur = q.front();
			q.pop();
			bfs(cur.second.first, cur.second.second, cur.first);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (v[i][j])
				ans++;
	cout << ans;
}
