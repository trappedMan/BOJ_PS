#include <bits/stdc++.h>
using namespace std;
string str1, str2, str3;
int dp[101][101][101];
inline bool equal(char a, char b, char c) { return ((a == b) && (b == c)); }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> str1 >> str2 >> str3;
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			for (int k = 1; k <= str3.size(); k++) {
				if (equal(str1[i - 1], str2[j - 1], str3[k - 1])) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					if (dp[i - 1][j][k] >= dp[i][j - 1][k] && dp[i - 1][j][k] >= dp[i][j][k - 1])
						dp[i][j][k] = dp[i - 1][j][k];
					else if (dp[i][j - 1][k] >= dp[i - 1][j][k] && dp[i][j - 1][k] >= dp[i][j][k - 1])
						dp[i][j][k] = dp[i][j - 1][k];
					else if (dp[i][j][k - 1] >= dp[i - 1][j][k] && dp[i][j][k - 1] >= dp[i][j - 1][k])
						dp[i][j][k] = dp[i][j][k - 1];
				}
			}
		}
	}
	cout << dp[str1.size()][str2.size()][str3.size()];
	return 0;
}