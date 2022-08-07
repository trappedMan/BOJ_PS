#include <bits/stdc++.h>
using namespace std;
int n, m, tmp1, tmp2,tmax,mins,mini, ances[101], p[101], d[101][101], dcpy[101][101];
vector<int> root, now, ans;
int set_find(int k) {
	while (p[k] > 0) {
		k = p[k];
	}
	return k;
}
void set_union(int a, int b) {
	int x = set_find(a);
	int y = set_find(b);
	if (x == y)
		return;
	else if (p[x] > p[y]) {
		p[y] += p[x];
		p[x] = y;
	}
	else {
		p[x] += p[y];
		p[y] = x;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	memset(p, -1, 101 * sizeof(int));
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i != j)
				d[i][j] = 1000;
			else
				d[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> tmp1 >> tmp2;
		d[tmp1][tmp2] = 1;
		d[tmp2][tmp1] = 1;
		set_union(tmp1, tmp2);
	}
	for (int m = 1; m <= n; m++)
		for (int s = 1; s <= n; s++)
			for (int e = 1; e <= n; e++)
				if (d[s][e] > d[s][m] + d[m][e])
					d[s][e] = d[s][m] + d[m][e];
	for (int i = 1; i <= n; i++) {
		ances[i] = set_find(i);
		if (ances[i] == i)
			root.push_back(i);
	}
	cout << root.size() << '\n';
	for (auto q : root) {
		now.clear();
		for (int i = 1; i <= n; i++) {
			if (ances[i] == q) {
				now.push_back(i);
			}
		}
		for (int i = 0; i < now.size(); i++) {
			for (int j = 0; j < now.size(); j++) {
				dcpy[i][j] = d[now[i]][now[j]];
			}
		}
		tmax = 0;
		for (int i = 0; i < now.size(); i++)
			tmax = max(tmax, dcpy[0][i]);
		mins = tmax;
		mini = 0;
		for (int i = 1; i < now.size(); i++) {
			tmax = 0;
			for (int j = 0; j < now.size(); j++) {
				tmax = max(tmax, dcpy[i][j]);
			}
			if (mins > tmax) {
				mins = tmax;
				mini = i;
			}
		}
		ans.push_back(now[mini]);
	}
	sort(ans.begin(), ans.end());
	for (auto k : ans)
		cout << k << '\n';
	return 0;
}