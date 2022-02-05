#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k, m, v, c;
    long long val = 0;
    vector<pii> ruby;
    vector<int> knapsack;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> v;
        ruby.push_back({m, v});
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        knapsack.push_back(c);
    }
    sort(ruby.begin(), ruby.end(), [](const pii &a, const pii &b)
         { return a < b; });
    sort(knapsack.begin(), knapsack.end());
    priority_queue<int> nice;
    int curruby = 0, curbag = 0;
    while (curbag < k)
    {
        while (curruby < n && ruby[curruby].first <= knapsack[curbag])
            nice.push(ruby[curruby++].second);
        if (nice.empty())
        {
            curbag++;
            continue;
        }
        val += nice.top();
        nice.pop();
        curbag++;
    }
    cout << val;
    return 0;
}