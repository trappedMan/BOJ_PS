#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1001], n;
ll func(ll n) {
	if (dp[n] != -1)
		return dp[n];
	dp[n] = func(n - 1) % 10007 + func(n - 2) % 10007;
	return dp[n];
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	memset(dp, -1, 1001 * 8);
	dp[0] = 0; dp[1] = 1; dp[2] = 2;
	cout << func(n) % 10007;
	return 0;
}