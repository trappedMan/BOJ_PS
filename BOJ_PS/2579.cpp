#include <bits/stdc++.h>
using namespace std;
int n, a[301], dp[301], serial[301];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = a[1]; serial[1] = 1;
	dp[2] = dp[1] + a[2]; serial[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + a[i];
		serial[i] = 1;
		if (serial[i - 1] == 1 && dp[i] < dp[i - 1] + a[i]) {
			dp[i] = dp[i - 1] + a[i];
			serial[i] = 2;
		}
		if (serial[i - 1] == 2 && dp[i] < dp[i - 3] + a[i - 1] + a[i]) {
			dp[i] = dp[i - 3] + a[i - 1] + a[i];
			serial[i] = 2;
		}
	}
	cout << dp[n];
	return 0;
}