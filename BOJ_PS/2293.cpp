#include <bits/stdc++.h>
using namespace std;
int n, k, p[101], dp[10001];
void func() {
	for (int i = 1; i <= n;i++) {
		for (int j=p[i]; j<= k; j++) {
			dp[j] = dp[j] + dp[j-p[i]];
		}
	}
	cout << dp[k] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> p[i];
	dp[0] = 1;
	func();
	return 0;
}
