//세그먼트 트리 배열의 크기는 4*n으로 잡는게 안전하다
//또는 트리의 depth는 (int)ceil(log2(n))고, 그 트리 배열의 크기는 pow(2,depth+1)로 잡자
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int n, m, k, t_size;
vector<ll> seg_tree;
vector<ll> seq;
void make_seg(int start, int end, int root)
{
    if (start == end)
    {
        seg_tree[root] = seq[start];
        return;
    }
    int mid = (start + end) / 2;
    make_seg(start, mid, root * 2);
    make_seg(mid + 1, end, root * 2 + 1);
    seg_tree[root] = seg_tree[root * 2] + seg_tree[root * 2 + 1];
}
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
ll sum(int start, int end, int root, int low, int high)
{
    if (high < start || end < low)
        return 0;
    if (low <= start && end <= high)
        return seg_tree[root];
    int mid = (start + end) / 2;
    return sum(start, mid, root * 2, low, high) + sum(mid + 1, end, root * 2 + 1, low, high);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll tmp, com, o1, o2;
    cin >> n >> m >> k;
    t_size = 4 * n;
    seg_tree.assign(t_size, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        seq.push_back(tmp);
    }
    make_seg(0, n - 1, 1);
    for (int i = 0; i < m + k; i++)
    {
        cin >> com >> o1 >> o2;
        if (com == 1)
        {
            ll temp = o2 - seq[o1 - 1];
            seq[o1 - 1] = o2;
            update(0, n - 1, 1, o1 - 1, temp);
        }
        if (com == 2)
        {
            cout << sum(0, n - 1, 1, o1 - 1, o2 - 1) << '\n';
        }
    }
    return 0;
}