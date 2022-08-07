#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int n, a[500001], seq[500001], seg_tree[1100000];
unordered_map<int, int> b;
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
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
        a[i] = seq[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
        b.insert({ a[i],i });
    for (int i = 1; i <= n; i++)
        seq[i] = b.find(seq[i])->second;
    for (int i = 1; i <= n; i++) {
        cout <<i-sum(1, n, 1, 1, seq[i] - 1) << '\n';
        update(1, n, 1, seq[i], 1);
    }
	return 0;
}
