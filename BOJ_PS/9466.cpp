#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
int stu[100001], group[100001];
bool cycle[100001];
void solve() {
	for (int i = 1; i <= n; i++) {
		stu[i] = group[i] = cycle[i] = 0;
	}
	ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stu[i];
		group[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (group[i] == i) {
			if (i == stu[i]) {
				cycle[i] = true;
				group[i] = -1;
			}
			else {
				int j = i;
				while (group[stu[j]] == stu[j]) {
					group[stu[j]] = group[j];
					j = stu[j];
				}
				if (group[stu[j]] == group[j]) {
					cycle[j] = true;
					for (int k = stu[j]; k != j; k = stu[k]) {
						cycle[k] = true;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!cycle[i])
			ans++;
	}
	cout << ans << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}