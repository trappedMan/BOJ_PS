#include <bits/stdc++.h>
using namespace std;
int m, n;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> m >> n;
	bool first = false;
	int minprime, cnt = 0;
	for (int i = m; i <= n; i++) {
		if (i == 1)
			continue;
		bool flag = true;
		for (int j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (!first) {
				minprime = i;
				first = true;
			}
			cnt += i;
		}
	}
	if (!first) {
		cout << "-1";
		return 0;
	}
	cout << cnt << '\n' << minprime;
	return 0;
}
