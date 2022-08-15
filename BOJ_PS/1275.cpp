#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, tmp;
ll seg[280000], aa[100001], mins[280000];
ll maxv;
void make_seg(int start, int end, int root) {
	if (start == end) {
		seg[root] = aa[start];
		return;
	}
	int mid = (start + end) / 2;
	make_seg(start, mid, root * 2);
	make_seg(mid + 1, end, root * 2 + 1);
	seg[root] = seg[root * 2] + seg[root * 2 + 1];
}
void make_mins(int start, int end, int root) {
	if (start == end) {
		mins[root] = aa[start];
		return;
	}
	int mid = (start + end) / 2;
	make_mins(start, mid, root * 2);
	make_mins(mid + 1, end, root * 2 + 1);
	mins[root] = min(mins[root * 2], mins[root * 2 + 1]);
}
int query(int start, int end, int root, int low, int high) {
	int result = max(seg[root * 2] * mins[root * 2], seg[root * 2 + 1] * mins[root * 2 + 1]);

}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> aa[i];
	make_seg(0, n - 1, 1);
	make_mins(0, n - 1, 1);
	cout << query(0, n - 1, 1, 0, n - 1);
	return 0;
}
