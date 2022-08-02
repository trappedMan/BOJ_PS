#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m, t_size;
vector<vector<int>> seg_tree;
vector<int> seq;
void make_seg(int start, int end, int root)
{
    if (start == end)
    {
        seg_tree[root].push_back(seq[start]);
        return;
    }
    int mid = (start + end) / 2;
    make_seg(start, mid, root * 2);
    make_seg(mid + 1, end, root * 2 + 1);
    auto i1 = seg_tree[root * 2].begin();
    auto i2 = seg_tree[root * 2 + 1].begin();
    const auto& end1 = seg_tree[root * 2].end();
    const auto& end2 = seg_tree[root * 2 + 1].end();
    while (i1 != end1 && i2 != end2) {
        if (*i1 <= *i2) {
            seg_tree[root].push_back(*i1);
            i1++;
        }
        else {
            seg_tree[root].push_back(*i2);
            i2++;
        }
    }
    while (i1 != end1) {
        seg_tree[root].push_back(*i1);
        i1++;
    }
    while (i2 != end2) {
        seg_tree[root].push_back(*i2);
        i2++;
    }
}
int ans(int start, int end, int root, int low, int high, int boundary)
{
    if (high < start || end < low)
        return 0;
    if (low <= start && end <= high) {
        int tmp = seg_tree[root].end() - lower_bound(seg_tree[root].begin(), seg_tree[root].end(), boundary + 1);
        return (tmp > 0 ? tmp : 0);
    }
    int mid = (start + end) / 2;
    return ans(start, mid, root * 2, low, high, boundary) + ans(mid + 1, end, root * 2 + 1, low, high, boundary);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int tmp, o1, o2, o3, prev;
    cin >> n;
    t_size = 4 * n;
    seg_tree.resize(t_size);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        seq.push_back(tmp);
    }
    make_seg(0, n - 1, 1);
    cin >> m;
    cin >> o1 >> o2 >> o3;
    prev = ans(0, n - 1, 1, o1 - 1, o2 - 1, o3);
    cout << prev << '\n';
    for (int i = 1; i < m; i++) {
        cin >> o1 >> o2 >> o3;
        prev = ans(0, n - 1, 1, (o1 ^ prev) -1 , (o2 ^ prev) -1 , (o3) ^ prev);
        cout << prev << '\n';
    }
    return 0;
}