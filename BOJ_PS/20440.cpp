#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans;
pair<int, int> ansp = { 0,0 };
vector<pair<int, int>> v;
vector<int> w;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	//coordination compressing
	for (auto& k : v) {
		w.push_back(k.first);
		w.push_back(k.second);
	}
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	for (auto& k : v) {
		int& f = k.first, & s = k.second;
		f = lower_bound(w.begin(), w.end(), f) - w.begin();
		s = lower_bound(w.begin(), w.end(), s) - w.begin();
	}

	//prefix sum
	vector<int> ans_sum(w.size() + 1);
	for (const auto& k : v) {
		ans_sum[k.first]++; ans_sum[k.second]--;
	}
	for (int i = 1; i < ans_sum.size(); i++)
		ans_sum[i] += ans_sum[i - 1];
	int mx = *max_element(ans_sum.begin(), ans_sum.end());
	cout << mx << '\n';
	int start = max_element(ans_sum.begin(), ans_sum.end()) - ans_sum.begin();
	for (int i = start; i <= ans_sum.size(); i++) {
		if (i == ans_sum.size() || ans_sum[i] != mx) {
			cout << w[start] << ' ' << w[i];
			break;
		}
	}
	return 0;
}
