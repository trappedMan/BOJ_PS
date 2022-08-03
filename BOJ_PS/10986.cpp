#include <bits/stdc++.h>
using namespace std;
int n, m, tmp;
long long accum, a[1000],ans;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		accum += tmp;
		a[accum % m]++;
	}
	ans += a[0];
	for (int i = 0; i < m; i++) {
		if (a[i] >= 2)
			ans += a[i] * (a[i] - 1) / 2;
	}
	cout << ans;
	return 0;
}