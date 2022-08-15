#include <bits/stdc++.h>
using namespace std;
int t, n, m, tmp, k;
int seg_tree[530000], h[200001], p[100001];
void make_seg(int start, int end, int root) {
	if (start == end) {
		seg_tree[root] = h[start];
		return;
	}
	int mid = (start + end) / 2;
	make_seg(start, mid, root * 2);
	make_seg(mid + 1, end, root * 2 + 1);
	seg_tree[root] = seg_tree[root * 2] + seg_tree[root * 2 + 1];
}
void update(int start, int end, int root, int idx, int dif) {
	if (idx < start || end < idx)
		return;
	seg_tree[root] += dif;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	update(start, mid, root * 2, idx, dif);
	update(mid + 1, end, root * 2 + 1, idx, dif);
}
int query(int start, int end, int root, int low, int high) {
	if (high < start || end < low)
		return 0;
	else if (low <= start && end <= high)
		return seg_tree[root];
	int mid = (start + end) / 2;
	return query(start, mid, root * 2, low, high) + query(mid + 1, end, root * 2 + 1, low, high);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(seg_tree, 0, 530000 * 4);
		for (k = 1; k <= n; k++)
			p[k] = n - k + 1;
		for (k = 1; k <= n; k++)
			h[k] = 1;
		for (; k <= n + m; k++)
			h[k] = 0;
		make_seg(1, n + m, 1);
		for (int i = 1; i <= m; i++) {
			cin >> tmp;
			cout << query(1, n + m, 1, p[tmp] + 1, n + m) << ' ';
			update(1, n + m, 1, p[tmp], -1);
			p[tmp] = n + i;
			update(1, n + m, 1, n + i, 1);
		}
		cout << '\n';
	}
	return 0;
}
