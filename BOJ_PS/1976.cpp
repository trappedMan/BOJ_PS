#include <bits/stdc++.h>
using namespace std;
int n, m, tmp, root, p[201];
int set_find(int k) {
	while (p[k] > 0) {
		k = p[k];
	}
	return k;
}
void set_union(int a,int b) {
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
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	memset(p, -1, 201 * sizeof(int));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			if (tmp == 1) {
				set_union(i, j);
			}
		}
	}
	cin >> tmp;
	root = set_find(tmp);
	for (int i = 2; i <= m; i++) {
		cin >> tmp;
		if (set_find(tmp) != root) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
