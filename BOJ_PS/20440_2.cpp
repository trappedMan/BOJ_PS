#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans;
pair<int, int> ansp = { 0,0 };
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		while (!pq.empty() && v[i].first >= pq.top().first) {
			pq.pop();
		}
		pq.push({ v[i].second,v[i].first });
		if (ans == pq.size() && v[i].first == ansp.second) {
			ansp.second = pq.top().first;
		}
		else if (ans < pq.size()) {
			ans = pq.size();
			ansp = { v[i].first,pq.top().first };
		}
	}
	cout << ans << '\n' << ansp.first << ' ' << ansp.second;
}
