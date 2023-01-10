#include <bits/stdc++.h>
using namespace std;
int n, c, a[200001];
int func(int mid) {
	int cur = 0;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[cur] >= mid) {
			cur = i;
			cnt++;
		}
	}
	return cnt;
}
int bin_search(int val) {
	int start = 0, end = 1000000000, cnt, mid;
	int ans = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		cnt = func(mid);
		if (cnt >= val) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	cout << bin_search(c);
	return 0;
}
