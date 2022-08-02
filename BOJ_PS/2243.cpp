#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int seg_tree[2000001];
void update(int start, int end, int root, int index, int dif)
{
    if (index < start || end < index)
        return;
    seg_tree[root] += dif;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(start, mid, root * 2, index, dif);
    update(mid + 1, end, root * 2 + 1, index, dif);
}
int query(int start, int end, int root, int order){
    if (start == end)
        return start;
    if (seg_tree[2 * root] >= order)
        return query(start, (start + end) / 2, root * 2, order);
    else
        return query((start + end) / 2 + 1, end, root * 2 + 1, order - seg_tree[2 * root]);
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
            int idx=query(1, 1000000, 1, b);
            update(1, 1000000, 1, idx, -1);
            cout << idx << '\n';
		}
		else {
			cin >> b >> c;
            update(1, 1000000, 1, b, c);
		}
	}
	return 0;
}