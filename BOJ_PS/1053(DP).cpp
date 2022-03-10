#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
string str;
const int inf = 1e9;
int dp[52][52];
int func(int start, int end) {
	if (dp[start][end]!=inf) return dp[start][end];
	if (start >= end) {
		return 0;
	}
	if (str[start] == str[end]) {
		dp[start][end] = func(start + 1, end - 1);
		return dp[start][end];
	}
	else {
		dp[start][end] = min({ func(start + 1, end) + 1 ,func(start, end - 1) + 1,func(start + 1, end - 1) + 1 });
		return dp[start][end];
	}
}
int main()
{
	FAST;
	cin >> str;
	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
			dp[i][j] = inf;
	int ans = func(0, str.size() - 1);
	for (int I = 0; I < str.size(); I++) {
		for (int J = I + 1; J < str.size(); J++) {
			swap(str[I], str[J]);
			for (int i = 0; i < 52; i++)
				for (int j = 0; j < 52; j++)
					dp[i][j] = inf;
			ans = min(ans, func(0, str.size() - 1) + 1);
			swap(str[I], str[J]);
		}
	}
	cout << ans;
	return 0;
}