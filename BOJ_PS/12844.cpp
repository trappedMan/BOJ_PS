#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> seq;
vector<int> seg_tree;
vector<int> lazy;
int n, m;
void make_seg(int start, int end, int root) {
	if (start == end) {
		seg_tree[root] = seq[start];
		return;
	}
	int mid = (start + end) / 2;
	make_seg(start, mid, root * 2);
	make_seg(mid + 1, end, root * 2 + 1);
	seg_tree[root] = seg_tree[root * 2] ^ seg_tree[root * 2 + 1];
}
int query(int start, int end, int root, int low, int high) {
	if (lazy[root]) {
		if ((end - start + 1) % 2 == 1)
			seg_tree[root] ^= lazy[root];
		if (start != end) {
			lazy[root * 2] ^= lazy[root];
			lazy[root * 2 + 1] ^= lazy[root];
		}
		lazy[root] = 0;
	}
	if (start > high || end < low)
		return 0;
	else if (start >= low && high >= end)
		return seg_tree[root];
	else {
		int mid = (start + end) / 2;
		return query(start, mid, root * 2, low, high) ^ query(mid + 1, end, root * 2 + 1, low, high);
	}
}
void update(int start, int end, int root, int low, int high, int dif) {
	if (lazy[root]) {
		if ((end - start + 1) % 2 == 1)
			seg_tree[root] ^= lazy[root];
		if (start != end) {
			lazy[root * 2] ^= lazy[root];
			lazy[root * 2 + 1] ^= lazy[root];
		}
		lazy[root] = 0;
	}
	if (start > high || end < low)
		return;
	if (start >= low && high >= end) {
		if ((end - start + 1) % 2 == 1)
			seg_tree[root] ^= dif;
		if (start != end) {
			lazy[root * 2] ^=dif;
			lazy[root * 2 + 1] ^= dif;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, root * 2, low, high, dif);
	update(mid + 1, end, root * 2 + 1, low, high, dif);
	seg_tree[root] = seg_tree[root * 2] ^ seg_tree[root * 2 + 1];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int tmp, a, b, c, d;
	cin >> n;
	seg_tree.resize(4 * n);
	lazy.resize(4 * n);
	lazy.assign(4 * n, 0);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		seq.push_back(tmp);
	}
	make_seg(0, n - 1, 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(0, n - 1, 1, b, c, d);
		}
		else {
			cin >> b >> c;
			cout << query(0, n - 1, 1, b, c) << '\n';
		}
	}
	return 0;
}