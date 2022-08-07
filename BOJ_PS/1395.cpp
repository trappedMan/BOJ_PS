#include <bits/stdc++.h>
using namespace std;
int seg_tree[400010], lazy[400010];
int n, m, a, b, c;
void propagate(int root, int n) {
	if (lazy[root]%2==1) {
		seg_tree[root] = n - seg_tree[root];
		if (n>1) {
			lazy[root * 2]++;
			lazy[root * 2 + 1]++;
		}
		lazy[root] = 0;
	}
}
int sum(int start, int end, int root, int low, int high) {
	propagate(root, end - start + 1);
	if (start > high || end < low)
		return 0;
	else if (start >= low && high >= end)
		return seg_tree[root];
	else {
		int mid = (start + end) / 2;
		return sum(start, mid, root * 2, low, high) + sum(mid + 1, end, root * 2 + 1, low, high);
	}
}
void update(int start, int end, int root, int low, int high) {
	propagate(root, end - start + 1);
	if (start > high || end < low)
		return;
	if (start >= low && high >= end) {
		seg_tree[root] = (end-start+1) - seg_tree[root];
		if (start != end) {
			lazy[root * 2] ++;
			lazy[root * 2 + 1] ++;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, root * 2, low, high);
	update(mid + 1, end, root * 2 + 1, low, high);
	seg_tree[root] = seg_tree[root * 2] + seg_tree[root * 2 + 1];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 0)
			update(0, n - 1, 1, b - 1, c - 1);
		else {
			cout << sum(0, n - 1, 1, b - 1, c - 1) << '\n';
		}
	}
	return 0;
}