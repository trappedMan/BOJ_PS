//정렬된 자료구조에서 같은 원소의 개수를 셀 때는 그냥 upper_bound-lower_bound가 젤 빠르다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A[4000], B[4000], C[4000], D[4000];
vector<int> AA, BB;
int bin_search(int val, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (BB[mid] == val)
        return mid;
    else if (BB[mid] > val)
        return bin_search(val, start, mid - 1);
    else
        return bin_search(val, mid + 1, end);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            AA.push_back(A[i] + B[j]);
            BB.push_back(C[i] + D[j]);
        }
    }
    sort(BB.begin(), BB.end());
    long long ans = 0;
    for (const auto &iter : AA)
    {
        int pos = bin_search(-iter, 0, n * n - 1);
        if (pos != -1)
        {
            long long dif = upper_bound(BB.begin(), BB.end(), -iter) - lower_bound(BB.begin(), BB.end(), -iter);
            ans += dif;
        }
    }
    cout << ans;
    return 0;
}