#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
bool a[770][770];
int ru[770][770], rd[770][770];
int main()
{
	FAST;
	string str;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			a[i][j] = str[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			if (a[i][j]) {
				ru[i][j] = ru[i - 1][j + 1] + 1;
			}
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			if (a[i][j]) {
				rd[i][j] = rd[i + 1][j + 1] + 1;
			}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = min(ru[i][j], rd[i][j]); k > 0; k--) {
				if (k == 1) {
					ans = max(ans, 1);
					break;
				}
				if (rd[i - k + 1][j + k - 1] >= k && ru[i + k - 1][j + k - 1] >= k) {
					ans = max(ans, k);
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}