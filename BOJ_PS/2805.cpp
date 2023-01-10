#include <bits/stdc++.h>
using namespace std;
int n, m, mx;
vector<int> a;
long long func(long long height) {
	long long len = 0;
	for (int i = 0; i < n; i++) {
		len += a[i] - height >= 0 ? a[i] - height : 0;
	}
	return len;
}
int bin_search(int val) {
	long long start = 0, end = mx-1;
	while (start<end) {
		//cout << "Start: " << start << "end: " << end << '\n';
		long long mid = (start + end) / 2;
		long long ret = func(mid);
		if (ret == val)
			return mid;
		else if (ret > val) {
			start = mid + 1;
			if (func(mid + 1) < val)
				return mid;
		}
		else {
			end = mid - 1;
		}
	}
	return start;
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	mx = *max_element(a.begin(), a.end());
	cout << bin_search(m);
	return 0;
}
