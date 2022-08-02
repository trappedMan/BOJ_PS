#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, tmp;
vector<int> a, b;
ll ans = 0;
int seg_tree[1100000];
void update(int start, int end, int root, int index, ll dif)
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
int sum(int start, int end, int root, int low, int high)
{
    if (high < start || end < low)
        return 0;
    if (low <= start && end <= high)
        return seg_tree[root];
    int mid = (start + end) / 2;
    return sum(start, mid, root * 2, low, high) + sum(mid + 1, end, root * 2 + 1, low, high);
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
    a.resize(1000000); b.resize(n);
    for (int j = 0; j < n; j++) {
        cin >> tmp;
        a[tmp] = j;
    }
    for (int j = 0; j < n; j++) {
        cin >> tmp;
        b[j] = a[tmp];
    }
    for (int i = 0; i < n; i++) {
        int now = b[i];
        update(0, n - 1, 1, now, 1);
        ans += sum(0, n - 1, 1, now + 1, n - 1);
    }
    cout << ans;
	return 0;
}