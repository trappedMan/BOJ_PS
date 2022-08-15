#include <bits/stdc++.h>
using namespace std;
int n,m, a[1001][1001], maxv;
int v[1001][1001];
queue < tuple <int, int, int >> q;
inline bool valid(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }
void bfs() {
	while (!q.empty()) {
		auto pp = q.front();
		q.pop();
		int f = get<0>(pp), s = get<1>(pp), t = get<2>(pp);
		if (valid(f + 1, s) && v[f + 1][s] > t + 1 && !a[f + 1][s]) {
			v[f + 1][s] = t + 1;
			q.push({ f + 1,s ,t + 1 });
		}
		if (valid(f - 1, s) && v[f - 1][s] > t + 1 && !a[f - 1][s]) {
			v[f - 1][s] = t + 1;
			q.push({ f - 1,s ,t + 1 });
		}
		if (valid(f, s + 1) && v[f][s + 1] > t + 1 && !a[f][s + 1]) {
			v[f][s + 1] = t + 1;
			q.push({ f,s + 1,t + 1 });
		}
		if (valid(f, s - 1) && v[f][s - 1] > t + 1 && !a[f][s - 1]) {
			v[f][s - 1] = t + 1;
			q.push({ f,s - 1,t + 1 });
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> m >> n;
	int flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0 )
				flag = true;
			v[i][j] = 10000000;
		}
	}
	if (!flag) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 1)
				q.push({ i,j,0 });
	bfs();

	flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 10000000 && !a[i][j])
				flag = true;
			if(v[i][j]!=10000000)
				maxv = max(maxv, v[i][j]);
		}
	}
	if (flag)
		cout << -1;
	else
		cout << maxv;
	return 0;
}
