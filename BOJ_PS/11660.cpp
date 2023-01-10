#include <bits/stdc++.h>
using namespace std;
int n, m, a[1025][1025], s[1025][1025];
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	int x1, y1, x2, y2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			s[i][j] = a[i][j]+s[i][j - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++) {
			cnt += s[j][y2] - s[j][y1-1];
		}
		cout << cnt << '\n';
	}
	return 0;
}
