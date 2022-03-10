#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt = 0, ans = 0;
bool table[50][50];
vector<int> elem;
int maxval[50];
int main()
{
	FAST;
	string str;
	cin >> n >> m;
	for (int i = 0; i < 50; i++)
		maxval[i] = 1;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			table[i][j] = str[j] - '0';
		}
	}
	cin >> k;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < m; j++) {
			if (!table[i][j])
				++cnt;
		}
		if (cnt == k || (cnt < k && !((k - cnt) & 1))) {
			elem.push_back(i);
		}
	}
	for (int i = 0; i < elem.size(); i++) {
		for (int j = i + 1; j < elem.size(); j++) {
			bool flag = true;
			for (int k = 0; k < m; k++) {
				if (table[elem[i]][k] != table[elem[j]][k]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				maxval[elem[i]]++;
				maxval[elem[j]]++;
			}
		}
	}
	if (elem.empty()) {
		cout << '0';
		return 0;
	}
	for (const auto& iter : maxval) {
		ans = max(ans, iter);
	}
	cout << ans;
	return 0;
}