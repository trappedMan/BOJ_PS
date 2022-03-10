/*#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 0;
int n;
vector<pair<int,int>> a;
vector<ll> segtree;
void update(int start, int end, int root, int index) {
	if (index < start || end < index)
		return;
	if (start == end) {
		++segtree[root];
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, root * 2, index);
	update(mid + 1, end, root * 2 + 1, index);
	segtree[root] = segtree[root * 2] + segtree[root * 2 + 1];
}
ll query(int start, int end, int root, int low, int high) {
	if (high < start || end < low)
		return 0;
	else if (low <= start && end <= high)
		return segtree[root];
	else {
		int mid = (start + end) / 2;
		return query(start, mid, root * 2, low, high) + query(mid + 1, end, root * 2 + 1, low, high);
	}
}
int main()
{
	FAST;
	cin >> n;
	a.resize(n); segtree.resize(4 * n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		ans += query(0, n - 1, 1, a[i].second + 1, n - 1);
		update(0, n - 1, 1, a[i].second);
	}
	cout << ans;
	return 0;
}*/