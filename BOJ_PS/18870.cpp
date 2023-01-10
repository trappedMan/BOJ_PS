#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	vector<int> a(n);
	vector<int> cp(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cp[i] = a[i];
	}
	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());
	for (int i = 0; i < a.size(); i++) {
		cout << lower_bound(cp.begin(), cp.end(), a[i]) - cp.begin() << ' ';
	}
	return 0;
}
