#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int n, m, k;
vector<ll> a;
vector<ll> segtree;
void make_tree(int start, int end, int root) {
	if (start == end) {
		segtree[root] = a[start];
		return;
	}
	int mid = (start + end) / 2;
	make_tree(start, mid, root * 2);
	make_tree(mid + 1, end, root * 2 + 1);
	segtree[root] = (segtree[root * 2] * segtree[root * 2 + 1]) % mod;
}
void update(int start, int end, int root, int index,int val) {
	if (index < start || end < index)
		return;
	if (start == end) {
		segtree[root] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, root * 2, index, val);
	update(mid + 1, end, root * 2 + 1, index, val);
	segtree[root] = (segtree[root * 2] * segtree[root * 2 + 1]) % mod;
}
ll search(int start, int end, int root, int low, int high) {
	if (high < start || end < low)
		return 1;
	else if (low <= start && end <= high)
		return segtree[root];
	else {
		int mid = (start + end) / 2;
		return (search(start, mid, root * 2, low, high) * search(mid + 1, end, root * 2 + 1, low, high)) % mod;
	}
}
int main()
{
	FAST;
	int o1, o2, o3;
	cin >> n >> m >> k;
	a.resize(n); segtree.resize(4 * n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	make_tree(0, n - 1, 1);
	for (int i = 0; i < m + k; i++) {
		cin >> o1 >> o2 >> o3;
		if (o1 == 1) {
			update(0, n - 1, 1, o2-1, o3);
		}
		else {
			cout << search(0, n - 1, 1, o2-1, o3-1)<<'\n';
		}
	}
	return 0;
}