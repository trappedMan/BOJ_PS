#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll dp[51][51];
ll calc(ll now, ll lparen) {
	ll tmp;
	if (now == n)
		return lparen == 0;
	if (dp[now][lparen] != -1)
		return dp[now][lparen];
	dp[now][lparen] = 0;
	dp[now][lparen] += calc(now + 1, lparen + 1);
	if (lparen > 0) {
		dp[now][lparen] += calc(now + 1, lparen - 1);
	}
	return dp[now][lparen];
}
void print(ll now, ll lparen, ll k) {
	if (now == n) {
		return;
	}
	if (dp[now + 1][lparen + 1] >= k) {
		if (now == n - 1) cout << ')';
		else cout << '(';
		print(now + 1, lparen + 1, k);
	}
	else {
		cout << ')';
		print(now + 1, lparen - 1, k - dp[now + 1][lparen + 1]);
	}
}
int main()
{
	FAST;
	cin >> n >> k;
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			dp[i][j] = -1;
	if (calc(0, 0) <= k)
		cout << "-1";
	else
		print(0, 0, k + 1);
	return 0;
}