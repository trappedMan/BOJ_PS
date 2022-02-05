//std::lower_bound와 set과 map내의 lower_bound는 O(n)과 O(log n) 으로 차이가 있다.
//random iterator와 bidirectional iterator차이
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k, m, v, c;
    long long val = 0;
    vector<pii> ruby;
    multiset<int, less<int>> knapsack;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> v;
        ruby.push_back({v, m});
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        knapsack.insert(c);
    }
    sort(ruby.begin(), ruby.end(), [](const pii &a, const pii &b)
         { return a > b; });
    for (const auto &iter : ruby)
    {
        if (knapsack.empty())
            break;

        auto itr = knapsack.lower_bound(iter.second);
        if (itr != knapsack.end())
        {
            val += iter.first;
            knapsack.erase(itr);
        }
    }
    cout << val;
    return 0;
}