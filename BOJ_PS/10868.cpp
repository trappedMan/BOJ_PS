//구간 내의 최소값, 최대값을 탐색하는 데 사용한 세그먼트 트리
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
vector<ll> seq, mintree;
int n, m;
void make_tree(int start, int end, int root)
{

    if (start == end)
    {
        mintree[root] = seq[start];
        return;
    }
    int mid = (start + end) / 2;
    make_tree(start, mid, root * 2);
    make_tree(mid + 1, end, root * 2 + 1);
    mintree[root] = min(mintree[root * 2], mintree[root * 2 + 1]);
}
ll min_find(int start, int end, int root, int low, int high)
{
    if (high < start || end < low)
        return INF;
    if (low <= start && end <= high)
        return mintree[root];
    int mid = (start + end) / 2;
    return min(min_find(start, mid, root * 2, low, high), min_find(mid + 1, end, root * 2 + 1, low, high));
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    int o1, o2;
    int t_size = (int)ceil(log2(n));
    t_size = pow(2, t_size + 1);
    seq.resize(n), mintree.resize(t_size);
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    make_tree(0, n - 1, 1);
    for (int i = 0; i < m; i++)
    {
        cin >> o1 >> o2;
        cout << min_find(0, n - 1, 1, o1 - 1, o2 - 1) << '\n';
    }
    return 0;
}