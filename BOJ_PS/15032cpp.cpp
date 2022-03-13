#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n, k;
double dp[401][401];
double f(int num, int left) {
	if (dp[num][left] != -1.0)
		return dp[num][left];
	if (left == 0) {
		dp[num][left] = (double)num;
		return dp[num][left];
	}
	if (num == n) {
		dp[num][left] = 0.5 * f(num - 1, left - 1) + 0.5 * f(num, left - 1);
	}
	else {
		dp[num][left] = 0.5 * f(num + 1, left - 1) + 0.5 * f(num, left - 1);
	}
	return dp[num][left];
}
int main()
{
	FAST;
	cin >> n >> k;
	for (int i = 0; i <= 400; i++)
		for (int j = 0; j <= 400; j++)
			dp[i][j] = -1.0;
	cout.precision(7);
	cout << f(0, k);
	return 0;
}